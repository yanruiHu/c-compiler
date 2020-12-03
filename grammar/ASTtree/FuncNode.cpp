#include "./FuncNode.h"

AST::DefineFuncNode::DefineFuncNode() : BaseNode(AST::def_func) {}

AST::DefineFuncNode::DefineFuncNode(std::string content) : BaseNode(content, AST::def_func) {}

void AST::DefineFuncNode::printInfo(int) {
    std::cout << "function defination: " << this->content;
}

AST::CallFuncNode::CallFuncNode() : BaseNode(AST::call_func) {}

AST::CallFuncNode::CallFuncNode(std::string content) : BaseNode(content, AST::call_func) {}

void AST::CallFuncNode::printInfo(int) {
    std::cout << "call function: " << this->content;
}

