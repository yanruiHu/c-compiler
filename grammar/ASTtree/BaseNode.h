#ifndef _BASENODE_H_
#define _BASENODE_H_

#include <iostream>
#include <string>
#include <vector>

namespace AST {

    enum ASTNodeType {
        root_ = 0,
        dec_var = 1,
        assign_var = 2,
        dec_func = 3,
        call_func = 4,
        op = 5,
        stmt = 6,
        loop = 7, 
        //select = 8,
        literal = 9,        // unknown
    };

    static std::string prefix[2] = {"`- ", "|- "};
    static std::string separator[2] = {"|  ", "   "};

    class BaseNode {
    private:
        ASTNodeType type;
        BaseNode *parent;
        BaseNode *cousin;
        BaseNode *child;

    protected:
        std::string content;
        static void tree(BaseNode*, int);
        static void tree(BaseNode*, int, bool, std::vector<bool>);

    public:
        BaseNode();
        BaseNode(ASTNodeType);
        BaseNode(char*, ASTNodeType);
        BaseNode(char*);
        inline void setParentNode(BaseNode *parent) { this->parent = parent; }
        inline ASTNodeType getASTNodeType() { return this->type; }
        void addChildNode(BaseNode*);
        void addCousinNode(BaseNode*);
        BaseNode *getFinalCousinNode();
        void printTree();
        inline std::string getContent() { return this->content; }
        void printInfo(int);
    };

}

#endif
