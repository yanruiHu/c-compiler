#include "SymbolTableTree.h"

void SMB::tree(SMB::SymbolTable* table, AST::BaseNode* node, int depth){
    if (!node) return;
    if (node->getASTNodeType() == AST::ASTNodeType::def_var){
        std::cout << "in tree symbol\n";
        if(table->addSymbol(node) == 0){
            std::cout << "\033[31mError: \033[0m"
              << "value " << node->getContent() << " is redeclaration" << std::endl;
            exit(1);
        }
    } else if (node->getASTNodeType() == AST::def_func){
        SMB::FuncSymbol* func_node = new SMB::FuncSymbol(node);
        if (table->addFuncSymbol(func_node) == 0){
            std::cout << "\033[31mError: \033[0m"
              << "function " << func_node->getDecName() << " is redeclaration" << std::endl;
            exit(1);
        } else {
            SMB::SymbolTable* child_table = table->createChildTable();
            child_table->addFromFunctionArgs(func_node);
            tree(child_table,node->getChildNode(), depth + 1);
            tree(table,node->getCousinNode(), depth);
            return;
        }
    } else if (node->getASTNodeType() == AST::select) {
        SMB::SymbolTable* child_table = table->createChildTable();
        tree(child_table,node->getChildNode(), depth + 1);
        tree(table,node->getCousinNode(), depth);
        return;
    } else if (node->getASTNodeType() == AST::loop) {
        AST::LoopNode *loop_node = (AST::LoopNode*) node;
        SMB::SymbolTable* child_table = table->createChildTable();
        if (loop_node->getDecNode()) {
            child_table->addSymbol(loop_node->getDecNode());
        }
        tree(child_table,node->getChildNode(), depth + 1);
        tree(table,node->getCousinNode(), depth);
    }
    tree(table,node->getChildNode(), depth + 1);
    tree(table,node->getCousinNode(), depth);
}