#if !defined(_LOOPNODE_H_)
#define _LOOPNODE_H_

#include "./BaseNode.h"
#include <string>

namespace AST {

    enum LoopType {
        for_loop = 0,
        while_loop = 1
    };

    class LoopNode: public BaseNode {
    private:
        LoopType loop_type;
        
    public:
        LoopNode();
        LoopNode(std::string);
        LoopNode(LoopType);
        LoopNode(std::string, LoopType);
        virtual void printInfo(int) override;
    };
    
} // namespace AST


#endif // _LOOPNODE_H_
