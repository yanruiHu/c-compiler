#include "./OperatorNode.h"

AST::OperatorNode::OperatorNode() : BaseNode(AST::op) {}

AST::OperatorNode::OperatorNode(std::string content) : BaseNode(content, AST::op) {
    this->op_type = OperatorType::none;
}

AST::OperatorNode::OperatorNode(std::string content, OperatorType op_type)
    : BaseNode(content, AST::op) {
        this->op_type = op_type;
}

void AST::OperatorNode::printInfo(int) {
    std::cout << "operator: " << this->content;
}
