#include "./symbol.h"
#include <string>

SMB::Symbol::Symbol() {
    this->name = "";
    this->type = STE::SymbolType::integer;
}

SMB::Symbol::Symbol(std::string name, STE::SymbolType type) {
    this->name = name;
    this->type = type;
}

const std::string SMB::Symbol::getName() {
    return this->name;
}

STE::SymbolType SMB::Symbol::getType() {
    return this->type;
}


//FuncSymbol
//检查StatementType == Compoundation,如果是，就开辟新的作用域，首先把参数插入新作用域符号表
SMB::FuncSymbol::FuncSymbol() {
    
}

SMB::FuncSymbol::FuncSymbol(AST::BaseNode* node) {
    this->name = node->getContent();
    // this->arg_type_list = NULL;
    // this->rtn_type = rtn_type;
    // for(size_t i = 0; i < type_list.size();i++){
    //     if(type_list[i] == SymbolType::integer){
    //         this->dec_name += "_i";
    //     }else if(type_list[i]==SymbolType::pointer){
    //         this->dec_name += "_p";
    //     }
    // }
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
    std::unordered_map<std::string, SMB::Symbol *>::iterator iter;
    iter = this->symbol_hash_map.find(name);
    if (iter!=this->symbol_hash_map.end()){
        return iter->second;
    }else{
        return NULL;
    }
}

int SMB::SymbolTable::addSymbol(AST::BaseNode *node){
    std::string name = node->getContent();
    AST::ASTNodeType node_type = node->getASTNodeType();
    AST::DefineVarNode* tmp = (AST::DefineVarNode*)node;
    STE::SymbolType symbol_type = tmp->getSymbolType();
    Symbol *s = new Symbol(name,symbol_type);
    if((this->findInTable(name))==NULL){
        this->root_table->symbol_list->push_back(s);
        s->setIndex(this->root_table->total_symbol_count++);
        s->setOffset(this->root_table->total_offset);
        //offset的地方可能还需要修改
        if(symbol_type == STE::SymbolType::integer || symbol_type == STE::SymbolType::pointer){
            this->root_table->total_offset += INT_OFFSET;
        }else if(symbol_type == STE::SymbolType::array){
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





