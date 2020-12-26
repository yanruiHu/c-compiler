#include "./OperatorNode.h"
#include "./VarNode.h"

AST::OperatorNode::OperatorNode() : BaseNode(AST::op) {}

AST::OperatorNode::OperatorNode(std::string content) : BaseNode(content, AST::op) {
    this->op_type = AST::none;
}

AST::OperatorNode::OperatorNode(std::string content, OperatorType op_type)
    : BaseNode(content, AST::op) {
        this->op_type = op_type;
}

void AST::OperatorNode::printInfo(int) {
    std::cout << "operator: " << this->content;
}

void AST::OperatorNode::setAllSymbolType(std::string tp) {
    AST::BaseNode *c = this->getChildNode();
    if (c->getASTNodeType() == AST::def_var) {
        AST::DefineVarNode *tmp = (AST::DefineVarNode*)c;
        tmp->setAllSymbolType(tp);
    }
    AST::BaseNode *cousin = this->getCousinNode();
    if (cousin->getASTNodeType() == AST::op) {
        AST::OperatorNode *tmp = (AST::OperatorNode*)cousin;
        tmp->setAllSymbolType(tp);
    }
}
