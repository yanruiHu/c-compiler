#ifndef _VARNODE_H_
#define _VARNODE_H_

#include "./BaseNode.h"
#include "../symbol/SymbolType.h"

namespace AST {

    class DefineVarNode : public BaseNode {
    private:
        STE::SymbolType symbol_type;    // 符号类型
        int array_length;
        std::string struct_name;    // 结构体名
    public:
        DefineVarNode();
        // DefineVarNode(std::string, BaseNode*);
        DefineVarNode(std::string, std::string);    // 结构体变量构造函数
        DefineVarNode(std::string); // 普通变量构造函数
        inline STE::SymbolType getSymbolType() {return this->symbol_type;}
        inline std::string getStructName() {return this->struct_name;}
        inline void setTypeToArray() {this->symbol_type = STE::SymbolType::array;}
        inline int getArrayLength() {return this->array_length;}
        void setAllSymbolType(std::string);
        void setArrayLength(std::string);
        virtual void printInfo(int) override;
    };

    class AssignVarNode : public BaseNode {
    public:
        AssignVarNode();
        AssignVarNode(std::string);
        virtual void printInfo(int) override;
    };

} // namespace AST


#endif