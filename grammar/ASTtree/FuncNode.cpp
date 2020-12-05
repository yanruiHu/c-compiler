#include "./FuncNode.h"

#include "../symbol/SymbolType.h"
#include "./VarNode.h"

AST::DefineFuncNode::DefineFuncNode() : BaseNode(AST::def_func) {}

AST::DefineFuncNode::DefineFuncNode(std::string content) : BaseNode(content, AST::def_func) {}

AST::DefineFuncNode::DefineFuncNode(std::string content, BaseNode* arg_list) : BaseNode(content, AST::def_func) {
    this->arg_list = arg_list;
}

void AST::DefineFuncNode::setReturnSymbolType(std::string symbol_type) {
    if (symbol_type == "int") {
        this->return_symbol_type = SMB::SymbolType::integer;
    } else if (symbol_type == "void") {
        this->return_symbol_type = SMB::SymbolType::void_type;
    } else if (symbol_type == "int ptr") {
        this->return_symbol_type = SMB::SymbolType::pointer;
    }
}

void AST::DefineFuncNode::printInfo(int) {
    std::cout << "function defination: " << this->content;
    AST::BaseNode *args = arg_list;
    std::string str = ", args: ";
    while(args) {
        str += "(" + SMB::symbol_string[((DefineVarNode*)args)->getSymbolType()] + ")";
        str += args->getContent() + ", ";
        args = args->getCousinNode();
    }
    std::cout << str;
}

AST::CallFuncNode::CallFuncNode() : BaseNode(AST::call_func) {}

AST::CallFuncNode::CallFuncNode(std::string content) : BaseNode(content, AST::call_func) {}

void AST::CallFuncNode::printInfo(int) {
    std::cout << "call function: " << this->content;
    AST::BaseNode *args = var_list;
    std::string str = ", args: ";
    while(args) {
        str += args->getContent() + ", ";
        args = args->getCousinNode();
    }
    std::cout << str;
}

