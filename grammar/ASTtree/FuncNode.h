#if !defined(_FUNCNODE_H_)
#define _FUNCNODE_H_

#include "./BaseNode.h"
#include <string>

namespace AST {
    
    class DefineFuncNode: public BaseNode {
    public:
        DefineFuncNode();
        DefineFuncNode(std::string);
        virtual void printInfo(int) override;
    };

    class CallFuncNode: public BaseNode {
    public:
        CallFuncNode();
        CallFuncNode(std::string);
        virtual void printInfo(int) override;
    };

} // namespace AST


#endif // _FUNCNODE_H_
