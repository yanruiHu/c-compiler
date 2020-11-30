#ifndef ASTNODE_H
#define ASTNODE_H

#include <iostream>
#include <string>
#include <vector>

enum ASTNodeType {
    root = 0,
};

std::string prefix[2] = {"└─ ", "├─ "};
std::string separator[2] = {"│  ", "   "};

class ASTNode {
private:
    ASTNodeType type;
    ASTNode *parent;
    ASTNode *cousin;
    ASTNode *child;

protected:
    std::string content;
    // static void tree(ASTNode*, int);
    static void tree(ASTNode*, int, bool, std::vector<bool>);

public:
    ASTNode();
    ASTNode(ASTNodeType);
    ASTNode(char*, ASTNodeType);
    ASTNode(char*);
    inline void setParent(ASTNode *parent) { this->parent = parent; }
    void addChild(ASTNode*);
    void addCousin(ASTNode*);
    ASTNode *getFinalCousinNode();
    void printTree();
    inline std::string getContent() { return this->content; }
    void printInfo(int);
};

class RootNode: public ASTNode {
public:
    RootNode();
    RootNode(char*);
};

#endif
