#include "./InterMediate.h"
#include <typeinfo>
#include <cstdio>
IM::InterMediate::InterMediate(AST::BaseNode *rootNode, SMB::StructTable *structTable) {
    temp_vars.reserve(100);
    this->root = rootNode;
    this->symbol_table = new SMB::SymbolTable(false, structTable);
}

void IM::InterMediate::generate(AST::BaseNode *node, SMB::SymbolTable *symbolTable)
{
    if (node == NULL) {
        std::cout << "NULL" << std::endl;
        return;
    }
    AST::BaseNode *p = node->getChildNode();
    switch (node->getASTNodeType()) {
    case AST::def_func: {
        SMB::FuncSymbol *func = new SMB::FuncSymbol(node);
        this->symbol_table->addFuncSymbol(func);
        Quaternion *temp;
        SMB::Symbol *temp_symbol = new SMB::Symbol(func->getDecName(), SMB::void_type);
        temp = new Quaternion(IM::FUNC_DEF, temp_symbol, (SMB::Symbol *)NULL);
        this->quads.push_back(*temp);
        while (p != NULL) {
            SMB::SymbolTable *childTable = symbolTable->createChildTable(true);
            childTable->setTableName(func->getDecName());
            childTable->addFromFunctionArgs(func);
            generate(p, childTable);
            p = p->getCousinNode();
        }
        temp = new Quaternion(IM::END_FUNCTION, (SMB::Symbol *)NULL, (SMB::Symbol *)NULL);
        this->quads.push_back(*temp);
        break;
    }
    case AST::call_func: {
        int count = 0;
        AST::BaseNode *var = ((AST::CallFuncNode*)node)->getVarList();
        std::string add_on = "";
        while (var != NULL) {
            count = count + 1;
            Quaternion *temp;
            if (var->getASTNodeType() == AST::assign_var) {
                SMB::Symbol *arg1 = symbolTable->findSymbol(var->getContent());
                temp = new Quaternion(IM::PARAM, arg1, (SMB::Symbol *)NULL);
                switch (arg1->getType()) {
                case SMB::integer:
                    add_on = add_on + "-i";
                    break;
                case SMB::pointer:
                    add_on = add_on + "-p";
                    break;
                default:
                    break;
                }
            }
            else if (var->getASTNodeType() == AST::literal) {
                int arg1 = std::stoi(var->getContent());
                temp = new Quaternion(IM::PARAM, arg1, (SMB::Symbol*)NULL);
                add_on = add_on + "-i";
            }
            else if (var->getASTNodeType() == AST::op) {
                SMB::Symbol *arg1 = generateOperator((AST::OperatorNode*)var, symbolTable);
                temp = new Quaternion(IM::PARAM, arg1, (SMB::Symbol*)NULL);
                switch (arg1->getType())
                {
                case SMB::integer:
                    add_on = add_on + "-i";
                    break;
                case SMB::pointer:
                    add_on = add_on + "-p";
                    break;
                default:
                    break;
                }
            }
            this->quads.push_back(*temp);
            var = var->getCousinNode();
        }
        SMB::FuncSymbol *funSym = (SMB::FuncSymbol*)this->symbol_table->findSymbol(node->getContent() + add_on);
        if (funSym == NULL) {
            std::cout << "\033[31mError: \033[0m"
                      << " function is not decleared." << std::endl;
            exit(1);
        }
        SMB::Symbol *funcSymbol = new SMB::Symbol(funSym->getDecName(), SMB::void_type);
        // SMB::Symbol *funcSymbol = new SMB::Symbol(funSym->getFunName(), SMB::void_type);
        SMB::Symbol *tempV = NULL;

        if (node->getParentNode()->getASTNodeType() == AST::stmt) {
            AST::StatementNode *stmt = (AST::StatementNode *)node->getParentNode();
            if (stmt->getStmtType() == AST::expression) {
                tempV = NULL;
            }
            else {
                tempV = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
                temp_vars.push_back(tempV);
            }
        }
        else {
            tempV = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
            temp_vars.push_back(tempV);
        }

        Quaternion *temp = new Quaternion(IM::CALL, funcSymbol, count, tempV);
        this->quads.push_back(*temp);
    }
    case AST::literal: {
        if (node->getParentNode()->getASTNodeType() == AST::op) {
            AST::OperatorNode *par = (AST::OperatorNode *)node->getParentNode();
            if (par->getOpType() == AST::and_op 
             || par->getOpType() == AST::or_op 
             || par->getOpType() == AST::not_op) 
            {
                Quaternion *true_quad = new Quaternion(IM::JUMP_GREAT, std::stoi(node->getContent()), 0, (int)NULL);
                Quaternion *false_quad = new Quaternion(IM::JUMP, (int)NULL);
                std::list<int> true_l;
                true_l.push_back(quads.size());
                this->quads.push_back(*true_quad);
                std::list<int> false_l;
                false_l.push_back(quads.size());
                this->quads.push_back(*false_quad);
                true_list.push(true_l);
                false_list.push(false_l);
            }
        }
        break;
    }
    case AST::op:
    {
        if (((AST::OperatorNode*)node)->getOpType() == AST::and_op 
        || ((AST::OperatorNode *)node)->getOpType() == AST::or_op)
        {
            generate(p, symbolTable);
            signal.push(quads.size());
            generate(p->getCousinNode(), symbolTable);
        }
        else if (((AST::OperatorNode*)node)->getOpType() == AST::not_op 
             || ((AST::OperatorNode *)node)->getOpType() == AST::relop)
        {
            while (p != NULL) {
                generate(p, symbolTable);
                p = p->getCousinNode();
            }
        }
        this->generateOperator((AST::OperatorNode *)node, symbolTable);
        break;
    }
    case AST::stmt:
    {
        AST::StatementNode *ret = (AST::StatementNode *)node;
        if (ret->getStmtType() == AST::return_stmt)
        {
            generateReturn((AST::StatementNode *)node, symbolTable);
        }
        else
        {
            while (p != NULL)
            {
                generate(p, this->generateStatement((AST::StatementNode *)node, symbolTable));
                p = p->getCousinNode();
            }
        }
        break;
    }
    case AST::def_var: {
        AST::DefineVarNode *tempNode = (AST::DefineVarNode*)node;
        if (tempNode->getSymbolType() == SMB::struct_type) {
            // TODO: addStructSymbol
            symbolTable->addStructSymbol(tempNode->getStructName(), tempNode->getContent());
        }
        else if (tempNode->getSymbolType() == SMB::array) {
            symbolTable->addArraySymbol(tempNode);
        }
        else {
            if(symbolTable->addSymbol(node) == 0){
                std::cout << "\033[31mError: \033[0m"
                << "value " << node->getContent() << " is redeclaration" << std::endl;
                exit(1);
            }
        }
        SMB::Symbol *varSymbol = symbolTable->findSymbol(node->getContent());
        if (p != NULL) {
            Quaternion *temp;
            if (p->getASTNodeType() == AST::literal) {
                int arg1 = std::stoi(p->getContent());
                temp = new Quaternion(IM::ASSIGN, arg1, varSymbol);
            }
            else if (p->getASTNodeType() == AST::assign_var) {
                SMB::Symbol *arg1 = symbolTable->findSymbol(p->getContent());
                temp = new Quaternion(IM::ASSIGN, arg1, varSymbol);
            }
            else if (p->getASTNodeType() == AST::op) {
                SMB::Symbol *arg1 = this->generateOperator((AST::OperatorNode *)p, symbolTable);
                temp = new Quaternion(IM::ASSIGN, arg1, varSymbol);
            }
            else if (p->getASTNodeType() == AST::call_func) {
                generate(p, symbolTable);
                SMB::Symbol *arg1 = temp_vars.back();
                temp = new Quaternion(IM::ASSIGN, arg1, varSymbol);
            }
            else {
                std::cout << "\033[31mError: \033[0m"
                          << "Type error" << std::endl;
                exit(1);
            }
            this->quads.push_back(*temp);
        }
        break;
    }
    case AST::assign_var:
    {
        if (node->getParentNode()->getASTNodeType() == AST::op) {
            AST::OperatorNode *par = (AST::OperatorNode *)node->getParentNode();
            if (par->getOpType() == AST::and_op 
             || par->getOpType() == AST::or_op 
            || par->getOpType() == AST::not_op)
            {
                SMB::Symbol *arg1 = symbolTable->findSymbol(node->getContent());
                Quaternion *trueQuad = new Quaternion(IM::JUMP_GREAT, arg1, 0, (int)NULL);
                Quaternion *falseQuad = new Quaternion(IM::JUMP, (int)NULL);
                std::list<int> trueL;
                trueL.push_back(quads.size());
                this->quads.push_back(*trueQuad);
                std::list<int> falseL;
                falseL.push_back(quads.size());
                this->quads.push_back(*falseQuad);
                true_list.push(trueL);
                false_list.push(falseL);
            }
        }
        break;
    }
    case AST::loop: // for(1.DefASTNODE, 2.OperatorASTNODE, 3.OperatorASTNODE, 4.StmtASTNODE)
    {
        AST::LoopNode *loop = (AST::LoopNode*)node;
        if (loop->getLoopType() == AST::for_loop)
        {
            SMB::SymbolTable *childTable = symbolTable->createChildTable(false);
            childTable->setTableName("for");
            generate(((AST::LoopNode*)node)->getDecNode(), childTable);
            int start = quads.size();
            generate(((AST::LoopNode*)node)->getCondNode(), childTable);
            std::list<int> JudgeTrue = true_list.top();
            std::list<int> JudgeFalse = false_list.top();
            true_list.pop();
            false_list.pop();
            backpatch(&JudgeTrue, JudgeTrue.back() + 2);
            while (p != NULL)
            {
                generate(p, childTable);
                p = p->getCousinNode();
            }
            generate(((AST::LoopNode*)node)->getActionNode(), childTable);

            Quaternion *temp = new Quaternion(IM::JUMP, start);
            this->quads.push_back(*temp);
            int end = quads.size();
            backpatch(&JudgeFalse, end);
        }
        else if (loop->getLoopType() == AST::while_loop)
        {
            int start = quads.size();
            generate(((AST::LoopNode*)node)->getCondNode(), symbolTable);
            std::list<int> JudgeTrue = true_list.top();
            std::list<int> JudgeFalse = false_list.top();
            true_list.pop();
            false_list.pop();
            backpatch(&JudgeTrue, JudgeTrue.back() + 2);
            while (p != NULL) {
                SMB::SymbolTable *childTable = symbolTable->createChildTable(false);
                childTable->setTableName("while");
                generate(p, childTable);
                p = p->getCousinNode();
            }

            Quaternion *temp = new Quaternion(IM::JUMP, start);
            this->quads.push_back(*temp);
            int end = quads.size();
            backpatch(&JudgeFalse, end);
        }
        break;
    }
    case AST::select: // Just IF and ELSE.
    {
        AST::SelectNode *select = (AST::SelectNode*)node;
        generate(select->getCondNode(), symbolTable);
        // std::cout << "generate finished!\n";
        int start = quads.size();
        std::list<int> JudgeTrue = true_list.top();
        std::list<int> JudgeFalse = false_list.top();
        true_list.pop();
        false_list.pop();

        backpatch(&JudgeTrue, start);
        // Body:
        // std::cout << "body: " << select->getBodyNode() << "\n";
        generate(select->getBodyNode(), symbolTable);
        if (select->getElse() != NULL) {
            // std::cout << "else if\n";
            Quaternion *temp = new Quaternion(IM::JUMP, (int)NULL);
            this->quads.push_back(*temp);
            temp = &quads.back();
            int elseStart = quads.size();
            generate(select->getElse(), symbolTable);
            // std::cout << "generate finished\n";
            backpatch(&JudgeFalse, elseStart);
            int end = quads.size();
            temp->backpatch(end);
        } else {
            int end = quads.size();
            backpatch(&JudgeFalse, end);
        }
        break;
    }
    case AST::root: {
        while (p != NULL) {
            generate(p, symbolTable);
            p = p->getCousinNode();
        }
        break;
    }
    default:
        std::cout << "Hello! Something Wrong happened!\n";
        break;
    }
}

