#if !defined(_STATEMENTNODE_H_)
#define _STATEMENTNODE_H_

#include "./BaseNode.h"
#include <string>

namespace AST {

    enum StatementType {
        compoundation = 0,
        comparation = 1,
        defination = 2,
        return_stmt = 3,
        expression = 4
    };

    class StatementNode: public BaseNode {
    private:
        StatementType stmt_type;

    public:
        StatementNode();
        StatementNode(StatementType);
        StatementNode(std::string);
        StatementNode(std::string, StatementType);
        inline StatementType getStmtType() {return this->stmt_type;}
        virtual void printInfo(int) override; 
    };

} // namespace AST


#endif // _STATEMENTNODE_H_
