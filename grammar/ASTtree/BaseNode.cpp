#include "./BaseNode.h"

AST::BaseNode::BaseNode() {
    this->child = NULL;
    this->parent = NULL;
    this->cousin = NULL;
    this->content = "code start!";
}

AST::BaseNode::BaseNode(std::string content) {
    this->child = NULL;
    this->parent = NULL;
    this->cousin = NULL;
    this->content = content;
}

AST::BaseNode::BaseNode(ASTNodeType type) {
    this->child = NULL;
    this->parent = NULL;
    this->cousin = NULL;
    this->type = type;
    this->content = "code start!";
}

AST::BaseNode::BaseNode(std::string content, ASTNodeType type) {
    this->child = NULL;
    this->parent = NULL;
    this->cousin = NULL;
    this->type = type;
    this->content = content;
}

void AST::BaseNode::addCousinNode(AST::BaseNode* node) {
    this->cousin = node;
    if (node) {
        node->parent = this->parent;
    }
}

void AST::BaseNode::addChildNode(AST::BaseNode* node) {
    this->child = node;
    while(node) {
        node->parent = this;
        node = node->cousin;
    }
}

void AST::BaseNode::printInfo(int depth) {
    while(depth) {
        std::cout << "   ";
        depth--;
    }
    std::cout << this->content << std::endl;
}

void AST::BaseNode::tree(AST::BaseNode* node, int depth, bool flag, std::vector<bool> pre_sep) {
    std::cout << prefix[!flag] << node->content << std::endl;
    ++depth;
    pre_sep.push_back(flag);

    node = node->child;
    while(node) {
        for (std::vector<bool>::iterator i = pre_sep.begin(); i != pre_sep.end(); i++) {
            std::cout << separator[*i];
        }
        AST::BaseNode* temp = node->child;
        if (!temp) {
            bool f = node->cousin;
            std::cout << prefix[f] << node->content << std::endl;
        } else {
            bool f = node->cousin;
            std::vector<bool> v(pre_sep);
            AST::BaseNode::tree(node, depth, !f, v);
        }
        node = node->cousin;
    }
}

void AST::BaseNode::tree(AST::BaseNode* node, int depth) {
    if (!node) return;
    node->printInfo(depth);
    AST::BaseNode::tree(node->child, depth + 1);
    AST::BaseNode::tree(node->cousin, depth);
}

void AST::BaseNode::printTree() {
    // AST::BaseNode::tree(this, 0);
    std::vector<bool> v(0);
    AST::BaseNode::tree(this, 1, true, v);
}

AST::BaseNode *AST::BaseNode::getFinalCousinNode() {
    AST::BaseNode *node = this;
    while(node->cousin) {
        node = node->cousin;
    }
    return node;
}

AST::BaseNode::~BaseNode() {
    if (this->cousin) {
        delete this->cousin;
    }
    if (this->child) {
        delete this->child;
    }
}

// // for test
// int main() {
//     AST::BaseNode* r[11];
//     for (int i = 0; i < 11; i++) {
//         char* a = (char*)malloc(sizeof(char) * 5);
//         sprintf(a, "%d", i + 1);
//         r[i] = new AST::BaseNode(a);
//     }
//     r[0]->addChild(r[1]);
//     r[1]->addChild(r[2]);
//     r[1]->addCousin(r[3]);
//     r[3]->addChild(r[4]);
//     r[3]->addCousin(r[5]);
//     r[5]->addChild(r[6]);
//     r[5]->addCousin(r[9]);
//     r[4]->addCousin(r[7]);
//     r[7]->addChild(r[8]);
//     r[6]->addCousin(r[10]);
//     r[0]->printTree();
//     return 0;
// }
