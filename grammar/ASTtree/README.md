# ASTTree

- [ASTTree](#asttree)
  - [ASTNode](#astnode)

## ASTNode
```cpp
ASTNode::ASTNode();
ASTNode::ASTNode(ASTNodeType);          // 传参NodeType
ASTNode::ASTNode(char*, ASTNodeType);   // 传入content
ASTNode::ASTNode(char*);                // 只传入 content 用于测试
void ASTNode::setParent(ASTNode* node); // 设置当前节点的父节点
void ASTNode::addChild(ASTNode* node);  // 设置当前子节点
void ASTNode::addCousin(ASTNode* node); // 设置当前节点的兄弟节点
ASTNode *ASTNode::getFinalCousinNode(); // 返回最后的兄弟节点
void ASTNode::printTree();              // 输出以当前节点为根节点的子树
void ASTNode::printInfo(int);           // 输出content
```