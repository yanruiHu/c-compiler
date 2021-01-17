// #include "./InterMediate3.h"

// IM::InterMediate::InterMediate(AST::BaseNode *root) {
//     this->root_node = root;
//     this->triples = BaseTriple::getAllTriples();
// }

// IM::InterMediate::InterMediate(AST::BaseNode* root, SMB::SymbolTable* symbol) {
//     this->root_node = root;
//     this->symbol_table = symbol;
//     this->triples = BaseTriple::getAllTriples();
// }

// SMB::SymbolTable *IM::InterMediate::generateReturn(AST::StatementNode *node, SMB::SymbolTable *symbol_table) {
//     AST::BaseNode *child = node->getChildNode();
//     Triple *triple;
//     if (!child) {
//         // 直接 return
//         triple = new Triple(IM::RETURN);
//     } else if (child->getASTNodeType() == AST::literal) {
//         // return 字面量
//         int arg1 = std::stoi(child->getContent());
//         Arg *arg = new Arg(arg1);
//         BaseTriple::pushBack(arg);
//         triple = new Triple(IM::RETURN, arg, NULL);
//     } else if (child->getASTNodeType() == AST::assign_var) {
//         // return 变量
//         SMB::Symbol *arg1 = symbol_table->findSymbol(child->getContent());
//         Arg *arg = new Arg(arg1);
//         BaseTriple::pushBack(arg);
//         triple = new Triple(IM::RETURN, arg, NULL);
//     } else if (child->getASTNodeType() == AST::op) {
//         // ruturn a + b;
//         Arg *arg1 = this->generateOperator((AST::OperatorNode*)child, symbol_table);
//         triple = new Triple(IM::RETURN, arg1, NULL);
//     } else if (child->getASTNodeType() == AST::call_func) {
//         // return func(a);
//         generate(child, symbol_table);
//         BaseTriple *arg1 = triples.back();
//         triple = new Triple(IM::RETURN, arg1, NULL);
//     } else {
//         std::cout << "\033[31mError: \033[0m"
//                   << "Type error" << std::endl;
//         exit(1);
//     }
//     BaseTriple::pushBack(triple);
//     return symbol_table;
// } 

// IM::Arg* IM::InterMediate::generateOperator(AST::OperatorNode *node, SMB::SymbolTable *symbol_table) {
//     AST::BaseNode *arg1, *arg2;
//     Triple *triple;
//     switch (node->getOpType()) {
//     case AST::OperatorType::eq: {
        
//     }
//     }
// }

// std::list<int> *IM::InterMediate::makelist(int index) {
//     std::list<int> *temp_list = new std::list<int>();
//     temp_list->push_back(index);
//     return temp_list;
// }

// std::list<int> *IM::InterMediate::merge(std::list<int> *list1, std::list<int> *list2) {
//     list1->merge(*list2);
//     return list1;
// }

// void IM::InterMediate::backpatch(std::list<int> *backList, int target) {
//     std::list<int>::iterator it;
//     Arg *jump_target = new Arg(target);
//     BaseTriple::pushBack(jump_target);
//     for (it = backList->begin(); it != backList->end(); it++) {
//         Triple *t = (Triple*)triples[*it];
//         t->setArg1(jump_target);
//     }
//     return;
// }