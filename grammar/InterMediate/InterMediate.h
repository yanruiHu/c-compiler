#if !defined(_INTERMEDIATE_H_)
#define _INTERMEDIATE_H_

#include "./Triple.h"
#include "../Nodes.h"
#include "../symbol/symbol.h"
#include <stack>
#include <list>

namespace IM {

    class InterMediate {
    private:
        AST::BaseNode *root_node;
        // SMB::SymbolTable *symbol_table;

        // bool expr
        std::stack< std::list<int> > true_list;
        std::stack< std::list<int> > false_list;

        // makelist, merge, backpatch
        

    public:
        InterMediate(AST::BaseNode*);
        // InterMediate(AST::BaseNode*, SMB::SymbolTable*);
        void generate(AST::BaseNode*);
        
    };

} // namespace IM


#endif // _INTERMEDIATE_H_
