#if !defined(_LITERALNODE_H_)
#define _LITERALNODE_H_

#include "./BaseNode.h"
#include <string>

namespace AST {
    
    class LiteralNode: public BaseNode {
    public:
        LiteralNode();
        LiteralNode(std::string);
        int getValue();
        void printInfo(int);
    };

} // namespace ASD


#endif // _LITERALNODE_H_
