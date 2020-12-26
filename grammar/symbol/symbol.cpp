#include "./symbol.h"
#include <string>
#include <stack>

SMB::SymbolTable* SMB::SymbolTable::global_table;

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
            this->dec_name += "-i";
        }else if(arg_type == SMB::SymbolType::pointer){
            this->dec_name += "-p";
        }
        total_arg_offset += 4;
        p = (AST::DefineVarNode*)(p->getCousinNode());
    }
}

bool SMB::FuncSymbol::operator==(const SMB::FuncSymbol& second) {
    return this->dec_name == second.dec_name;
}

// Struct
SMB::StructDefSymbol::StructDefSymbol(std::string struct_type_name, std::string id_name){
    this->stuct_type_name=struct_type_name;
    this->name = id_name;
}

SMB::StructSymbol::StructSymbol(){
    
}

SMB::StructSymbol::StructSymbol(std::string name, AST::BaseNode* node){
    this->total_member_offset = 0;
    int offset = 0;
    this->name = name;
    std::cout << "struct_name: " << name << std::endl;
    AST::BaseNode *curr_node = node;
    while(curr_node){
        AST::DefineVarNode *var = (AST::DefineVarNode*)curr_node;
        offset_table[var->getContent()] = offset;
        offset+=4;
        curr_node = curr_node->getCousinNode();
    }
    this->total_member_offset = offset;
}

int SMB::StructSymbol::getMemberOffset(std::string member_name){
    if(this->offset_table.count(member_name) == 0){
        return -1;
    }else{
        return this->offset_table[member_name];
    }
}

SMB::StructTable::StructTable(){

}

SMB::StructSymbol *SMB::StructTable::findStruct(std::string id_name){
    // std::cout<<"findStruct"<<std::endl;
    // std::cout<<&this->struct_hash_table<<std::endl;
    // return NULL;
    std::unordered_map<std::string, SMB::StructSymbol*>::iterator iter;
    iter = this->struct_hash_table.find(id_name);
    if(iter != this->struct_hash_table.end())
        return iter->second;
    else
        return NULL;
}

bool SMB::StructTable::addStruct(StructSymbol *curr_struct){
    if(this->findStruct(curr_struct->getName())!=NULL){
        return false;
    }else{
        this->struct_hash_table[curr_struct->getName()]=curr_struct;
        return true;
    }
}



SMB::SymbolTable::SymbolTable() {
    this->table_name = "Global";
}

void SMB::SymbolTable::addFromFunctionArgs(FuncSymbol *func_node) {
    AST::BaseNode* args = func_node->getArgList();
    int offset = -4;
    int index = -1;
    std::stack<AST::BaseNode*> tmp_stack;
    while (args) {
        tmp_stack.push(args);
        args = args->getCousinNode();
    }
    while (tmp_stack.size()) {
        // this->addSymbol(args);
        AST::DefineVarNode *arg = (AST::DefineVarNode *)tmp_stack.top();
        if(arg->getSymbolType() == SMB::SymbolType::integer || arg->getSymbolType() == SMB::SymbolType::pointer){
            offset -= 4;
            SMB::Symbol *arg_symbol = new SMB::Symbol(arg->getContent(),arg->getSymbolType());
            arg_symbol->setIndex(index--);
            arg_symbol->setOffset(offset);
            std::cout<< "add symbol:" << arg_symbol->getName() << " in " << this->getTableName() <<std::endl;
            symbol_hash_map[arg_symbol->getName()] = arg_symbol;
        }
        tmp_stack.pop();
    }
    this->total_arg_offset = -(offset+4);
}

SMB::SymbolTable::SymbolTable(SymbolTable *parent, bool is_func) {
    this->parent_table = parent;
    this->child_table = NULL;
    this->cousin_table = NULL;
    this->is_func = is_func;
    this->table_name = "Unnamed";
    
    // 遍历找到根作用域
    SymbolTable *p = this;
    while (!p->is_func)
    {
        p = p->parent_table;
    }
    this->root_table = p;   
    this->total_symbol_count = 0;
    this->total_offset = 4;
    this->symbol_list = new std::vector<SMB::Symbol *>();
    if(is_func){
        this->arg_list = new std::vector<SMB::Symbol *>();
    }
    
}

SMB::SymbolTable::SymbolTable(bool is_func, SMB::StructTable *struct_table){
    this->struct_list = struct_table;
    this->child_table = NULL;
    this->parent_table = NULL;
    this->root_table = this;
    this->total_symbol_count = 0;
    this->total_offset = 4;
    this->is_func = is_func;
    this->symbol_list = new std::vector<SMB::Symbol *>();
    if(is_func){
        this->arg_list = new std::vector<SMB::Symbol *>();
    }else{
        this->table_name = "GLOBAL";
    }
}

