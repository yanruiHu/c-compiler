#include "./VarNode.h"

AST::DefineVarNode::DefineVarNode() : BaseNode(AST::def_var) {}

AST::DefineVarNode::DefineVarNode(std::string content) : BaseNode(content, AST::def_var) {}

void AST::DefineVarNode::printInfo(int) {
    std::cout << "variable defination: " << this->content;
}

AST::AssignVarNode::AssignVarNode() : BaseNode(AST::assign_var) {}

AST::AssignVarNode::AssignVarNode(std::string content) : BaseNode(content, AST::assign_var) {}

void AST::AssignVarNode::printInfo(int) {
    std::cout << "variable: " << this->content;
}
