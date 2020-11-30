#include "./ASTNode.h"

AST::ASTNode::ASTNode() {
    this->child = NULL;
    this->parent = NULL;
    this->cousin = NULL;
    this->content = "code start!";
}

AST::ASTNode::ASTNode(char* string) {
    this->child = NULL;
    this->parent = NULL;
    this->cousin = NULL;
    this->content = string;
}

AST::ASTNode::ASTNode(ASTNodeType type) {
    this->child = NULL;
    this->parent = NULL;
    this->cousin = NULL;
    this->type = type;
    this->content = "code start!";
}

AST::ASTNode::ASTNode(char* content, ASTNodeType type) {
    this->child = NULL;
    this->parent = NULL;
    this->cousin = NULL;
    this->type = type;
    this->content = content;
}

void AST::ASTNode::addCousin(ASTNode* node) {
    this->cousin = node;
    if (node) {
        node->parent = this->parent;
    }
}

void AST::ASTNode::addChild(ASTNode* node) {
    this->child = node;
    while(node) {
        node->parent = this;
        node = node->cousin;
    }
}

void AST::ASTNode::printInfo(int depth) {
    std::cout << this->content << std::endl;
}

void AST::ASTNode::tree(ASTNode* node, int depth, bool flag, std::vector<bool> pre_sep) {
    std::cout << AST::prefix[!flag] << node->content << std::endl;
    ++depth;
    pre_sep.push_back(flag);

    while(node) {
        for (std::vector<bool>::iterator i = pre_sep.begin(); i != pre_sep.end(); i++) {
            std::cout << AST::separator[*i];
        }
        ASTNode* temp = node->child;
        if (!temp) {
            bool f = node->cousin;
            std::cout << AST::prefix[f] << node->content << std::endl;
        } else {
            bool f = node->cousin;
            std::vector<bool> v(pre_sep);
            ASTNode::tree(temp, depth, !f, v);
        }
        node = node->cousin;
    }
}

// void ASTNode::tree(ASTNode* node, int depth) {
//     if (!node) return;
//     node->printInfo(depth);
//     ASTNode::tree(node->child, depth + 1);
//     ASTNode::tree(node->cousin, depth);
// }

void AST::ASTNode::printTree() {
    // ASTNode::tree(this, 0);
    std::vector<bool> v(0);
    ASTNode::tree(this, 1, true, v);
}

AST::ASTNode *AST::ASTNode::getFinalCousinNode() {
    ASTNode *node = this;
    while(node->cousin) {
        node = node->cousin;
    }
    return node;
}

AST::RootNode::RootNode() : ASTNode(ASTNodeType::root) {
    this->content = "root";
}

AST::RootNode::RootNode(char* string) : ASTNode(string) {}

int main() {
    AST::ASTNode* r[11];
    for (int i = 0; i < 11; i++) {
        char* a = (char*)malloc(sizeof(char) * 5);
        sprintf(a, "%d", i + 1);
        r[i] = new AST::RootNode(a);
    }
    r[0]->addChild(r[1]);
    r[1]->addChild(r[2]);
    r[1]->addCousin(r[3]);
    r[3]->addChild(r[4]);
    r[3]->addCousin(r[5]);
    r[5]->addChild(r[6]);
    r[5]->addCousin(r[9]);
    r[4]->addCousin(r[7]);
    r[7]->addChild(r[8]);
    r[6]->addCousin(r[10]);
    r[0]->printTree();
    return 0;
}
