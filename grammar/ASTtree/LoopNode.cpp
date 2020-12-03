#include "./LoopNode.h"

AST::LoopNode::LoopNode() : BaseNode(AST::loop) {}

AST::LoopNode::LoopNode(std::string content) : BaseNode(content, AST::loop) {}

AST::LoopNode::LoopNode(LoopType tp) : BaseNode(AST::loop) {
    this->loop_type = tp;
}

AST::LoopNode::LoopNode(std::string content, LoopType tp) : BaseNode(content, AST::loop) {
    this->loop_type = tp;
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
    std::cout << this->content;
}
