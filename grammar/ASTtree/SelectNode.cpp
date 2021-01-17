#include "./SelectNode.h"

AST::SelectNode::SelectNode() : BaseNode(AST::select) {
    this->body = NULL;
    this->cond = NULL;
}

AST::SelectNode::SelectNode(std::string content) : BaseNode(content, AST::select) {
    this->body = NULL;
    this->cond = NULL;
}

AST::SelectNode::SelectNode(SelectType select_type) : BaseNode(AST::select) {
    this->select_type = select_type;
    this->body = NULL;
    this->cond = NULL;
}

AST::SelectNode::SelectNode(std::string content, SelectType select_type) : BaseNode(content, AST::select) {
    this->select_type = select_type;
    this->body = NULL;
    this->cond = NULL;
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
    this->cond = NULL;
}

void AST::SelectNode::printInfo(int) {
    switch (this->select_type) {
    case if_stmt:
        std::cout << "select statement(if): ";
        break;
    case else_stmt:
        std::cout << "select statement(else): ";
        break;
    case else_if_stmt:
        std::cout << "select statement(else if): ";
        break;
    }
    std::cout << this->content;
}

AST::SelectNode::~SelectNode() {
    if (cond) delete cond;
    if (body) delete body;
}
