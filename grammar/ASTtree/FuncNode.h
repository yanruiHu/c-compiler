#if !defined(_FUNCNODE_H_)
#define _FUNCNODE_H_

#include "./BaseNode.h"
#include "../symbol/SymbolType.h"
#include <string>

namespace AST {
    
    class DefineFuncNode: public BaseNode {
    private:
        BaseNode* arg_list; // 参数列表
        STE::SymbolType return_symbol_type; // 返回值symbol类型
    public:
        DefineFuncNode();
        DefineFuncNode(std::string);
        inline BaseNode* getArgList() {return this->arg_list;}
        void setReturnSymbolType(std::string);
        virtual void printInfo(int) override;
    };

    class CallFuncNode: public BaseNode {
    private:
        BaseNode *var_list; // 参数列表
    public:
        CallFuncNode();
        CallFuncNode(std::string);
        inline void setVarList(BaseNode *v) {this->var_list = v;}
        inline BaseNode* getVarList() {return this->var_list;}
        virtual void printInfo(int) override;
    };

} // namespace AST


#endif // _FUNCNODE_H_
