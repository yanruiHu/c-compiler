#ifndef _VARNODE_H_
#define _VARNODE_H_

#include "./BaseNode.h"
#include "../../lexical/symbol/symbol.h"

namespace AST {

    class DeclareVarNode : public BaseNode {
    private:
        SMB::SymbolType var_type;       // type 字段被 ASTNodeType 占用
        int array_length;               // for array
        std::string struct_name;

    public:
        DeclareVarNode();
        DeclareVarNode(char*);
        void print_info(int);
    };

    class AssignVarNode : public BaseNode {

    };

} // namespace AST


#endif