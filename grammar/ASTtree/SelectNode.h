#if !defined(_SELECTNODE_H_)
#define _SELECTNODE_H_

#include "./BaseNode.h"
#include <string>

namespace AST {
    
    enum SelectType {
        if_stmt = 0,
        else_stmt = 1,
        // else_if_stmt = 2
    };

    class SelectNode: public BaseNode {
    private: 
        SelectType select_type;
    public:
        SelectNode();
        SelectNode(std::string);
        SelectNode(SelectType);
        SelectNode(std::string, SelectType);
        virtual void printInfo(int) override;
    };

} // namespace AST


#endif // _SELECTNODE_H_
