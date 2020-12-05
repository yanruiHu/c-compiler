#include "SymbolTableTree.h"

void tree(SMB::SymbolTable* table, AST::BaseNode* node, int depth){
    if (!node) return;
    if(node->getASTNodeType()==AST::ASTNodeType::def_var){
        if(table->addSymbol(node)==0){
            std::cout << "\033[31mError: \033[0m"
              << "value " << node->getContent() << " is redeclaration" << std::endl;
            exit(1);
        }
    }else if(node->getASTNodeType()==AST::def_func){
        SMB::FuncSymbol* func_node = new SMB::FuncSymbol(node);
        if(table->addFuncSymbol(func_node)==0){
            std::cout << "\033[31mError: \033[0m"
              << "function " << func_node->getDecName() << " is redeclaration" << std::endl;
            exit(1);
        }else{
            SMB::SymbolTable* child_table = table->createChildTable();
            child_table->addFromFunctionArgs((AST::DefineFuncNode*) node);
            tree(child_table,node->getChildNode(), depth + 1);
            tree(table,node->getCousinNode(), depth);
            return;
        }
    }
    tree(table,node->getChildNode(), depth + 1);
    tree(table,node->getCousinNode(), depth);
}