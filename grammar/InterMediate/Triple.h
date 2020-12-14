#if !defined(_TRIPLE_H_)
#define _TRIPLE_H_

#include "../symbol/symbol.h"
#include <vector>

namespace IM {

    enum OperatorType {
        NONE,
        JUMP,
        JUMP_SMALL,
        JUMP_EQ_SMALL,
        JUMP_GREAT,
        JUMP_EQ_GREAT,
        JUMP_EQUAL,
        JUMP_NOT_EQUAL,
        PLUS,
        MINUS,
        TIMES,
        DIV,
        MOD,
        POWER,
        NEGATIVE,
        ASSIGN,
        ASSIGN_ARRAY,
        ASSIGN_STRUCT,
        ASSIGN_POINTER,
        GET_ADDRESS,
        PARAM,
        CALL,
        RETURN,
        FUNC_DEF,
        END_FUNCTION,
        LABEL,
        GET_VALUE,
        GET_ARRAY,
        GET_STRUCT
    };

    class BaseTriple {
    protected:
        static std::vector<BaseTriple*> all_args;
        OperatorType op;    // None 表示读取 symbol, 即当前类型为 Arg
        int index;          // 三元式在all_args的坐标
    public:
        BaseTriple(OperatorType);
        inline OperatorType getOperatorType() { return this->op; }
        inline void setOperatorType(OperatorType op) { this->op = op; }
        inline int getIndex() { return this->index; }
        inline void setIndex(int index) { this->index = index; }
        static void pushBack(BaseTriple *triple);
    };

    class Arg : public BaseTriple {
    private:
        SMB::Symbol *symbol;
    public:
        Arg();
        Arg(SMB::Symbol*);
        inline SMB::Symbol *getSymbol() { return this->symbol; }
        inline void setSymbol(SMB::Symbol *symbol) { this->symbol = symbol; }
    };

    class Triple : public BaseTriple {
    private:
        int arg1;  // 三元式的参数 
        int arg2;
    public: 
        Triple(OperatorType);
        Triple(OperatorType, BaseTriple*, BaseTriple*);
        inline BaseTriple *getArg1() { return this->all_args[this->arg1]; }
        inline BaseTriple *getArg2() { return this->all_args[this->arg2]; }
        inline void setArg1(BaseTriple *arg1) { this->arg1 = arg1->getIndex(); }
        inline void setArg2(BaseTriple *arg2) { this->arg2 = arg2->getIndex(); }
    };
    
} // namespace IM


#endif // _TRIPLE_H_
