#include "./LiteralNode.h"

AST::LiteralNode::LiteralNode() : BaseNode(AST::literal) {}

AST::LiteralNode::LiteralNode(std::string content) : BaseNode(content, AST::literal) {}

void AST::LiteralNode::printInfo(int) {
    std::cout << "literal: " << this->content;
}
