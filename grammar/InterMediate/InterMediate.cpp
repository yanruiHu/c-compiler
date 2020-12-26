#include "./InterMediate.h"
#include <typeinfo>
#include <cstdio>
IM::InterMediate::InterMediate(AST::BaseNode *root_node, SMB::StructTable *struct_table) {
    temp_vars.reserve(100);
    this->root = root_node;
    this->root_symbol_table = new SMB::SymbolTable(false, struct_table);
    SMB::SymbolTable::setGlobalTable(this->root_symbol_table);
    std::cout << "root_symbol_table: " << this->root_symbol_table << std::endl;
    std::cout << "struct_table: " << struct_table << std::endl;
}

void IM::InterMediate::generate(AST::BaseNode *node, SMB::SymbolTable *symbol_table) {
    if (node == NULL) {
        std::cout << "NULL" << std::endl;
        return;
    }
    AST::BaseNode *p = node->getChildNode();
    switch (node->getASTNodeType()) {
    case AST::def_func: {
        SMB::FuncSymbol *func = new SMB::FuncSymbol(node);
        this->root_symbol_table->addFuncSymbol(func);
        Quaternion *temp;
        SMB::Symbol *temp_symbol = new SMB::Symbol(func->getDecName(), SMB::void_type);
        temp = new Quaternion(IM::FUNC_DEF, temp_symbol, (SMB::Symbol *)NULL);
        this->quads.push_back(*temp);
        while (p != NULL) {
            SMB::SymbolTable *child_table = symbol_table->createChildTable(true);
            child_table->setTableName(func->getDecName());
            child_table->addFromFunctionArgs(func);
            generate(p, child_table);
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
                // std::cout<<"var_content: "<<var->getContent()<<std::endl;
                SMB::Symbol *arg1 = symbol_table->findSymbol(var->getContent());
                temp = new Quaternion(IM::PARAM, arg1, (SMB::Symbol *)NULL);
                // std::cout<<"arg1_name: "<<arg1->getName()<<" arg1_type: "<<arg1->getType()<<std::endl;
                switch (arg1->getType()) {
                case SMB::integer:
                    add_on = add_on + "_i";
                    break;
                case SMB::pointer:
                    add_on = add_on + "_p";
                    break;
                default:
                    std::cout << "Wrong Type!\n";
                    break;
                }
            }
            else if (var->getASTNodeType() == AST::literal) {
                int arg1 = std::stoi(var->getContent());
                temp = new Quaternion(IM::PARAM, arg1, (SMB::Symbol*)NULL);
                add_on = add_on + "_i";
            }
            else if (var->getASTNodeType() == AST::op) {
                SMB::Symbol *arg1 = generateOperator((AST::OperatorNode*)var, symbol_table);
                std::cout << "generate op finished!\n";
                temp = new Quaternion(IM::PARAM, arg1, (SMB::Symbol*)NULL);
                switch (arg1->getType())
                {
                case SMB::integer:
                    add_on = add_on + "_i";
                    break;
                case SMB::pointer:
                    add_on = add_on + "_p";
                    break;
                default:
                    break;
                }
            }
            this->quads.push_back(*temp);
            var = var->getCousinNode();
        }
        SMB::FuncSymbol *fun_sym = (SMB::FuncSymbol*)this->root_symbol_table->findSymbol(node->getContent() + add_on);
        if (fun_sym == NULL) {
            std::cout << "\033[31mError: \033[0m"
                      << " function is not decleared." << std::endl;
            exit(1);
        }
        SMB::Symbol *func_symbol = new SMB::Symbol(fun_sym->getDecName(), SMB::void_type);
        // SMB::Symbol *func_symbol = new SMB::Symbol(fun_sym->getFunName(), SMB::void_type);
        SMB::Symbol *temp_v = NULL;

        if (node->getParentNode()->getASTNodeType() == AST::stmt) {
            AST::StatementNode *stmt = (AST::StatementNode *)node->getParentNode();
            if (stmt->getStmtType() == AST::expression) {
                temp_v = NULL;
            }
            else {
                temp_v = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
                temp_vars.push_back(temp_v);
            }
        }
        else {
            temp_v = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
            temp_vars.push_back(temp_v);
        }

        Quaternion *temp = new Quaternion(IM::CALL, func_symbol, count, temp_v);
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
    case AST::op: {
        if (((AST::OperatorNode*)node)->getOpType() == AST::and_op 
        || ((AST::OperatorNode *)node)->getOpType() == AST::or_op)
        {
            generate(p, symbol_table);
            signal.push(quads.size());
            generate(p->getCousinNode(), symbol_table);
        }
        else if (((AST::OperatorNode*)node)->getOpType() == AST::not_op 
             || ((AST::OperatorNode *)node)->getOpType() == AST::relop)
        {
            while (p != NULL) {
                generate(p, symbol_table);
                p = p->getCousinNode();
            }
        }
        this->generateOperator((AST::OperatorNode *)node, symbol_table);
        break;
    }
    case AST::stmt: {
        AST::StatementNode *ret = (AST::StatementNode *)node;
        if (ret->getStmtType() == AST::return_stmt) {
            generateReturn((AST::StatementNode *)node, symbol_table);
        }
        else {
            while (p != NULL) {
                generate(p, this->generateStatement((AST::StatementNode *)node, symbol_table));
                p = p->getCousinNode();
            }
        }
        break;
    }
    case AST::def_var: {
        AST::DefineVarNode *temp_node = (AST::DefineVarNode*)node;
        if (temp_node->getSymbolType() == SMB::struct_type) {
            // TODO: addStructSymbol
            if (symbol_table->addStructSymbol(temp_node->getStructName(), temp_node->getContent()) == 0) {
                std::cout << "\033[31mError: \033[0m"
                << "struct " << temp_node->getStructName() << " is not defined" << std::endl;
                exit(1);
            }
        } else if (temp_node->getSymbolType() == SMB::array) {
            symbol_table->addArraySymbol(temp_node);
        } else {
            if(symbol_table->addSymbol(node) == 0){
                std::cout << "\033[31mError: \033[0m"
                << "value " << node->getContent() << " is redeclaration" << std::endl;
                exit(1);
            }
        }
        SMB::Symbol *var_symbol = symbol_table->findSymbol(node->getContent());
        if (p != NULL) {
            Quaternion *temp;
            if (p->getASTNodeType() == AST::literal) {
                int arg1 = std::stoi(p->getContent());
                temp = new Quaternion(IM::ASSIGN, arg1, var_symbol);
            }
            else if (p->getASTNodeType() == AST::assign_var) {
                SMB::Symbol *arg1 = symbol_table->findSymbol(p->getContent());
                temp = new Quaternion(IM::ASSIGN, arg1, var_symbol);
            }
            else if (p->getASTNodeType() == AST::op) {
                SMB::Symbol *arg1 = this->generateOperator((AST::OperatorNode *)p, symbol_table);
                temp = new Quaternion(IM::ASSIGN, arg1, var_symbol);
            }
            else if (p->getASTNodeType() == AST::call_func) {
                generate(p, symbol_table);
                SMB::Symbol *arg1 = temp_vars.back();
                temp = new Quaternion(IM::ASSIGN, arg1, var_symbol);
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
    case AST::assign_var: {
        if (node->getParentNode()->getASTNodeType() == AST::op) {
            AST::OperatorNode *par = (AST::OperatorNode *)node->getParentNode();
            if (par->getOpType() == AST::and_op 
             || par->getOpType() == AST::or_op 
            || par->getOpType() == AST::not_op)
            {
                SMB::Symbol *arg1 = symbol_table->findSymbol(node->getContent());
                Quaternion *true_quad = new Quaternion(IM::JUMP_GREAT, arg1, 0, (int)NULL);
                Quaternion *false_quad = new Quaternion(IM::JUMP, (int)NULL);
                std::list<int> trueL;
                trueL.push_back(quads.size());
                this->quads.push_back(*true_quad);
                std::list<int> falseL;
                falseL.push_back(quads.size());
                this->quads.push_back(*false_quad);
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
            SMB::SymbolTable *child_table = symbol_table->createChildTable(false);
            child_table->setTableName("for");
            generate(((AST::LoopNode*)node)->getDecNode(), child_table);
            int start = quads.size();
            generate(((AST::LoopNode*)node)->getCondNode(), child_table);
            std::list<int> Judge_true = true_list.top();
            std::list<int> Judge_false = false_list.top();
            true_list.pop();
            false_list.pop();
            backPatch(&Judge_true, Judge_true.back() + 2);
            while (p != NULL)
            {
                generate(p, child_table);
                p = p->getCousinNode();
            }
            generate(((AST::LoopNode*)node)->getActionNode(), child_table);

            Quaternion *temp = new Quaternion(IM::JUMP, start);
            this->quads.push_back(*temp);
            int end = quads.size();
            backPatch(&Judge_false, end);
        }
        else if (loop->getLoopType() == AST::while_loop)
        {
            int start = quads.size();
            generate(((AST::LoopNode*)node)->getCondNode(), symbol_table);
            std::list<int> Judge_true = true_list.top();
            std::list<int> Judge_false = false_list.top();
            true_list.pop();
            false_list.pop();
            backPatch(&Judge_true, Judge_true.back() + 2);
            while (p != NULL) {
                SMB::SymbolTable *child_table = symbol_table->createChildTable(false);
                child_table->setTableName("while");
                generate(p, child_table);
                p = p->getCousinNode();
            }

            Quaternion *temp = new Quaternion(IM::JUMP, start);
            this->quads.push_back(*temp);
            int end = quads.size();
            backPatch(&Judge_false, end);
        }
        break;
    }
    case AST::select: // Just IF and ELSE.
    {
        AST::SelectNode *select = (AST::SelectNode*)node;
        generate(select->getCondNode(), symbol_table);
        // std::cout << "generate finished!\n";
        int start = quads.size();
        std::cout << "true_list pop!\n";
        std::list<int> Judge_true = true_list.top();
        std::list<int> Judge_false = false_list.top();
        true_list.pop();
        false_list.pop();

        backPatch(&Judge_true, start);
        // Body:
        // std::cout << "body: " << select->getBodyNode() << "\n";
        generate(select->getBodyNode(), symbol_table);
        if (select->getElse() != NULL) {
            // std::cout << "else if\n";
            Quaternion *temp = new Quaternion(IM::JUMP, (int)NULL);
            this->quads.push_back(*temp);
            temp = &quads.back();
            int else_start = quads.size();
            generate(select->getElse(), symbol_table);
            // std::cout << "generate finished\n";
            backPatch(&Judge_false, else_start);
            int end = quads.size();
            temp->backPatch(end);
        } else {
            int end = quads.size();
            backPatch(&Judge_false, end);
        }
        break;
    }
    case AST::root: {
        while (p != NULL) {
            generate(p, symbol_table);
            p = p->getCousinNode();
        }
        break;
    }
    default:
        std::cout << "Hello! Something Wrong happened!\n";
        break;
    }
    return;
}

SMB::SymbolTable *IM::InterMediate::generateStatement(AST::StatementNode *node, SMB::SymbolTable *symbol_table) {
    switch (node->getStmtType()) {
    case AST::comparation: {
        if (node->getParentNode()->getASTNodeType() == AST::loop)
            return symbol_table;
        if (node->getParentNode()->getASTNodeType() == AST::def_func)
            return symbol_table;
        SMB::SymbolTable *child_table = symbol_table->createChildTable(false);
        child_table->setTableName("comparation");
        return child_table;
    }
    break;
    default:
        break;
    }
    return symbol_table;
}

SMB::SymbolTable *IM::InterMediate::generateReturn(AST::StatementNode *node, SMB::SymbolTable *symbol_table)
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
        SMB::Symbol *arg1 = symbol_table->findSymbol(p->getContent());
        temp = new Quaternion(IM::RETURN, arg1, result);
    }
    else if (p->getASTNodeType() == AST::op) {
        SMB::Symbol *arg1 = this->generateOperator((AST::OperatorNode *)p, symbol_table);
        temp = new Quaternion(IM::RETURN, arg1, result);
    }
    else if (p->getASTNodeType() == AST::call_func) {
        generate(p, symbol_table);
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

SMB::Symbol *IM::InterMediate::generateOperator(AST::OperatorNode *node, SMB::SymbolTable *symbol_table)
{
    std::cout << "op begin, type: " << node->getOpType() << "\n";
    Quaternion *temp;
    AST::BaseNode *arg1_node, *arg2_node;
    switch (node->getOpType()) {
    case AST::assign: {
        SMB::Symbol *result;
        IM::OperatorCode op;
        if (node->getChildNode()->getASTNodeType() == AST::op 
        && ((AST::OperatorNode *)node->getChildNode())->getOpType() == AST::get_var)
        {
            op = IM::ASSIGN_POINTER;
            result = symbol_table->findSymbol(node->getChildNode()->getChildNode()->getContent());
        }
        else {
            op = IM::ASSIGN;
            if (node->getChildNode()->getASTNodeType() != AST::assign_var
            &&  node->getChildNode()->getASTNodeType() != AST::def_var) {
                std::cout << "\033[31mError: \033[0m"
                          << "node_type:"<<node->getChildNode()->getASTNodeType()
                          << node->getChildNode()->getContent() << " is not a variable. What are u doing?" << std::endl;
                exit(1);
            } else if (node->getChildNode()->getASTNodeType() == AST::def_var) {
                if(symbol_table->addSymbol(node->getChildNode()) == 0){
                    std::cout << "\033[31mError: \033[0m"
                    << "value " << node->getChildNode()->getContent() << " is redeclaration" << std::endl;
                    exit(1);
                }
            }
            result = symbol_table->findSymbol(node->getChildNode()->getContent());
        }

        AST::BaseNode *arg1_node = node->getChildNode()->getCousinNode();
        if (arg1_node->getASTNodeType() == AST::assign_var) {
            SMB::Symbol *arg1 = symbol_table->findSymbol(arg1_node->getContent());
            if (result->getType() == SMB::integer && arg1->getType() == SMB::pointer) {
                std::cout << "\033[31mError: \033[0m"
                          << "Syntax error, maybe you have used the wrong type: " << (int)arg1_node->getASTNodeType() << "  Content:" << arg1_node->getContent() << std::endl;
                exit(1);
            }
            temp = new Quaternion(op, arg1, result);
        }
        else if (arg1_node->getASTNodeType() == AST::op) {
            SMB::Symbol *arg1 = generateOperator((AST::OperatorNode *)arg1_node, symbol_table);
            temp = new Quaternion(op, arg1, result);
        }
        else if (arg1_node->getASTNodeType() == AST::literal) {
            int arg1 = std::stoi(arg1_node->getContent());
            temp = new Quaternion(op, arg1, result);
        }
        else if (arg1_node->getASTNodeType() == AST::call_func) {
            generate(arg1_node, symbol_table);
            SMB::Symbol *arg1 = temp_vars.back();
            temp = new Quaternion(op, arg1, result);
        }
        else {
            std::cout << "\033[31mError: \033[0m"
                      << "No match type of" << (int)arg1_node->getASTNodeType() << "  Content:" << arg1_node->getContent() << std::endl;
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
        result = generateOperator((AST::OperatorNode *)node->getChildNode(), symbol_table);
        AST::BaseNode *arg1_node = node->getChildNode()->getCousinNode();
        SMB::Symbol *arg2 = this->child_value.top();
        this->child_value.pop();
        if (arg1_node->getASTNodeType() == AST::assign_var) {
            SMB::Symbol *arg1 = symbol_table->findSymbol(arg1_node->getContent());
            temp = new Quaternion(IM::ASSIGN_ARRAY, arg1, arg2, result);
        }
        else if (arg1_node->getASTNodeType() == AST::op) {
            SMB::Symbol *arg1 = generateOperator((AST::OperatorNode *)arg1_node, symbol_table);
            temp = new Quaternion(IM::ASSIGN_ARRAY, arg1, arg2, result);
        }
        else if (arg1_node->getASTNodeType() == AST::literal) {
            int arg1 = std::stoi(arg1_node->getContent());
            temp = new Quaternion(IM::ASSIGN_ARRAY, arg1, arg2, result);
        }
        else if (arg1_node->getASTNodeType() == AST::call_func) {
            generate(arg1_node, symbol_table);
            SMB::Symbol *arg1 = temp_vars.back();
            temp = new Quaternion(IM::ASSIGN_ARRAY, arg1, arg2, result);
        }
        else {
            std::cout << "\033[31mError: \033[0m"
                      << "No match type of" << (int)arg1_node->getASTNodeType() << "  Content:" << arg1_node->getContent() << std::endl;
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
        result = generateOperator((AST::OperatorNode *)node->getChildNode(), symbol_table);
        AST::BaseNode *arg1_node = node->getChildNode()->getCousinNode();
        SMB::Symbol *arg2 = this->child_value.top();
        this->child_value.pop();
        if (arg1_node->getASTNodeType() == AST::assign_var) {
            SMB::Symbol *arg1 = symbol_table->findSymbol(arg1_node->getContent());
            temp = new Quaternion(IM::ASSIGN_STRUCT, arg1, arg2, result);
        } else if (arg1_node->getASTNodeType() == AST::op) {
            SMB::Symbol *arg1 = generateOperator((AST::OperatorNode *)arg1_node, symbol_table);
            temp = new Quaternion(IM::ASSIGN_STRUCT, arg1, arg2, result);
        } else if (arg1_node->getASTNodeType() == AST::literal) {
            int arg1 = std::stoi(arg1_node->getContent());
            temp = new Quaternion(IM::ASSIGN_STRUCT, arg1, arg2, result);
        } else if (arg1_node->getASTNodeType() == AST::call_func) {
            generate(arg1_node, symbol_table);
            SMB::Symbol *arg1 = temp_vars.back();
            temp = new Quaternion(IM::ASSIGN_STRUCT, arg1, arg2, result);
        }
        else {
            std::cout << "\033[31mError: \033[0m"
                      << "No match type of" << (int)arg1_node->getASTNodeType() << "  Content:" << arg1_node->getContent() << std::endl;
            exit(1);
        }
        this->quads.push_back(*temp);

        break;
    }
    case AST::relop: {
        Quaternion *temp_true, *temp_false;
        arg1_node = node->getChildNode();
        arg2_node = arg1_node->getCousinNode();
        // std::cout<<"relop:"<<node->getContent()<<std::endl;
        if (node->getContent() == ">") {
            relopOperator(temp_true, temp_false, IM::JUMP_GREAT, arg1_node, arg2_node, symbol_table);
        }
        else if (node->getContent() == ">=") {
            relopOperator(temp_true, temp_false, IM::JUMP_EQ_GREAT, arg1_node, arg2_node, symbol_table);
        }
        else if (node->getContent() == "<") {
            relopOperator(temp_true, temp_false, IM::JUMP_SMALL, arg1_node, arg2_node, symbol_table);
        }
        else if (node->getContent() == "<=") {
            relopOperator(temp_true, temp_false, IM::JUMP_EQ_SMALL, arg1_node, arg2_node, symbol_table);
        }
        else if (node->getContent() == "!=") {
            relopOperator(temp_true, temp_false, IM::JUMP_NOT_EQUAL, arg1_node, arg2_node, symbol_table);
        }
        else if (node->getContent() == "==") {
            relopOperator(temp_true, temp_false, IM::JUMP_EQUAL, arg1_node, arg2_node, symbol_table);
        } else {
            std::cout << "Wrong Content in RELOP\n";
            exit(1);
        }
        break;
    }
    case AST::add: // 可能需要重构一下，方便看
    {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
        arg1_node = node->getChildNode();
        arg2_node = arg1_node->getCousinNode();
        temp_vars.push_back(result);
        result = temp_vars.back();
        temp = this->caculateOperator(IM::PLUS, arg1_node, arg2_node, result, symbol_table);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case AST::minus: {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
        arg1_node = node->getChildNode();
        arg2_node = arg1_node->getCousinNode();
        temp_vars.push_back(result);
        result = temp_vars.back();
        temp = this->caculateOperator(IM::MINUS, arg1_node, arg2_node, result, symbol_table);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case AST::multi: {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
        arg1_node = node->getChildNode();
        arg2_node = arg1_node->getCousinNode();
        temp_vars.push_back(result);
        result = temp_vars.back();
        temp = this->caculateOperator(IM::TIMES, arg1_node, arg2_node, result, symbol_table);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case AST::div: {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
        arg1_node = node->getChildNode();
        arg2_node = arg1_node->getCousinNode();
        temp_vars.push_back(result);
        result = temp_vars.back();
        temp = this->caculateOperator(IM::DIV, arg1_node, arg2_node, result, symbol_table);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case AST::mod: {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
        arg1_node = node->getChildNode();
        arg2_node = arg1_node->getCousinNode();
        temp_vars.push_back(result);
        result = temp_vars.back();
        temp = this->caculateOperator(IM::MOD, arg1_node, arg2_node, result, symbol_table);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case AST::pow: {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
        arg1_node = node->getChildNode();
        arg2_node = arg1_node->getCousinNode();
        temp_vars.push_back(result);
        result = temp_vars.back();
        temp = this->caculateOperator(IM::POWER, arg1_node, arg2_node, result, symbol_table);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case AST::negative: {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
        arg1_node = node->getChildNode();
        temp_vars.push_back(result);
        result = temp_vars.back();
        if (arg1_node->getASTNodeType() == AST::assign_var) {
            SMB::Symbol *arg1 = symbol_table->findSymbol(arg1_node->getContent());
            temp = new Quaternion(IM::NEGATIVE, arg1, result);
        }
        else if (arg1_node->getASTNodeType() == AST::literal) {
            int arg1 = std::stoi(arg1_node->getContent());
            temp = new Quaternion(IM::NEGATIVE, arg1, result);
        }
        else if (arg1_node->getASTNodeType() == AST::op) {
            SMB::Symbol *arg1 = generateOperator((AST::OperatorNode *)arg1_node, symbol_table);
            temp = new Quaternion(IM::NEGATIVE, arg1, result);
        }
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case AST::get_address: {
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::pointer);
        arg1_node = node->getChildNode();
        temp_vars.push_back(result);
        if (arg1_node->getASTNodeType() == AST::assign_var) {
            SMB::Symbol *arg1 = symbol_table->findSymbol(arg1_node->getContent());
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
        std::list<int> left_true, right_true, left_false, right_false;
        right_true = true_list.top();
        true_list.pop();
        left_true = true_list.top();
        true_list.pop();
        right_false = false_list.top();
        false_list.pop();
        left_false = false_list.top();
        false_list.pop();
        left_false.merge(right_false);
        false_list.push(left_false);
        true_list.push(right_true);
        backPatch(&left_true, signal.top());
        signal.pop();
        break;
    }
    case AST::or_op: {
        std::list<int> left_true, right_true, left_false, right_false;
        right_true = true_list.top();
        true_list.pop();
        left_true = true_list.top();
        true_list.pop();
        right_false = false_list.top();
        false_list.pop();
        left_false = false_list.top();
        false_list.pop();
        left_true.merge(right_true);
        true_list.push(left_true);
        false_list.push(right_false);
        backPatch(&left_false, signal.top());
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
        arg1_node = node->getChildNode();
        temp_vars.push_back(result);
        if (arg1_node->getASTNodeType() == AST::assign_var) {
            SMB::Symbol *arg1 = symbol_table->findSymbol(arg1_node->getContent());
            temp = new Quaternion(IM::GET_VALUE, arg1, result);
        }
        else if (arg1_node->getASTNodeType() == AST::call_func) {
            generate(arg1_node, symbol_table);
            SMB::Symbol *arg1 = temp_vars.back();
            temp = new Quaternion(IM::GET_VALUE, arg1, result);
        }
        else if (arg1_node->getASTNodeType() == AST::op) {
            SMB::Symbol *arg1 = generateOperator((AST::OperatorNode *)arg1_node, symbol_table);
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
        AST::BaseNode *arg1_node = node->getChildNode();
        AST::BaseNode *arg2_node = arg1_node->getCousinNode();
        SMB::Symbol *arg1 = symbol_table->findSymbol(arg1_node->getContent());
        // 如果赋值，就把index push到 child_value中 返回arg1
        // 如果是别的运算，就把值放到temp中，返回temp，并且加一条四元式
        if (node->getParentNode()->getASTNodeType() == AST::op 
        && ((AST::OperatorNode *)node->getParentNode())->getOpType() == AST::assign_arr)
        {
            if (arg2_node->getASTNodeType() == AST::assign_var) {
                child_value.push(symbol_table->findSymbol(arg2_node->getContent()));
            }
            else if (arg2_node->getASTNodeType() == AST::call_func) {
                generate(arg2_node, symbol_table);
                SMB::Symbol *arg2 = temp_vars.back();
                child_value.push(arg2);
            }
            else if (arg2_node->getASTNodeType() == AST::literal) {
                SMB::Symbol *arg2 = new SMB::Symbol(arg2_node->getContent(), SMB::literal);
                child_value.push(arg2);
            }
            else if (arg2_node->getASTNodeType() == AST::op) {
                SMB::Symbol *arg2 = generateOperator((AST::OperatorNode *)arg2_node, symbol_table);
                child_value.push(arg2);
            }
            else {
                std::cout << "\033[31mError: \033[0m"
                          << "Type error" << std::endl;
                exit(1);
            }
            return arg1;
        }
        else {
            if (arg2_node->getASTNodeType() == AST::assign_var) {
                SMB::Symbol *arg2 = symbol_table->findSymbol(arg2_node->getContent());
                temp = new Quaternion(IM::GET_ARRAY, arg1, arg2, result);
            }
            else if (arg2_node->getASTNodeType() == AST::call_func) {
                generate(arg2_node, symbol_table);
                SMB::Symbol *arg2 = temp_vars.back();
                temp = new Quaternion(IM::GET_ARRAY, arg1, arg2, result);
            }
            else if (arg2_node->getASTNodeType() == AST::literal) {
                int arg2 = std::stoi(arg2_node->getContent());
                temp = new Quaternion(IM::GET_ARRAY, arg1, arg2, result);
            }
            else if (arg2_node->getASTNodeType() == AST::op) {
                SMB::Symbol *arg2 = generateOperator((AST::OperatorNode *)arg2_node, symbol_table);
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
        std::cout << "get_member\n";
        Quaternion *temp;
        SMB::Symbol *result = new SMB::Symbol("Temp" + std::to_string(temp_vars.size()), SMB::integer);
        AST::BaseNode *arg1_node = node->getChildNode();
        AST::BaseNode *arg2_node = arg1_node->getCousinNode();
        SMB::Symbol *arg1 = symbol_table->findSymbol(arg1_node->getContent());
        // 短路写法，应该没啥问题，不行再改
        std::cout << "parent: " << node->getParentNode() << std::endl;
        if (node->getParentNode()->getASTNodeType() == AST::op 
        && ((AST::OperatorNode *)node->getParentNode())->getOpType() == AST::assign_member)
        {
            if (arg2_node->getASTNodeType() == AST::assign_var) {
                // TODO: struct table
                std::string type_name = ((SMB::StructDefSymbol *)arg1)->getTypeName();
                // std::cout<<"struct_list:"<<this->root_symbol_table->getStructTable()<<std::endl;
                int offset = this->root_symbol_table->getStructTable()->findStruct(type_name)->getMemberOffset(arg2_node->getContent());
                SMB::Symbol *arg2 = new SMB::Symbol(std::to_string(offset), SMB::literal);
                child_value.push(arg2);
            }
            else {
                std::cout << "\033[31mError: \033[0m"
                          << "Type error" << std::endl;
                exit(1);
            }
            return arg1;
        } else {
            if (arg2_node->getASTNodeType() == AST::assign_var) {
                std::string type_name = ((SMB::StructDefSymbol *)arg1)->getTypeName();
                // std::cout<<"struct_list:"<<this->root_symbol_table->getStructTable()<<std::endl;
                int offset = this->root_symbol_table->getStructTable()->findStruct(type_name)->getMemberOffset(arg2_node->getContent());
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
                                                   AST::BaseNode *arg1_node, 
                                                   AST::BaseNode *arg2_node, 
                                                   SMB::Symbol *result, 
                                                   SMB::SymbolTable *symbol_table)
{
    Quaternion *temp;
    // SMB::Symbol *result = new SMB::Symbol(std::to_string(temp_vars.size()), SMB::integer);
    // temp_vars.push_back(result);
    // result = temp_vars.back();

    if (arg1_node->getASTNodeType() == AST::assign_var 
     && arg2_node->getASTNodeType() == AST::assign_var) 
    {
        SMB::Symbol *arg1 = symbol_table->findSymbol(arg1_node->getContent());
        SMB::Symbol *arg2 = symbol_table->findSymbol(arg2_node->getContent());
        temp = new Quaternion(op, arg1, arg2, result);
    }
    else if (arg1_node->getASTNodeType() == AST::assign_var 
          && arg2_node->getASTNodeType() == AST::op)
    {
        SMB::Symbol *arg1 = symbol_table->findSymbol(arg1_node->getContent());
        SMB::Symbol *arg2 = generateOperator((AST::OperatorNode *)arg2_node, symbol_table);
        temp = new Quaternion(op, arg1, arg2, result);
    }
    else if (arg1_node->getASTNodeType() == AST::assign_var 
          && arg2_node->getASTNodeType() == AST::literal)
    {
        SMB::Symbol *arg1 = symbol_table->findSymbol(arg1_node->getContent());
        int arg2 = std::stoi(arg2_node->getContent());
        temp = new Quaternion(op, arg1, arg2, result);
    }
    else if (arg1_node->getASTNodeType() == AST::op 
          && arg2_node->getASTNodeType() == AST::assign_var)
    {
        SMB::Symbol *arg1 = generateOperator((AST::OperatorNode *)arg1_node, symbol_table);
        SMB::Symbol *arg2 = symbol_table->findSymbol(arg2_node->getContent());
        temp = new Quaternion(op, arg1, arg2, result);
    }
    else if (arg1_node->getASTNodeType() == AST::op 
          && arg2_node->getASTNodeType() == AST::op)
    {
        SMB::Symbol *arg1 = generateOperator((AST::OperatorNode *)arg1_node, symbol_table);
        SMB::Symbol *arg2 = generateOperator((AST::OperatorNode *)arg2_node, symbol_table);
        temp = new Quaternion(op, arg1, arg2, result);
    }
    else if (arg1_node->getASTNodeType() == AST::op 
          && arg2_node->getASTNodeType() == AST::literal)
    {
        SMB::Symbol *arg1 = generateOperator((AST::OperatorNode *)arg1_node, symbol_table);
        int arg2 = std::stoi(arg2_node->getContent());
        temp = new Quaternion(op, arg1, arg2, result);
    }

    else if (arg1_node->getASTNodeType() == AST::literal 
          && arg2_node->getASTNodeType() == AST::assign_var)
    {
        int arg1 = std::stoi(arg1_node->getContent());
        SMB::Symbol *arg2 = symbol_table->findSymbol(arg2_node->getContent());
        temp = new Quaternion(op, arg1, arg2, result);
    }
    else if (arg1_node->getASTNodeType() == AST::literal 
          && arg2_node->getASTNodeType() == AST::op)
    {
        int arg1 = std::stoi(arg1_node->getContent());
        SMB::Symbol *arg2 = generateOperator((AST::OperatorNode *)arg2_node, symbol_table);
        temp = new Quaternion(op, arg1, arg2, result);
    }
    else if (arg1_node->getASTNodeType() == AST::literal 
          && arg2_node->getASTNodeType() == AST::literal)
    {
        int arg1 = std::stoi(arg1_node->getContent());
        int arg2 = std::stoi(arg2_node->getContent());
        temp = new Quaternion(op, arg1, arg2, result);
    } else {
        std::cout << "\033[31mError: \033[0m"
                  << "No match type for" << (int)arg1_node->getASTNodeType() << "  Content:" << arg1_node->getContent() << std::endl;
        exit(1);
    }
    return temp;
}

void IM::InterMediate::relopOperator(Quaternion *true_quad, 
                                     Quaternion *false_quad, 
                                     OperatorCode op, 
                                     AST::BaseNode *arg1_node, 
                                     AST::BaseNode *arg2_node, 
                                     SMB::SymbolTable *symbol_table)
{
    if (arg1_node->getASTNodeType() == AST::assign_var 
     && arg2_node->getASTNodeType() == AST::assign_var)
    {
        true_quad = new Quaternion(op, symbol_table->findSymbol(arg1_node->getContent()), 
                                                              symbol_table->findSymbol(arg2_node->getContent()), 
                                                              (int)NULL);
        false_quad = new Quaternion(IM::JUMP, (int)NULL);
    }
    else if (arg1_node->getASTNodeType() == AST::assign_var 
          && arg2_node->getASTNodeType() == AST::literal)
    {
        true_quad = new Quaternion(op, 
                                  symbol_table->findSymbol(arg1_node->getContent()), 
                                  std::stoi(arg2_node->getContent()), 
                                  (int)NULL);
        false_quad = new Quaternion(IM::JUMP, (int)NULL);
    }
    else if (arg1_node->getASTNodeType() == AST::literal 
          && arg2_node->getASTNodeType() == AST::assign_var)
    {
        true_quad = new Quaternion(op, 
                                  std::stoi(arg1_node->getContent()), 
                                  symbol_table->findSymbol(arg2_node->getContent()), 
                                  (int)NULL);
        false_quad = new Quaternion(IM::JUMP, (int)NULL);
    }
    else if (arg1_node->getASTNodeType() == AST::literal 
          && arg2_node->getASTNodeType() == AST::literal)
    {
        true_quad = new Quaternion(op, 
                                  std::stoi(arg1_node->getContent()), 
                                  std::stoi(arg2_node->getContent()), 
                                  (int)NULL);
        false_quad = new Quaternion(IM::JUMP, (int)NULL);
    }
    std::list<int> trueL; // Use size to get the index of true quad will be pushed
    trueL.push_back(quads.size());
    this->quads.push_back(*true_quad);
    std::list<int> falseL; // Same as the upper one
    falseL.push_back(quads.size());
    this->quads.push_back(*false_quad);
    std::cout << "true_list add\n";
    true_list.push(trueL);
    false_list.push(falseL);
    return;
}

std::list<int> *IM::InterMediate::makeList(int index) {
    std::list<int> *jump_list = new std::list<int>();
    jump_list->push_back(index);
    return jump_list;
}
std::list<int> *IM::InterMediate::merge(std::list<int> *list1, std::list<int> *list2) {
    list1->merge(*list2);
    return list1;
}
void IM::InterMediate::backPatch(std::list<int> *backList, int target) {
    std::list<int>::iterator it;
    for (it = backList->begin(); it != backList->end(); it++) {
        quads[*it].backPatch(target);
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