#include "./LoopNode.h"

AST::LoopNode::LoopNode() : BaseNode(AST::loop) {
    this->cond = NULL;
    this->dec = NULL;
    this->action = NULL;
}

AST::LoopNode::LoopNode(std::string content) : BaseNode(content, AST::loop) {
    this->cond = NULL;
    this->dec = NULL;
    this->action = NULL;
}

AST::LoopNode::LoopNode(LoopType tp) : BaseNode(AST::loop) {
    this->cond = NULL;
    this->dec = NULL;
    this->action = NULL;
    this->loop_type = tp;
}

AST::LoopNode::LoopNode(std::string content, LoopType tp) : BaseNode(content, AST::loop) {
    this->cond = NULL;
    this->dec = NULL;
    this->action = NULL;
    this->loop_type = tp;
}

// while循环
AST::LoopNode::LoopNode(std::string content,
                        LoopType loop_type,
                        BaseNode *condition)
    : BaseNode(content, AST::loop) {
    this->loop_type = loop_type;
    this->cond = condition;
    condition->setParentNode(this);
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
    cond->setParentNode(this);
    this->dec = dec;
    dec->setParentNode(this);
    this->action = action;
    action->setParentNode(this);
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

AST::LoopNode::~LoopNode() {
    if (dec) delete dec;
    if (cond) delete cond;
    if (action) delete action;
}