SMB::SymbolTable *IM::InterMediate::generateStatement(AST::StatementNode *node, SMB::SymbolTable *symbolTable) {
    switch (node->getStmtType()) {
    case AST::comparation: {
        if (node->getParentNode()->getASTNodeType() == AST::loop)
            return symbolTable;
        if (node->getParentNode()->getASTNodeType() == AST::def_func)
            return symbolTable;
        SMB::SymbolTable *childTable = symbolTable->createChildTable(false);
        childTable->setTableName("comparation");
        return childTable;
    }
    break;
    default:
        break;
    }
    return symbolTable;
}

SMB::SymbolTable *IM::InterMediate::generateReturn(AST::StatementNode *node, SMB::SymbolTable *symbolTable)
{
    AST::BaseNode *p = node->getChildNode();
    Quaternion *temp;
    SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
    temp_vars.push_back(result);
    if (p == NULL) {
        temp = new Quaternion(IM::RETURN, (SMB::Symbol *)NULL, (SMB::Symbol *)NULL, (SMB::Symbol *)NULL);
    }
    else if (p->getASTNodeType() == AST::literal) {
        int arg1 = std::stoi(p->getContent());
        temp = new Quaternion(IM::RETURN, arg1, result);
    }
    else if (p->getASTNodeType() == AST::assign_var) {
        SMB::Symbol *arg1 = symbolTable->findSymbol(p->getContent());
        temp = new Quaternion(IM::RETURN, arg1, result);
    }
    else if (p->getASTNodeType() == AST::op) {
        SMB::Symbol *arg1 = this->generateOperator((AST::OperatorNode *)p, symbolTable);
        temp = new Quaternion(IM::RETURN, arg1, result);
    }
    else if (p->getASTNodeType() == AST::call_func) {
        generate(p, symbolTable);
        SMB::Symbol *arg1 = temp_vars.back();
        temp = new Quaternion(IM::RETURN, arg1, (SMB::Symbol *)NULL);
    }
    else {
        std::cout << "\033[31mError: \033[0m"
                  << "Type error" << std::endl;
        exit(1);
    }
    quads.push_back(*temp);
}

