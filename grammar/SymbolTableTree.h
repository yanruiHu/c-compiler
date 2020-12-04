#ifndef SYMBOLTABLETREE_H
#define SYMBOLTABLETREE_H

#include "./ASTtree/BaseNode.h"
#include "./symbol/symbol.h"

void tree(SMB::SymbolTable* table, AST::BaseNode* node, int depth);

#endif