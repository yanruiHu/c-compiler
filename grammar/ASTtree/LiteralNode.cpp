#include "./LiteralNode.h"

AST::LiteralNode::LiteralNode() : BaseNode(AST::literal) {}

AST::LiteralNode::LiteralNode(std::string content) : BaseNode(content, AST::literal) {}

int AST::LiteralNode::getValue()  {
    return std::stoi(this->content);
}

void AST::LiteralNode::printInfo(int) {
    std::cout << "literal: " << this->content;
}