// 解决重定义问题
SMB::Symbol* SMB::SymbolTable::findInTable(const std::string name){
    std::unordered_map<std::string, SMB::Symbol *>::iterator iter;
    iter = this->symbol_hash_map.find(name);
    if (iter != this->symbol_hash_map.end()) {
        // std::cout<<"find "<< name << " in " << this->getTableName() <<std::endl;
        return iter->second;
    } else {
        // std::cout<<"no "<< name << " in " << this->getTableName() <<std::endl;
        return NULL;
    }
}

int SMB::SymbolTable::addSymbol(AST::BaseNode *node){
    std::string name = node->getContent();
    AST::ASTNodeType node_type = node->getASTNodeType();
    AST::DefineVarNode* tmp = (AST::DefineVarNode*)node;
    SMB::SymbolType symbol_type = tmp->getSymbolType();
    // std::cout<<"name:"<<name<<"node_type:"<<node_type<<std::endl;
    Symbol *s = new Symbol(name, symbol_type);
    if((this->findInTable(name)) == NULL){
        this->root_table->symbol_list->push_back(s);
        s->setIndex(this->root_table->total_symbol_count++);
        s->setOffset(this->root_table->total_offset);
        //offset的地方可能还需要修改
        if(symbol_type == SMB::SymbolType::integer || symbol_type == SMB::SymbolType::pointer){
            this->root_table->total_offset += INT_OFFSET;
        }
        // } else if(symbol_type == SMB::SymbolType::array) {
        //     this->root_table->total_offset += tmp->getArrayLength()*4;
        // }
        this->symbol_hash_map[s->getName()] = s;
        // std::cout<< "add symbol:" << s->getName() << " in " << this->getTableName() <<std::endl;
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
        this->symbol_hash_map[tmp_func_name]=func_symbol;
        if((this->symbol_hash_map[tmp_func_name])==NULL){
            // std::cout<<"wrong"<<std::endl;
        }
        std::string tmp = ((SMB::FuncSymbol*)(this->symbol_hash_map[tmp_func_name]))->getDecName();
        // std::cout<< "add function:" << tmp << " in " << this->getTableName() << std::endl;
        return SUCCESS;
    }else{
        //重定义
        return FAIL;
    }
}

int SMB::SymbolTable::addStructSymbol(std::string struct_type, std::string id_name){
    StructDefSymbol *s = new StructDefSymbol(struct_type, id_name);
    if(this->findInTable(id_name)!=NULL)
        return FAIL;
    else{
        std::cout << "global_table: " << this->global_table << std::endl;
        std::cout << "struct_list: " << this->global_table->struct_list << std::endl;
        StructSymbol *target = this->global_table->struct_list->findStruct(struct_type);
        if(target == NULL){
            return FAIL;
        }else{
            this->symbol_list->push_back(s);
            s->setIndex(this->root_table->total_symbol_count++);
            s->setOffset(this->root_table->total_offset);
            this->root_table->total_offset += target->getTotalMemberOffset();
            this->symbol_hash_map[s->getName()] = s;
            // std::cout<< "add struct symbol:" << s->getName() << " in " << this->getTableName() <<std::endl;
            return SUCCESS;
        }
    }
}

int SMB::SymbolTable::addArraySymbol(AST::BaseNode *array_node){
    AST::DefineVarNode *curr_array = (AST::DefineVarNode *)array_node;
    std::string array_name = array_node->getContent();
    if(this->findInTable(array_name)!=NULL)
        return FAIL;
    else{
        Symbol *s = new Symbol(array_name, SymbolType::array);
        this->root_table->symbol_list->push_back(s);
        s->setIndex(this->root_table->total_symbol_count++);
        s->setOffset(this->root_table->total_offset);
        this->root_table->total_offset += curr_array->getArrayLength()*4;
        //std::cout<<"total_offset:"<<this->root_table->total_offset<<std::endl<<"total_:"<<this->total_offset<<std::endl;
        this->symbol_hash_map[array_name] = s;
        //std::cout<< "add array:" << s->getName() << " in " << this->getTableName() <<std::endl;
        return SUCCESS;
    }
}

SMB::SymbolTable* SMB::SymbolTable::createChildTable(bool is_func){
    SMB::SymbolTable *child = new SMB::SymbolTable(this, is_func);
    // child->root_table = this->root_table;
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
        if(final == NULL){
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






