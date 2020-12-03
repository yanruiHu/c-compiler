#include "./OperatorNode.h"

AST::OperatorNode::OperatorNode() : BaseNode(AST::op) {}

AST::OperatorNode::OperatorNode(std::string content) : BaseNode(content, AST::op) {}

void AST::OperatorNode::printInfo(int) {
    std::cout << "operator: " << this->content;
}
