#ifndef _VARNODE_H_
#define _VARNODE_H_

#include "./BaseNode.h"

namespace AST {

    class DefineVarNode : public BaseNode {
    public:
        DefineVarNode();
        DefineVarNode(std::string);
        virtual void printInfo(int) override;
    };

    class AssignVarNode : public BaseNode {
    public:
        AssignVarNode();
        AssignVarNode(std::string);
        virtual void printInfo(int) override;
    };

} // namespace AST


#endif