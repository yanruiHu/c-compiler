#if !defined(_TRIPLE_H_)
#define _TRIPLE_H_

#include "../symbol/symbol.h"

namespace IM {

    enum OpCode {
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
    private:
        OpCode op;
    public:
        BaseTriple();
        BaseTriple(OpCode);
        inline OpCode getOperator() { return this->op; }
        inline void setOperator(OpCode op) { this->op = op; }
    };

    class Arg : public BaseTriple {
    private:
        SMB::Symbol *symbol;
    public:
        Arg();
        Arg(SMB::Symbol*);
        inline SMB::Symbol* getSymbol() { return this->symbol; }
        inline void setSymbol(SMB::Symbol *symbol) { this->symbol = symbol; }
    };

    class Triple : public BaseTriple {
    private:
        BaseTriple *arg1;
        BaseTriple *arg2;
        BaseTriple *nxt;
    public:
        Triple();
        Triple(OpCode);
        Triple(BaseTriple*, BaseTriple*);
        Triple(OpCode, BaseTriple*, BaseTriple*);
        inline BaseTriple* getNextTriple() { return this->nxt; }
        inline void setNextTriple(BaseTriple *nxt) { this->nxt = nxt; }
        inline BaseTriple* getArg1() { return this->arg1; }
        inline void setArg2(BaseTriple* arg1) { this->arg1 = arg1; }
        inline BaseTriple* getArg2() { return this->arg2; }
        inline void setArg2(BaseTriple* arg2) { this->arg2 = arg2; }
    };
    
} // namespace IM


#endif // _TRIPLE_H_
