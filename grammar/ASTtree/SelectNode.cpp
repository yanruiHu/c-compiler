#include "./SelectNode.h"

AST::SelectNode::SelectNode() : BaseNode(AST::select) {}

AST::SelectNode::SelectNode(std::string content) : BaseNode(content, AST::select) {}

AST::SelectNode::SelectNode(SelectType select_type) : BaseNode(AST::select) {
    this->select_type = select_type;
}

AST::SelectNode::SelectNode(std::string content, SelectType select_type) : BaseNode(content, AST::select) {
    this->select_type = select_type;
}

// if / else if
AST::SelectNode::SelectNode(std::string content, SelectType select_type, BaseNode* cond, BaseNode* body)
    : BaseNode(content, AST::select) {
    this->select_type = select_type;
    this->cond = cond;
    this->body = body;
}

// else
AST::SelectNode::SelectNode(std::string content, SelectType select_type, BaseNode* body)
    : BaseNode(content, AST::select) {
    this->select_type = select_type;
    this->body = body;
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
