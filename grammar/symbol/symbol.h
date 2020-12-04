#ifndef _SYMBOL_H_
#define _SYMBOL_H_
#include <string>
#include <unordered_map>
#include <vector>
#include "../Nodes.h"
#define INT_OFFSET 4
namespace SMB {

    enum SymbolType {
        none = 0, //undefine
        integer = 1,
        pointer = 2,
        boolean = 3,
        void_type = 4,
        struct_type = 5, // for struct
        array = 6,
        literal = 7,
        function = 8,
    };

    class Symbol {
    protected:
        std::string name;
        SymbolType type;
        int offset;
        int index;

    public:
        Symbol();
        Symbol(std::string name, SymbolType type);
        const std::string getName();
        SymbolType getType();
        inline int getOffset() { return offset; }
        inline int getIndex() { return index; }
        inline void setOffset(int offset) { this->offset = offset; }
        inline void setIndex(int index) { this->index = index; }
    };

    class FuncSymbol : public Symbol {
        private:
            std::string dec_name;
            std::vector<SymbolType> arg_type_list;
            int total_arg_offset;
            SymbolType rtn_type;
        
        public:
            FuncSymbol();
            FuncSymbol(AST::BaseNode* node);
            bool operator==(const FuncSymbol& second);
            inline std::string getDecName() { return this->dec_name; }
            inline int getTotalArgOffset() { return this->total_arg_offset; }
    };


    class SymbolTable {
        private:
            std::unordered_map<std::string, Symbol*> symbol_hash_map;
            std::vector<Symbol*> *symbol_list;
            SymbolTable *parent_table;
            SymbolTable *child_table;
            SymbolTable *cousin_table;
            //结构体Table
            int total_symbol_count;
            int total_offset;
            //int argTotalOffset;                     // 参数偏移量  
            //bool isFunctionTable;
           static SymbolTable *root_table;

            SymbolTable(SymbolTable *parent);
            Symbol *findInTable(const std::string name);
            //void visitFuncArgs(AbstractASTNode *arg, int &offset, int &index);
        
        public:
            static const int SUCCESS=1;
            static const int FAIL=0;
            SymbolTable();
            int addSymbol(AST::BaseNode *node);
            //int addStructSymbol(std::string structTypeName, std::string structIdName);
            //void addFromFunctionArgs(AbstractASTNode *func);
            SymbolTable* createChildTable();

            Symbol* findSymbol(const std::string name);
            inline void setChild(SymbolTable* child) { this->child_table = child; };
            inline void setParent(SymbolTable* parent) { this->parent_table = parent; };


            inline SymbolTable* getParent() { return this->parent_table; };
            inline SymbolTable* getChild() { return this->child_table; };
            inline SymbolTable* getPeer() { return this->cousin_table; }
            inline int getTotalOffset() { return this->total_offset; }
            //inline int getArgTotalOffset() { return this->argTotalOffset; }
            //inline StructTable *getStructTable() { return this->structTable; }
    };
/*
    class structTable
    {
    private:
        std::unordered_map<std::string, structSymbol *> structHashTable;
        static int num;

    public:
        structTable();
        bool addStructSymbol(structSymbol *func);
        structSymbol *searchStructSymbol(std::string symbolName);
    };

    class structSymbol : public symbol
    {
        std::unordered_map<std::string, int> offsetTable;
        int totalOffsets;

    public:
        structSymbol();
        //structSymbol(std::string name, AbstractASTNode *node);
        std::string getStructName() { return this->name; }
        int getTotalOffsets() { return this->totalOffsets; }
        int getMemberOffset(std::string key);
    };

    class decorationStructSymbol : public symbol
    {
    private:
        std::string structTypeName;
    public:
        decorationStructSymbol(std::string structTypeName, std::string name);
        std::string getStructTypeName() { return this->structTypeName; }
    };
*/
} // namespace SMB

#endif
