#ifndef BASENODE_H
#define BASENODE_H

#include <iostream>
#include <string>
#include <vector>

namespace AST {

    enum ASTNodeType {
        root = 0,
    };

    std::string prefix[2] = {"`- ", "|- "};
    std::string separator[2] = {"|  ", "   "};

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
        BaseNode();
        BaseNode(ASTNodeType);
        BaseNode(char*, ASTNodeType);
        BaseNode(char*);
        inline void setParent(BaseNode *parent) { this->parent = parent; }
        void addChild(BaseNode*);
        void addCousin(BaseNode*);
        BaseNode *getFinalCousinNode();
        void printTree();
        inline std::string getContent() { return this->content; }
        void printInfo(int);
    };

}

#endif
