#include "SymbolTableTree.h"

void tree(SMB::SymbolTable* table, AST::BaseNode* node, int depth){
    if (!node) return;
        //node->printInfo(depth);
    if(node->getASTNodeType()==AST::ASTNodeType::def_var){
        if(table->addSymbol(node)==0){
            std::cout << "\033[31mError: \033[0m"
              << "value " << node->getContent() << " is redeclaration" << std::endl;
            exit(1);
        }
    }
    tree(table,node->getChildNode(), depth + 1);
    tree(table,node->getCousinNode(), depth);
}