#ifndef _FUNCNODE_H_
#define _FUNCNODE_H_

#include "./BaseNode.h"

namespace AST {
    class FuncNode : public BaseNode {
    private:
        BaseNode *args;
    public:
        void printInfo(int depth);
    };
} // namespace AST


#endif