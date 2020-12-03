#if !defined(_OPERATORNODE_H_)
#define _OPERATORNODE_H_

#include "./BaseNode.h"
#include <string>

namespace AST {

    enum OperatorType {
        add = 0,
        minus = 1,
        multi = 2,
        div = 3,
        pow = 4,
        and_op = 5, 
        or_op = 6,
        eq = 7,
        not_op = 8,
        negative = 9,
        relop = 10,
        mod = 11,
    };
    
    class OperatorNode: public BaseNode {
    private:
        OperatorType op_type;
        
    public:
        OperatorNode();
        OperatorNode(std::string);
        virtual void printInfo(int) override;
    };

} // namespace AST


#endif // _OPERATORNODE_H_
