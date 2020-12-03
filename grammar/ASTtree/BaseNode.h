#ifndef _BASENODE_H_
#define _BASENODE_H_

#include <iostream>
#include <string>
#include <vector>

namespace AST {

    enum ASTNodeType {
        root = 0,
        def_var = 1,
        assign_var = 2,
        def_func = 3,
        call_func = 4,
        op = 5,
        stmt = 6,
        loop = 7,
        select = 8,
        literal = 9,
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
        // static void tree(BaseNode*, int);
        static void tree(BaseNode*, int, bool, std::vector<bool>);

    public:
        // constructors:
        BaseNode();
        BaseNode(ASTNodeType);
        BaseNode(std::string, ASTNodeType);
        BaseNode(std::string);

        // setters: 
        inline void setParentNode(BaseNode *parent) { this->parent = parent; }
        void addChildNode(BaseNode*);
        void addCousinNode(BaseNode*);
        
        // getters:
        BaseNode *getFinalCousinNode();
        inline ASTNodeType getASTNodeType() { return this->type; }
        inline std::string getContent() { return this->content; }
        inline BaseNode* getChildNode() { return this->child; }
        inline BaseNode* getParentNode() { return this->parent; }
        inline BaseNode* getCousinNode() { return this->cousin; }

        // printers:
        void printTree();
        virtual void printInfo(int);

        // deconstructor:
        ~BaseNode();
    };

}

#endif
