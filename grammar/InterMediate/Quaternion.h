#if !defined(_QUATERNION_H_)
#define _QUATERNION_H_

#include "../symbol/symbol.h"
#include <string.h>

namespace IM {

enum OperatorCode
{
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
    GET_STRUCT,
    NONE
};

union Arg {
    SMB::Symbol *var;
    int literal;
};

class Quaternion {
private:
    OperatorCode op;
    // 0: arg1, 1: arg2, 2: result
    Arg args[3];
    std::string __str__();

public:
    inline Quaternion(OperatorCode op, int result) {
        this->op = op;
        this->args[2].literal = result;
    }
    inline Quaternion(OperatorCode op, SMB::Symbol* arg1, SMB::Symbol* result) {
        this->op = op;
        this->args[0].var = arg1;
        this->args[2].var = result;
    }
    inline Quaternion(OperatorCode op, int arg1, SMB::Symbol* result) {
        this->op = op;
        this->args[0].literal = arg1;
        this->args[2].var = result;
    }
    inline Quaternion(OperatorCode op, SMB::Symbol *arg1, SMB::Symbol *arg2, SMB::Symbol *result) {
        this->op = op;
        this->args[0].var = arg1;
        this->args[1].var = arg2;
        this->args[2].var = result;
    }
    inline Quaternion(OperatorCode op, int arg1, SMB::Symbol *arg2, SMB::Symbol *result) {
        this->op = op;
        this->args[0].literal = arg1;
        this->args[1].var = arg2;
        this->args[2].var = result;
    }
    inline Quaternion(OperatorCode op, SMB::Symbol *arg1, int arg2, SMB::Symbol *result) {
        this->op = op;
        this->args[0].var = arg1;
        this->args[1].literal = arg2;
        this->args[2].var = result;
    }
    inline Quaternion(OperatorCode op, int arg1, int arg2, SMB::Symbol *result) {
        this->op = op;
        this->args[0].literal = arg1;
        this->args[1].literal = arg2;
        this->args[2].var = result;
    }
    inline Quaternion(OperatorCode op, SMB::Symbol *arg1, SMB::Symbol *arg2, int result) {
        this->op = op;
        this->args[0].var = arg1;
        this->args[1].var = arg2;
        this->args[2].literal = result;
    }
    inline Quaternion(OperatorCode op, SMB::Symbol *arg1, int arg2, int result) {
        this->op = op;
        this->args[0].var = arg1;
        this->args[1].literal = arg2;
        this->args[2].literal = result;
    }
    inline Quaternion(OperatorCode op, int arg1, int arg2, int result) {
        this->op = op;
        this->args[0].literal = arg1;
        this->args[1].literal = arg2;
        this->args[2].literal = result;
    }

    inline void backPatch(int target) { this->args[2].literal = target; }
    inline bool getResult() { return this->args[2].literal == 0 ? true : false; }
    inline OperatorCode getOperator() { return this->op; }
    inline bool isSymbol() { return this->op != NONE; }
    inline Arg operator[](int index) { return this->args[index]; }
    void print();
};

}

#endif // _QUATERNION_H_
