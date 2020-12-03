#include "./SelectNode.h"

AST::SelectNode::SelectNode() : BaseNode(AST::select) {}

AST::SelectNode::SelectNode(std::string content) : BaseNode(content, AST::select) {}

AST::SelectNode::SelectNode(SelectType tp) : BaseNode(AST::select) {
    this->select_type = tp;
}

AST::SelectNode::SelectNode(std::string content, SelectType tp) : BaseNode(content, AST::select) {
    this->select_type = tp;
}

void AST::SelectNode::printInfo(int) {
    switch (this->select_type) {
    case if_stmt:
        std::cout << "select statement(if): ";
        break;
    case else_stmt:
        std::cout << "select statement(else): ";
        break;
    }
    std::cout << this->content;
}
