#include "./StatementNode.h"

AST::StatementNode::StatementNode() : BaseNode(AST::stmt) {}

AST::StatementNode::StatementNode(std::string content) : BaseNode(content, AST::stmt) {}

AST::StatementNode::StatementNode(StatementType tp) : BaseNode(AST::stmt) {
    this->stmt_type = tp;
}

AST::StatementNode::StatementNode(std::string content, StatementType tp) : BaseNode(content, AST::stmt) {
    this->stmt_type = tp;
}

void AST::StatementNode::printInfo(int) {
    switch (this->stmt_type) {
    case compoundation:
        std::cout << "compound statement: ";
        break;
    case comparation:
        std::cout << "compare statement: ";
        break;
    case return_stmt:
        std::cout << "return statement: ";
        break;
    case defination:
        std::cout << "define statement: ";
        break;
    case expression:
        std::cout << "expression: ";
        break;
    }
    std::cout << this->content;
}
