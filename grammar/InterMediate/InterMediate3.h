// #if !defined(_INTERMEDIATE_H_)
// #define _INTERMEDIATE_H_

// #include "./Triple.h"
// #include "../Nodes.h"
// #include "../symbol/symbol.h"
// #include <stack>
// #include <list>

// namespace IM {

//     class InterMediate {
//     private:
//         AST::BaseNode *root_node;
//         SMB::SymbolTable *symbol_table;
//         std::vector<BaseTriple*> triples;
        
//         // bool expr
//         std::stack< std::list<int> > trueList;
//         std::stack< std::list<int> > falseList;

//         // func return
//         std::stack<int> signal;

//         // makelist, merge, backpatch
//         std::list<int> *makelist(int);
//         std::list<int> *merge(std::list<int>*, std::list<int>*);
//         void backpatch(std::list<int>*, int);

//     public:
//         InterMediate(AST::BaseNode*);
//         InterMediate(AST::BaseNode*, SMB::SymbolTable*);
//         void generate(AST::BaseNode*, SMB::SymbolTable*);
//         SMB::SymbolTable *generateStmt(AST::StatementNode*, SMB::SymbolTable*);
//         SMB::SymbolTable *generateReturn(AST::StatementNode*, SMB::SymbolTable*);
//         Arg *generateOperator(AST::OperatorNode*, SMB::SymbolTable*);
        
//     };

// } // namespace IM


// #endif // _INTERMEDIATE_H_
