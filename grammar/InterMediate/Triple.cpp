#include "./Triple.h"

std::vector<IM::BaseTriple*> IM::BaseTriple::all_args;

IM::BaseTriple::BaseTriple(OperatorType op) {
    this->op = op;
}

void IM::BaseTriple::pushBack(BaseTriple *triple) {
    triple->setIndex((int) all_args.size());
    all_args.push_back(triple);
}

IM::Arg::Arg() : BaseTriple(IM::NONE) {}

IM::Arg::Arg(SMB::Symbol *symbol) : BaseTriple(IM::NONE) {
    this->symbol = symbol;
}

IM::Triple::Triple(OperatorType op) : BaseTriple(op) {}

IM::Triple::Triple(OperatorType op, BaseTriple *arg1, BaseTriple *arg2) 
    :  BaseTriple(op) 
{
    this->setArg1(arg1);
    this->setArg2(arg2);
}
