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
    this->parent_table = NULL;
    this->child_table = NULL;
    this->cousin_table = NULL;
    this->root_table = this;

    this->total_symbol_count = 0;
    this->total_offset = 4;
}

SMB::SymbolTable::SymbolTable(SymbolTable *parent) {
    this->parent_table = parent;
    this->child_table = NULL;
    this->cousin_table = NULL;
    
    this->total_symbol_count = 0;
    this->total_offset = 4;
}

SMB::Symbol* SMB::SymbolTable::findInTable(const std::string name){
    std::unordered_map<std::string, SMB::Symbol *>::iterator iter;
    iter = this->symbol_hash_map.find(name);
    if (iter !=this->symbol_hash_map.end()){
        return iter->second;
    }else{
        return NULL;
    }
}

int SMB::SymbolTable::addSymbol(AST::BaseNode *node){
    std::string name = node->getContent();
    AST::ASTNodeType node_type = node->getASTNodeType();
    if(node_type==AST::def_var){
        AST::DefineVarNode* tmp = (AST::DefineVarNode*)node;
        SMB::SymbolType symbol_type = tmp->getSymbolType();
        Symbol *s = new Symbol(name,symbol_type);
        if(this->findSymbol(s->getName())){
            return FAIL;
        }else{
            this->root_table->symbol_list->push_back(s);
            s->setIndex(this->root_table->total_symbol_count++);
            s->setOffset(this->root_table->total_offset);
            if(symbol_type == SymbolType::integer || symbol_type == SymbolType::pointer){
                this->root_table->total_offset += INT_OFFSET;
            }else if(symbol_type == SymbolType::array){
                this->root_table->total_offset += 0;//加一个数组长度
            }
            this->symbol_hash_map[s->getName()]==s;
            std::cout<<"add symbol:"<<s->getName();
            return SUCCESS;
        }   
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






