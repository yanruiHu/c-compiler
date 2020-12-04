#include "SymbolTableTree.h"

void tree(SMB::SymbolTable* table, AST::BaseNode* node, int depth){
    if (!node) return;
        //node->printInfo(depth);
    if(node->getASTNodeType()==AST::ASTNodeType::def_var){
        table->addSymbol(node);
    }
    tree(table,node->getChildNode(), depth + 1);
    tree(table,node->getCousinNode(), depth);
}