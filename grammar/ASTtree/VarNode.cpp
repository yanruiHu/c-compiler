#include "./VarNode.h"

AST::DeclareVarNode::DeclareVarNode() : BaseNode(dec_var) {
    this->var_type = SMB::none;
}

AST::DeclareVarNode::DeclareVarNode(char* content) : BaseNode(content, dec_var) {
    this->var_type = SMB::none;
}

void AST::DeclareVarNode::print_info(int) {
    std::cout << "Variable Declaration: ";
    switch (this->var_type) {
    case SMB::none:
        std::cout << "none type ";
        break;
    case SMB::array:
        std::cout << "array type ";
        break;
    case SMB::integer:
        std::cout << "integer type ";
        break;
    case SMB::struct_type:
        std::cout << "struct type(" << this->struct_name << ") ";
        break;
    case SMB::pointer:
        std::cout << "ptr type ";
        break;
    default:
        std::cout << "sth wrong! ";
        break;
    }
    std::cout << this->content << std::endl;
}