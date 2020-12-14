#if !defined(_INTERMEDIATE_H_)
#define _INTERMEDIATE_H_

#include "./Triple.h"
#include "../Nodes.h"
#include "../symbol/symbol.h"

namespace IM {

    class InterMediate {
    private:
        AST::BaseNode *root_node;
        SMB::SymbolTable *symbol_table;

    public:
        InterMediate(AST::BaseNode*, SMB::SymbolTable*);
        void generate(AST::BaseNode*);
        
    };

} // namespace IM


#endif // _INTERMEDIATE_H_
