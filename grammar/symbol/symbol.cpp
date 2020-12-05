#include "./symbol.h"
#include <string>

SMB::Symbol::Symbol() {
    this->name = "";
    this->type = SMB::SymbolType::integer;
}

SMB::Symbol::Symbol(std::string name, SMB::SymbolType type) {
    this->name = name;
    this->type = type;
}

const std::string SMB::Symbol::getName() {
    return this->name;
}

SMB::SymbolType SMB::Symbol::getType() {
    return this->type;
}


//FuncSymbol
//检查StatementType == Compoundation,如果是，就开辟新的作用域，首先把参数插入新作用域符号表
SMB::FuncSymbol::FuncSymbol() {
    
}

SMB::FuncSymbol::FuncSymbol(AST::BaseNode* node) {
    AST::DefineFuncNode* tmp_node = (AST::DefineFuncNode*)node;
    this->dec_name = tmp_node->getContent();
    this->arg_list =tmp_node->getArgList();
    this->rtn_type = tmp_node->getReturnSymbolType();

    AST::DefineVarNode* p = (AST::DefineVarNode*)this->arg_list;
    while(p){
        SMB::SymbolType arg_type = p->getSymbolType();
        if(arg_type == SMB::SymbolType::integer){
            this->dec_name += "_i";
        }else if(arg_type == SMB::SymbolType::pointer){
            this->dec_name += "_p";
        }
        p = (AST::DefineVarNode*)(p->getCousinNode());
    }
}

bool SMB::FuncSymbol::operator==(const SMB::FuncSymbol& second) {
    return this->dec_name == second.dec_name;
}

SMB::SymbolTable::SymbolTable() {

}

SMB::SymbolTable::SymbolTable(SymbolTable *parent) {
    this->parent_table = parent;
    this->child_table = NULL;
    this->cousin_table = NULL;
    
    // 遍历找到根作用域
    SymbolTable *p = this;
    while (p->parent_table)
    {
        p = p->parent_table;
    }
    this->root_table = p;   
    this->total_symbol_count = 0;
    this->total_offset = 4;

    this->symbol_list = new std::vector<SMB::Symbol *>();
}

// 解决重定义问题
SMB::Symbol* SMB::SymbolTable::findInTable(const std::string name){
    std::cout<<name<<std::endl;
    std::unordered_map<std::string, SMB::Symbol *>::iterator iter;
    iter = this->symbol_hash_map.find(name);
    if (iter!=this->symbol_hash_map.end()){
        std::cout<<"find"<<std::endl;
        return iter->second;
    }else{
        std::cout<<"NULL"<<std::endl;
        return NULL;
    }
}

int SMB::SymbolTable::addSymbol(AST::BaseNode *node){
    std::string name = node->getContent();
    AST::ASTNodeType node_type = node->getASTNodeType();
    AST::DefineVarNode* tmp = (AST::DefineVarNode*)node;
    SMB::SymbolType symbol_type = tmp->getSymbolType();
    Symbol *s = new Symbol(name,symbol_type);
    if((this->findInTable(name))==NULL){
        this->root_table->symbol_list->push_back(s);
        s->setIndex(this->root_table->total_symbol_count++);
        s->setOffset(this->root_table->total_offset);
        //offset的地方可能还需要修改
        if(symbol_type == SMB::SymbolType::integer || symbol_type == SMB::SymbolType::pointer){
            this->root_table->total_offset += INT_OFFSET;
        }else if(symbol_type == SMB::SymbolType::array){
            //this->root_table->total_offset += 0;//加一个数组长度
        }
        this->symbol_hash_map[s->getName()]=s;
        std::cout<<"add symbol:"<<s->getName()<<std::endl;
        return SUCCESS;
    }else{
        // 重定义了
        return FAIL; 
    }   
}

int SMB::SymbolTable::addFuncSymbol(SMB::FuncSymbol *func_symbol){
    if((this->findInTable(func_symbol->getDecName()))==NULL){
        this->root_table->symbol_list->push_back(func_symbol);
        //func_symbol->setIndex(this->root_table->total_symbol_count++);
        //offset部分
        std::string tmp_func_name = func_symbol->getDecName();
        std::cout<<tmp_func_name<<std::endl;
        this->symbol_hash_map[tmp_func_name]=func_symbol;
        if((this->symbol_hash_map[tmp_func_name])==NULL){
            std::cout<<"wrong"<<std::endl;
        }
        std::string tmp = ((SMB::FuncSymbol*)(this->symbol_hash_map[tmp_func_name]))->getDecName();
        std::cout<<"add function:"<<tmp<<std::endl;
        return SUCCESS;
    }else{
        //重定义
        return FAIL;
    }
}

SMB::SymbolTable* SMB::SymbolTable::createChildTable(){
    SymbolTable *child = new SymbolTable(this);
    if(this->child_table == NULL){
        this->setChild(child);
    }else if(this->child_table->cousin_table == NULL){
        this->child_table->cousin_table = child;
    }
    else{
        SymbolTable *cousin = this->child_table->cousin_table;
        while(cousin != NULL){
            if(cousin->cousin_table == NULL){
                cousin->cousin_table = child;
                break;
            }
        }
    }
    return child;
}

// 解决undefine的问题
SMB::Symbol* SMB::SymbolTable::findSymbol(std::string name){
    SymbolTable *tmp = this;
    while(tmp != NULL){
        Symbol *final = tmp->findInTable(name);
        if(final ==NULL){
            tmp = tmp->parent_table;
        }else{
            return final;
        }
    }
    std::cout << "\033[31mError: \033[0m"
              << "value " << name << " is not defined" << std::endl;
    exit(1);
    return NULL;
}






