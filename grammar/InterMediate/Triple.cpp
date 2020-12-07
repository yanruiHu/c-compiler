#include "./Triple.h"

IM::BaseTriple::BaseTriple() { this->op = NONE; }

IM::BaseTriple::BaseTriple(OpCode op) { this->op = op; }

IM::Arg::Arg() : BaseTriple() {
    this->symbol = NULL;
}

IM::Arg::Arg(SMB::Symbol *symbol) : BaseTriple() {
    this->symbol = symbol;
}

IM::Triple::Triple() : BaseTriple() { 
    this->arg1 = NULL;
    this->arg2 = NULL;
    this->nxt = NULL;
}

IM::Triple::Triple(OpCode op) : BaseTriple(op) { 
    this->arg1 = NULL;
    this->arg2 = NULL;
    this->nxt = NULL;
}

IM::Triple::Triple(BaseTriple *arg1, BaseTriple *arg2) : BaseTriple() { 
    this->arg1 = arg1;
    this->arg2 = arg2;
    this->nxt = NULL;
}

IM::Triple::Triple(OpCode op, BaseTriple *arg1, BaseTriple *arg2) : BaseTriple(op) { 
    this->arg1 = arg1;
    this->arg2 = arg2;
    this->nxt = NULL;
}
