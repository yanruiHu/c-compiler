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
        BaseNode *cond; // 条件，for循环中的第二句
        BaseNode *dec;  // for循环中的第一句
        BaseNode *action;   // for循环中的第三句
    public:
        LoopNode();
        LoopNode(std::string);
        LoopNode(LoopType);
        LoopNode(std::string, LoopType);
        // while循环
        LoopNode(std::string, LoopType, BaseNode*);
        // for循环
        LoopNode(std::string, LoopType, BaseNode*, BaseNode*, BaseNode*);
        inline BaseNode *getDecNode() { return this->dec; }
        inline BaseNode *getCondNode() { return this->cond; }
        inline BaseNode *getActionNode() { return this->action; }
        inline LoopType getLoopType() { return this->loop_type; }
        void printInfo(int);
        ~LoopNode();
    };
    
} // namespace AST


#endif // _LOOPNODE_H_
