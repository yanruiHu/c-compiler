#ifndef SYMBOLTABLETREE_H
#define SYMBOLTABLETREE_H

#include "./ASTtree/BaseNode.h"
#include "./ASTtree/LoopNode.h"
#include "./symbol/symbol.h"

namespace SMB {
    void tree(SymbolTable* table, AST::BaseNode* node, int depth);
} // namespace SMB


#endif