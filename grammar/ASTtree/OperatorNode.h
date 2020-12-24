#if !defined(_OPERATORNODE_H_)
#define _OPERATORNODE_H_

#include "./BaseNode.h"
#include <string>

namespace AST {

    enum OperatorType {
        none = 0,   // 未设置
        assign = 14,// =
        add = 1,    // +
        minus = 2,  // -
        multi = 3,  // *
        div = 4,    // /
        pow = 5,    // ^
        and_op = 6, // &&
        or_op = 7,  // ||
        // eq = 8,     // ==
        not_op = 9, // !
        negative = 10, // -
        relop = 11, // <=
        mod = 12,   // %
        get_adress = 13, // &
        get_var = 15,// *
        get_arr_var = 16, //[]
        get_member = 17, // a.b
        assign_arr = 18, // []=
        assign_member = 19, // a.b=
    };
    
    class OperatorNode: public BaseNode {
    private:
        OperatorType op_type;
    public:
        OperatorNode();
        OperatorNode(std::string);
        OperatorNode(std::string, OperatorType);
        inline OperatorType getOpType() {return this->op_type;}
        void printInfo(int);
    };

} // namespace AST


#endif // _OPERATORNODE_H_
