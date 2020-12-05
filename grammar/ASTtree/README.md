# ASTTree

[TOC]

## ASTNodeType

枚举类：**节点类型**

```cpp
root = 0,			// 根节点，程序开始
def_var = 1,		// 定义变量（普通变量、数组、结构体）
assign_var = 2,		// 调用变量
def_func = 3,		// 定义函数
call_func = 4,		// 调用函数
op = 5,			    // 操作符
stmt = 6,			// 语句类型
loop = 7,			// 循环类型（for while）
select = 8,			// 选择类型（if else）
literal = 9,		// 字面量
```



## BaseNode

节点类的祖先类

```cpp
BaseNode();
BaseNode(ASTNodeType);				// 只传入节点类型
BaseNode(std::string, ASTNodeType);	 // 传入节点内容和节点类型
BaseNode(std::string);				// 只传入节点内容

// setters: 
void setParentNode(BaseNode *parent);	 // 设置父节点
void addChildNode(BaseNode*);			// 设置子节点
void addCousinNode(BaseNode*);			// 设置兄弟节点

// getters:
BaseNode *getFinalCousinNode();			// 返回最后的兄弟节点
ASTNodeType getASTNodeType();			// 返回节点类型
std::string getContent();				// 返回节点内容 
BaseNode* getChildNode();				// 返回子节点
BaseNode* getParentNode();				// 返回父节点
BaseNode* getCousinNode();				// 返回邻近的兄弟节点

// printers:
void printTree();						// 输出以当前节点为根节点的子树
virtual void printInfo(int);			 // 输出节点信息（不同类型节点的信息不同）
```



## DefineVarNode

定义变量的节点

```cpp
DefineVarNode();
DefineVarNode(std::string, std::string);      // 结构体变量构造函数，传入1.结构体变量名作为节点内容 2.结构体名
DefineVarNode(std::string); 				// 普通变量构造函数，只传入变量名作为节点内容

SMB::SymbolType getSymbolType();			// 返回变量symbol类型（int、void、int ptr、struct、array）
std::string getStructName();				// 返回结构体名字
int getArrayLength();						// 返回数组长度

void setTypeToArray();						// 设置该节点的symbol类型为数组（array）
void setAllSymbolType(std::string);			// 设置该节点及其兄弟节点的symbol类型（int、void、int ptr、struct、array）
void setArrayLength(std::string);			// 设置数组长度
virtual void printInfo(int) override;		// 输出变量名（若是数组，还会输出数组长度）
```



## AssignVarNode

调用变量的节点

```cpp
AssignVarNode();
AssignVarNode(std::string);				// 传入节点内容
virtual void printInfo(int) override;	 // 输出节点内容
```



## LiteralNode

字面量节点

```cpp
LiteralNode();
LiteralNode(std::string);				// 传入字面量的值作为节点内容
int getValue();
virtual void printInfo(int) override;	 // 输出字面量的值
```



## DefineFuncNode

定义函数的节点

```cpp
DefineFuncNode();
DefineFuncNode(std::string);			// 传入函数名作为节点内容
DefineFuncNode(std::string, BaseNode*);	 // 传入1.函数名作为节点内容 2.参数节点列表的头指针
BaseNode* getArgList();					// 返回参数节点列表的头指针
SMB::SymbolType getReturnSymbolType();	 // 返回返回值的symbol类型（int、void、int ptr）
void setReturnSymbolType(std::string);	 // 设置返回值的symbolsymbol类型（int、void、int ptr）
virtual void printInfo(int) override;	 // 输出函数名
```



## CallFuncNode

调用函数的节点

```cpp
CallFuncNode();
CallFuncNode(std::string);				 // 传入函数名作为节点内容
void setVarList(BaseNode *v);   		 // 设置参数节点列表，传入参数节点列表的头指针
BaseNode* getVarList();					// 返回参数列表的头指针
virtual void printInfo(int) override;	 // 输出函数名
```



## LoopNode

循环（for、while）节点

```cpp
LoopNode();
LoopNode(std::string);
LoopNode(LoopType);
LoopNode(std::string, LoopType);
LoopNode(std::string, LoopType, BaseNode*);	// while循环，传入1.节点内容 2.循环类型（LoopType::while_loop） 3.条件节点
LoopNode(std::string, LoopType, BaseNode*, BaseNode*, BaseNode*);// for循环，传入
// 1.节点内容 
// 2.循环类型（LoopType::for_loop）
// 3.条件节点（for循环第二句）
// 4.定义节点（for循环第一句）
// 5.动作节点（for循环第三句）

BaseNode *getDecNode();					// 返回定义节点
BaseNode *getCondNode();				// 返回条件节点
BaseNode *getActionNode();				// 返回动作节点
virtual void printInfo(int) override;	 // 输出节点内容
```



## OperatorNode

操作符节点

```cpp
// 操作符枚举类
enum OperatorType {
    none = 0,   	// 未设置
    add = 1,    	// +
    minus = 2,  	// -
    multi = 3,  	// *
    div = 4,    	// /
    pow = 5,    	// ^
    and_op = 6, 	// &&
    or_op = 7,  	// ||
    eq = 8,     	// ==
    not_op = 9, 	// !
    negative = 10,   // -
    relop = 11, 	// =
    mod = 12,   	// %
    get_adress = 13 // &
};
```

```cpp
OperatorNode();
OperatorNode(std::string);					// 传入操作符名作为节点内容
OperatorNode(std::string, OperatorType);	 // 传入1.操作符名 2.操作符类型
OperatorType getOpType();					// 返回操作符类型
virtual void printInfo(int) override;		 // 输出节点内容
```



## SelectNode

选择类型节点（if else）

```cpp
// 选择类型枚举类
enum SelectType {
    if_stmt = 0,
    else_stmt = 1,
    else_if_stmt = 2
};
```

```cpp
SelectNode();
SelectNode(std::string);									// 传入节点内容
SelectNode(SelectType);										// 传入选择类型
SelectNode(std::string, SelectType);						 // 传入1.节点内容 2.选择类型
SelectNode(std::string, SelectType, BaseNode*, BaseNode*);		// if / else if 传入
// 1.节点内容 
// 2.选择类型 
// 3.条件节点 
// 4.body节点

SelectNode(std::string, SelectType, BaseNode*);				  // else 传入1.节点内容 2.选择类型 3.body节点
SelectType getSelectType();									// 返回节点的选择类型
BaseNode* getCondNode();									// 返回条件节点
BaseNode* getBodyNode();									// 返回body节点
virtual void printInfo(int) override;						 // 输出节点信息
```



## StatementNode

语句类型节点

```cpp
// 语句类型枚举类
enum StatementType {
    compoundation = 0,	// 语句块
    comparation = 1,	// 比较语句
    defination = 2,		// 定义语句
    return_stmt = 3,	// 返回语句
    expression = 4		// 表达式语句
};
```

```cpp
StatementNode();
StatementNode(StatementType);				// 传入语句类型
StatementNode(std::string);					// 传入节点内容
StatementNode(std::string, StatementType);	 // 传入1.节点内容 2.语句类型
StatementType getStmtType();				// 返回语句类型
virtual void printInfo(int) override; 		 // 输出节点信息
```

