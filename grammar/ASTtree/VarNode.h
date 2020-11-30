#ifndef _VARNODE_H_
#define _VARNODE_H_

#include "./BaseNode.h"
#include "../../lexical/symbol/symbol.h"

namespace AST {

    class VarNode : public BaseNode {
    private:
        SMB::SymbolType smb_type;       // type 名称被 ASTNodeType 占用

    public:

    };

} // namespace AST


#endif