SMB::Symbol *IM::InterMediate::generateOperator(AST::OperatorNode *node, SMB::SymbolTable *symbolTable)
{
    std::cout << "op begin\n";
    Quaternion *temp;
    AST::BaseNode *arg1Node, *arg2Node;
    switch (node->getOpType()) {
    case AST::assign: {
        SMB::Symbol *result;
        IM::OperatorCode op;
        if (node->getChildNode()->getASTNodeType() == AST::op 
        && ((AST::OperatorNode *)node->getChildNode())->getOpType() == AST::get_var)
        {
            op = IM::ASSIGN_POINTER;
            result = symbolTable->findSymbol(node->getChildNode()->getChildNode()->getContent());
        }
        else {
            op = IM::ASSIGN;
            if (node->getChildNode()->getASTNodeType() != AST::assign_var
            &&  node->getChildNode()->getASTNodeType() != AST::def_var) {
                std::cout << "\033[31mError: \033[0m"
                          << node->getChildNode()->getContent() << " is not a variable. What are u doing?" << std::endl;
                exit(1);
            } else if (node->getChildNode()->getASTNodeType() == AST::def_var) {
                if(symbolTable->addSymbol(node->getChildNode()) == 0){
                    std::cout << "\033[31mError: \033[0m"
                    << "value " << node->getContent() << " is redeclaration" << std::endl;
                    exit(1);
                }
            }
            result = symbolTable->findSymbol(node->getChildNode()->getContent());
        }

        AST::BaseNode *arg1Node = node->getChildNode()->getCousinNode();
        if (arg1Node->getASTNodeType() == AST::assign_var) {
            SMB::Symbol *arg1 = symbolTable->findSymbol(arg1Node->getContent());
            if (result->getType() == SMB::integer && arg1->getType() == SMB::pointer) {
                std::cout << "\033[31mError: \033[0m"
                          << "Syntax error, maybe you have used the wrong type: " << (int)arg1Node->getASTNodeType() << "  Content:" << arg1Node->getContent() << std::endl;
                exit(1);
            }
            temp = new Quaternion(op, arg1, result);
        }
        else if (arg1Node->getASTNodeType() == AST::op) {
            SMB::Symbol *arg1 = generateOperator((AST::OperatorNode *)arg1Node, symbolTable);
            temp = new Quaternion(op, arg1, result);
        }
        else if (arg1Node->getASTNodeType() == AST::literal) {
            int arg1 = std::stoi(arg1Node->getContent());
            temp = new Quaternion(op, arg1, result);
        }
        else if (arg1Node->getASTNodeType() == AST::call_func) {
            generate(arg1Node, symbolTable);
            SMB::Symbol *arg1 = temp_vars.back();
            temp = new Quaternion(op, arg1, result);
        }
        else {
            std::cout << "\033[31mError: \033[0m"
                      << "No match type of" << (int)arg1Node->getASTNodeType() << "  Content:" << arg1Node->getContent() << std::endl;
            exit(1);
        }
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case AST::assign_arr: {
        SMB::Symbol *result;
        if (node->getChildNode()->getASTNodeType() != AST::op) {
            std::cout << "\033[31mError: \033[0m"
                      << node->getContent() << " syntax error. What are u doing?" << std::endl;
        }
        result = generateOperator((AST::OperatorNode *)node->getChildNode(), symbolTable);
        AST::BaseNode *arg1Node = node->getChildNode()->getCousinNode();
        SMB::Symbol *arg2 = this->childValue.top();
        this->childValue.pop();
        if (arg1Node->getASTNodeType() == AST::assign_var) {
            SMB::Symbol *arg1 = symbolTable->findSymbol(arg1Node->getContent());
            temp = new Quaternion(IM::ASSIGN_ARRAY, arg1, arg2, result);
        }
        else if (arg1Node->getASTNodeType() == AST::op) {
            SMB::Symbol *arg1 = generateOperator((AST::OperatorNode *)arg1Node, symbolTable);
            temp = new Quaternion(IM::ASSIGN_ARRAY, arg1, arg2, result);
        }
        else if (arg1Node->getASTNodeType() == AST::literal) {
            int arg1 = std::stoi(arg1Node->getContent());
            temp = new Quaternion(IM::ASSIGN_ARRAY, arg1, arg2, result);
        }
        else if (arg1Node->getASTNodeType() == AST::call_func) {
            generate(arg1Node, symbolTable);
            SMB::Symbol *arg1 = temp_vars.back();
            temp = new Quaternion(IM::ASSIGN_ARRAY, arg1, arg2, result);
        }
        else {
            std::cout << "\033[31mError: \033[0m"
                      << "No match type of" << (int)arg1Node->getASTNodeType() << "  Content:" << arg1Node->getContent() << std::endl;
            exit(1);
        }
        this->quads.push_back(*temp);

        return result;
        break;
    }
    case AST::assign_member: {
        SMB::Symbol *result;
        if (node->getChildNode()->getASTNodeType() != AST::op) {
            std::cout << "\033[31mError: \033[0m"
                      << node->getContent() << " syntax error. What are u doing?" << std::endl;
        }
        result = generateOperator((AST::OperatorNode *)node->getChildNode(), symbolTable);
        AST::BaseNode *arg1Node = node->getChildNode()->getCousinNode();
        SMB::Symbol *arg2 = this->childValue.top();
        this->childValue.pop();
        if (arg1Node->getASTNodeType() == AST::assign_var) {
            SMB::Symbol *arg1 = symbolTable->findSymbol(arg1Node->getContent());
            temp = new Quaternion(IM::ASSIGN_STRUCT, arg1, arg2, result);
        }
        else if (arg1Node->getASTNodeType() == AST::op) {
            SMB::Symbol *arg1 = generateOperator((AST::OperatorNode *)arg1Node, symbolTable);
            temp = new Quaternion(IM::ASSIGN_STRUCT, arg1, arg2, result);
        }
        else if (arg1Node->getASTNodeType() == AST::literal) {
            int arg1 = std::stoi(arg1Node->getContent());
            temp = new Quaternion(IM::ASSIGN_STRUCT, arg1, arg2, result);
        }
        else if (arg1Node->getASTNodeType() == AST::call_func) {
            generate(arg1Node, symbolTable);
            SMB::Symbol *arg1 = temp_vars.back();
            temp = new Quaternion(IM::ASSIGN_STRUCT, arg1, arg2, result);
        }
        else {
            std::cout << "\033[31mError: \033[0m"
                      << "No match type of" << (int)arg1Node->getASTNodeType() << "  Content:" << arg1Node->getContent() << std::endl;
            exit(1);
        }
        this->quads.push_back(*temp);

        break;
    }
    case AST::relop: {
        Quaternion *tempTrue, *tempFalse;
        arg1Node = node->getChildNode();
        arg2Node = arg1Node->getCousinNode();
        std::cout<<"relop:"<<std::endl;
        if (node->getContent() == ">") {
            relopOperator(tempTrue, tempFalse, IM::JUMP_GREAT, arg1Node, arg2Node, symbolTable);
        }
        else if (node->getContent() == ">=") {
            relopOperator(tempTrue, tempFalse, IM::JUMP_EQ_GREAT, arg1Node, arg2Node, symbolTable);
        }
        else if (node->getContent() == "<") {
            relopOperator(tempTrue, tempFalse, IM::JUMP_SMALL, arg1Node, arg2Node, symbolTable);
        }
        else if (node->getContent() == "<=") {
            relopOperator(tempTrue, tempFalse, IM::JUMP_EQ_SMALL, arg1Node, arg2Node, symbolTable);
        }
        else if (node->getContent() == "!=") {
            relopOperator(tempTrue, tempFalse, IM::JUMP_NOT_EQUAL, arg1Node, arg2Node, symbolTable);
        }
        else if (node->getContent() == "==") {
            relopOperator(tempTrue, tempFalse, IM::JUMP_EQUAL, arg1Node, arg2Node, symbolTable);
        }
        break;
    }
    case AST::add: // 可能需要重构一下，方便看
    {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
        arg1Node = node->getChildNode();
        arg2Node = arg1Node->getCousinNode();
        temp_vars.push_back(result);
        result = temp_vars.back();
        temp = this->caculateOperator(IM::PLUS, arg1Node, arg2Node, result, symbolTable);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case AST::minus: {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
        arg1Node = node->getChildNode();
        arg2Node = arg1Node->getCousinNode();
        temp_vars.push_back(result);
        result = temp_vars.back();
        temp = this->caculateOperator(IM::MINUS, arg1Node, arg2Node, result, symbolTable);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case AST::multi: {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
        arg1Node = node->getChildNode();
        arg2Node = arg1Node->getCousinNode();
        temp_vars.push_back(result);
        result = temp_vars.back();
        temp = this->caculateOperator(IM::TIMES, arg1Node, arg2Node, result, symbolTable);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case AST::div: {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
        arg1Node = node->getChildNode();
        arg2Node = arg1Node->getCousinNode();
        temp_vars.push_back(result);
        result = temp_vars.back();
        temp = this->caculateOperator(IM::DIV, arg1Node, arg2Node, result, symbolTable);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case AST::mod: {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
        arg1Node = node->getChildNode();
        arg2Node = arg1Node->getCousinNode();
        temp_vars.push_back(result);
        result = temp_vars.back();
        temp = this->caculateOperator(IM::MOD, arg1Node, arg2Node, result, symbolTable);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case AST::pow: {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
        arg1Node = node->getChildNode();
        arg2Node = arg1Node->getCousinNode();
        temp_vars.push_back(result);
        result = temp_vars.back();
        temp = this->caculateOperator(IM::POWER, arg1Node, arg2Node, result, symbolTable);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case AST::negative: {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
        arg1Node = node->getChildNode();
        temp_vars.push_back(result);
        result = temp_vars.back();
        if (arg1Node->getASTNodeType() == AST::assign_var) {
            SMB::Symbol *arg1 = symbolTable->findSymbol(arg1Node->getContent());
            temp = new Quaternion(IM::NEGATIVE, arg1, result);
        }
        else if (arg1Node->getASTNodeType() == AST::literal) {
            int arg1 = std::stoi(arg1Node->getContent());
            temp = new Quaternion(IM::NEGATIVE, arg1, result);
        }
        else if (arg1Node->getASTNodeType() == AST::op) {
            SMB::Symbol *arg1 = generateOperator((AST::OperatorNode *)arg1Node, symbolTable);
            temp = new Quaternion(IM::NEGATIVE, arg1, result);
        }
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case AST::get_address: {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::pointer);
        arg1Node = node->getChildNode();
        temp_vars.push_back(result);
        if (arg1Node->getASTNodeType() == AST::assign_var) {
            SMB::Symbol *arg1 = symbolTable->findSymbol(arg1Node->getContent());
            temp = new Quaternion(IM::GET_ADDRESS, arg1, result);
        }
        else {
            std::cout << "\033[31mError: \033[0m"
                      << " lvalue required as unary ‘&’ operand" << std::endl;
            exit(1);
        }
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case AST::and_op: // 保证栈顶是：node2List, node1List,所以得先遍历子节点，再到&&节点
    {
        std::list<int> leftTrue, rightTrue, leftFalse, rightFalse;
        rightTrue = true_list.top();
        true_list.pop();
        leftTrue = true_list.top();
        true_list.pop();
        rightFalse = false_list.top();
        false_list.pop();
        leftFalse = false_list.top();
        false_list.pop();
        leftFalse.merge(rightFalse);
        false_list.push(leftFalse);
        true_list.push(rightTrue);
        backpatch(&leftTrue, signal.top());
        signal.pop();
        break;
    }
    case AST::or_op: {
        std::list<int> leftTrue, rightTrue, leftFalse, rightFalse;
        rightTrue = true_list.top();
        true_list.pop();
        leftTrue = true_list.top();
        true_list.pop();
        rightFalse = false_list.top();
        false_list.pop();
        leftFalse = false_list.top();
        false_list.pop();
        leftTrue.merge(rightTrue);
        true_list.push(leftTrue);
        false_list.push(rightFalse);
        backpatch(&leftFalse, signal.top());
        signal.pop();
        break;
    }
    case AST::not_op: {
        std::list<int> trueL, falseL;
        trueL = true_list.top();
        true_list.pop();
        falseL = false_list.top();
        false_list.pop();
        true_list.push(falseL);
        false_list.push(trueL);
        break;
    }
    case AST::get_var: {
        Quaternion *temp;
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
        arg1Node = node->getChildNode();
        temp_vars.push_back(result);
        if (arg1Node->getASTNodeType() == AST::assign_var) {
            SMB::Symbol *arg1 = symbolTable->findSymbol(arg1Node->getContent());
            temp = new Quaternion(IM::GET_VALUE, arg1, result);
        }
        else if (arg1Node->getASTNodeType() == AST::call_func) {
            generate(arg1Node, symbolTable);
            SMB::Symbol *arg1 = temp_vars.back();
            temp = new Quaternion(IM::GET_VALUE, arg1, result);
        }
        else if (arg1Node->getASTNodeType() == AST::op) {
            SMB::Symbol *arg1 = generateOperator((AST::OperatorNode *)arg1Node, symbolTable);
            temp = new Quaternion(IM::GET_VALUE, arg1, result);
        }
        else {
            std::cout << "\033[31mError: \033[0m"
                      << " lvalue required as unary ‘&’ operand" << std::endl;
            exit(1);
        }
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case AST::get_arr_var:
    {
        Quaternion *temp;
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
        AST::BaseNode *arg1Node = node->getChildNode();
        AST::BaseNode *arg2Node = arg1Node->getCousinNode();
        SMB::Symbol *arg1 = symbolTable->findSymbol(arg1Node->getContent());
        // 如果赋值，就把index push到 childValue中 返回arg1
        // 如果是别的运算，就把值放到temp中，返回temp，并且加一条四元式
        if (node->getParentNode()->getASTNodeType() == AST::op 
        && ((AST::OperatorNode *)node->getParentNode())->getOpType() == AST::assign_arr)
        {
            if (arg2Node->getASTNodeType() == AST::assign_var) {
                childValue.push(symbolTable->findSymbol(arg2Node->getContent()));
            }
            else if (arg2Node->getASTNodeType() == AST::call_func) {
                generate(arg2Node, symbolTable);
                SMB::Symbol *arg2 = temp_vars.back();
                childValue.push(arg2);
            }
            else if (arg2Node->getASTNodeType() == AST::literal) {
                SMB::Symbol *arg2 = new SMB::Symbol(arg2Node->getContent(), SMB::literal);
                childValue.push(arg2);
            }
            else if (arg2Node->getASTNodeType() == AST::op) {
                SMB::Symbol *arg2 = generateOperator((AST::OperatorNode *)arg2Node, symbolTable);
                childValue.push(arg2);
            }
            else {
                std::cout << "\033[31mError: \033[0m"
                          << "Type error" << std::endl;
                exit(1);
            }
            return arg1;
        }
        else {
            if (arg2Node->getASTNodeType() == AST::assign_var) {
                SMB::Symbol *arg2 = symbolTable->findSymbol(arg2Node->getContent());
                temp = new Quaternion(IM::GET_ARRAY, arg1, arg2, result);
            }
            else if (arg2Node->getASTNodeType() == AST::call_func) {
                generate(arg2Node, symbolTable);
                SMB::Symbol *arg2 = temp_vars.back();
                temp = new Quaternion(IM::GET_ARRAY, arg1, arg2, result);
            }
            else if (arg2Node->getASTNodeType() == AST::literal) {
                int arg2 = std::stoi(arg2Node->getContent());
                temp = new Quaternion(IM::GET_ARRAY, arg1, arg2, result);
            }
            else if (arg2Node->getASTNodeType() == AST::op) {
                SMB::Symbol *arg2 = generateOperator((AST::OperatorNode *)arg2Node, symbolTable);
                temp = new Quaternion(IM::GET_ARRAY, arg1, arg2, result);
            }
            else {
                std::cout << "\033[31mError: \033[0m"
                          << "Type error" << std::endl;
                exit(1);
            }
            temp_vars.push_back(result);
            this->quads.push_back(*temp);
            return result;
        }
    }
    case AST::get_member:
    {
        Quaternion *temp;
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
        AST::BaseNode *arg1Node = node->getChildNode();
        AST::BaseNode *arg2Node = arg1Node->getCousinNode();
        SMB::Symbol *arg1 = symbolTable->findSymbol(arg1Node->getContent());
        // 短路写法，应该没啥问题，不行再改
        if (node->getParentNode()->getASTNodeType() == AST::op 
        && ((AST::OperatorNode *)node->getParentNode())->getOpType() == AST::assign_member)
        {
            if (arg2Node->getASTNodeType() == AST::assign_var) {
                // TODO: struct table
                std::string typeName = ((SMB::StructDefSymbol *)arg1)->getTypeName();
                int offset = this->symbol_table->getStructTable()->findStruct(typeName)->getMemberOffset(arg2Node->getContent());
                SMB::Symbol *arg2 = new SMB::Symbol(std::to_string(offset), SMB::literal);
                childValue.push(arg2);
            }
            else {
                std::cout << "\033[31mError: \033[0m"
                          << "Type error" << std::endl;
                exit(1);
            }
            return arg1;
        } else {
            if (arg2Node->getASTNodeType() == AST::assign_var) {
                std::string typeName = ((SMB::StructDefSymbol *)arg1)->getTypeName();
                int offset = this->symbol_table->getStructTable()->findStruct(typeName)->getMemberOffset(arg2Node->getContent());
                SMB::Symbol *arg2 = new SMB::Symbol(std::to_string(offset), SMB::literal);
                temp = new Quaternion(IM::GET_STRUCT, arg1, arg2, result);
            } else {
                std::cout << "\033[31mError: \033[0m"
                          << "Type error" << std::endl;
                exit(1);
            }
            temp_vars.push_back(result);
            this->quads.push_back(*temp);
            return result;
        }
    }
    default:
        break;
    }
    return NULL;
}

IM::Quaternion *IM::InterMediate::caculateOperator(OperatorCode op, 
                                                   AST::BaseNode *arg1Node, 
                                                   AST::BaseNode *arg2Node, 
                                                   SMB::Symbol *result, 
                                                   SMB::SymbolTable *symbolTable)
{
    Quaternion *temp;
    // SMB::Symbol *result = new SMB::Symbol(std::to_string(temp_vars.size()), SMB::integer);
    // temp_vars.push_back(result);
    // result = temp_vars.back();

    if (arg1Node->getASTNodeType() == AST::assign_var 
     && arg2Node->getASTNodeType() == AST::assign_var) 
    {
        SMB::Symbol *arg1 = symbolTable->findSymbol(arg1Node->getContent());
        SMB::Symbol *arg2 = symbolTable->findSymbol(arg2Node->getContent());
        temp = new Quaternion(op, arg1, arg2, result);
    }
    else if (arg1Node->getASTNodeType() == AST::assign_var 
          && arg2Node->getASTNodeType() == AST::op)
    {
        SMB::Symbol *arg1 = symbolTable->findSymbol(arg1Node->getContent());
        SMB::Symbol *arg2 = generateOperator((AST::OperatorNode *)arg2Node, symbolTable);
        temp = new Quaternion(op, arg1, arg2, result);
    }
    else if (arg1Node->getASTNodeType() == AST::assign_var 
          && arg2Node->getASTNodeType() == AST::literal)
    {
        SMB::Symbol *arg1 = symbolTable->findSymbol(arg1Node->getContent());
        int arg2 = std::stoi(arg2Node->getContent());
        temp = new Quaternion(op, arg1, arg2, result);
    }
    else if (arg1Node->getASTNodeType() == AST::op 
          && arg2Node->getASTNodeType() == AST::assign_var)
    {
        SMB::Symbol *arg1 = generateOperator((AST::OperatorNode *)arg1Node, symbolTable);
        SMB::Symbol *arg2 = symbolTable->findSymbol(arg2Node->getContent());
        temp = new Quaternion(op, arg1, arg2, result);
    }
    else if (arg1Node->getASTNodeType() == AST::op 
          && arg2Node->getASTNodeType() == AST::op)
    {
        SMB::Symbol *arg1 = generateOperator((AST::OperatorNode *)arg1Node, symbolTable);
        SMB::Symbol *arg2 = generateOperator((AST::OperatorNode *)arg2Node, symbolTable);
        temp = new Quaternion(op, arg1, arg2, result);
    }
    else if (arg1Node->getASTNodeType() == AST::op 
          && arg2Node->getASTNodeType() == AST::literal)
    {
        SMB::Symbol *arg1 = generateOperator((AST::OperatorNode *)arg1Node, symbolTable);
        int arg2 = std::stoi(arg2Node->getContent());
        temp = new Quaternion(op, arg1, arg2, result);
    }

    else if (arg1Node->getASTNodeType() == AST::literal 
          && arg2Node->getASTNodeType() == AST::assign_var)
    {
        int arg1 = std::stoi(arg1Node->getContent());
        SMB::Symbol *arg2 = symbolTable->findSymbol(arg2Node->getContent());
        temp = new Quaternion(op, arg1, arg2, result);
    }
    else if (arg1Node->getASTNodeType() == AST::literal 
          && arg2Node->getASTNodeType() == AST::op)
    {
        int arg1 = std::stoi(arg1Node->getContent());
        SMB::Symbol *arg2 = generateOperator((AST::OperatorNode *)arg2Node, symbolTable);
        temp = new Quaternion(op, arg1, arg2, result);
    }
    else if (arg1Node->getASTNodeType() == AST::literal 
          && arg2Node->getASTNodeType() == AST::literal)
    {
        int arg1 = std::stoi(arg1Node->getContent());
        int arg2 = std::stoi(arg2Node->getContent());
        temp = new Quaternion(op, arg1, arg2, result);
    } else {
        std::cout << "\033[31mError: \033[0m"
                  << "No match type for" << (int)arg1Node->getASTNodeType() << "  Content:" << arg1Node->getContent() << std::endl;
        exit(1);
    }
    return temp;
}

void IM::InterMediate::relopOperator(Quaternion *trueQuad, 
                                     Quaternion *falseQuad, 
                                     OperatorCode op, 
                                     AST::BaseNode *arg1Node, 
                                     AST::BaseNode *arg2Node, 
                                     SMB::SymbolTable *symbolTable)
{
    if (arg1Node->getASTNodeType() == AST::assign_var 
     && arg2Node->getASTNodeType() == AST::assign_var)
    {
        trueQuad = new Quaternion(op, symbolTable->findSymbol(arg1Node->getContent()), 
                                                              symbolTable->findSymbol(arg2Node->getContent()), 
                                                              (int)NULL);
        falseQuad = new Quaternion(IM::JUMP, (int)NULL);
    }
    else if (arg1Node->getASTNodeType() == AST::assign_var 
          && arg2Node->getASTNodeType() == AST::literal)
    {
        trueQuad = new Quaternion(op, 
                                  symbolTable->findSymbol(arg1Node->getContent()), 
                                  std::stoi(arg2Node->getContent()), 
                                  (int)NULL);
        falseQuad = new Quaternion(IM::JUMP, (int)NULL);
    }
    else if (arg1Node->getASTNodeType() == AST::literal 
          && arg2Node->getASTNodeType() == AST::assign_var)
    {
        trueQuad = new Quaternion(op, 
                                  std::stoi(arg1Node->getContent()), 
                                  symbolTable->findSymbol(arg2Node->getContent()), 
                                  (int)NULL);
        falseQuad = new Quaternion(IM::JUMP, (int)NULL);
    }
    else if (arg1Node->getASTNodeType() == AST::literal 
          && arg2Node->getASTNodeType() == AST::literal)
    {
        trueQuad = new Quaternion(op, 
                                  std::stoi(arg1Node->getContent()), 
                                  std::stoi(arg2Node->getContent()), 
                                  (int)NULL);
        falseQuad = new Quaternion(IM::JUMP, (int)NULL);
    }
    std::list<int> trueL; // Use size to get the index of true quad will be pushed
    trueL.push_back(quads.size());
    this->quads.push_back(*trueQuad);
    std::list<int> falseL; // Same as the upper one
    falseL.push_back(quads.size());
    this->quads.push_back(*falseQuad);
    true_list.push(trueL);
    false_list.push(falseL);
    return;
}

std::list<int> *IM::InterMediate::makelist(int index) {
    std::list<int> *jumpList = new std::list<int>();
    jumpList->push_back(index);
    return jumpList;
}
std::list<int> *IM::InterMediate::merge(std::list<int> *list1, std::list<int> *list2) {
    list1->merge(*list2);
    return list1;
}
void IM::InterMediate::backpatch(std::list<int> *backList, int target) {
    std::list<int>::iterator it;
    for (it = backList->begin(); it != backList->end(); it++) {
        quads[*it].backpatch(target);
    }
    return;
}
void IM::InterMediate::print() {
    std::vector<Quaternion>::iterator it;
    std::cout << "\t   Operator   \targ1\targ2\tresult" << std::endl;
    int count = 0;
    for (it = this->quads.begin(); it != this->quads.end(); it++)
    {
        std::cout << count++ << "\t";
        it->print();
    }
    return;
}