#include "./LoopNode.h"

AST::LoopNode::LoopNode() : BaseNode(AST::loop) {}

AST::LoopNode::LoopNode(std::string content) : BaseNode(content, AST::loop) {}

AST::LoopNode::LoopNode(LoopType tp) : BaseNode(AST::loop) {
    this->loop_type = tp;
}

AST::LoopNode::LoopNode(std::string content, LoopType tp) : BaseNode(content, AST::loop) {
    this->loop_type = tp;
}

// while循环
AST::LoopNode::LoopNode(std::string content,
                        LoopType loop_type,
                        BaseNode *condition)
    : BaseNode(content, AST::loop) {
    this->loop_type = loop_type;
    this->cond = condition;
    this->dec = NULL;
    this->action = NULL;
}

// for循环
AST::LoopNode::LoopNode(std::string content,
                        LoopType loop_type,
                        BaseNode* cond,
                        BaseNode* dec,
                        BaseNode* action)
    : BaseNode(content, AST::loop) {
    this->loop_type = loop_type;
    this->cond = cond;
    this->dec = dec;
    this->action = action;
}

void AST::LoopNode::printInfo(int) {
    switch (this->loop_type) {
    case while_loop:
        std::cout << "loop statement(while): ";
        break;
    case for_loop:
        std::cout << "loop statement(for): ";
        break;
    }
}
