#include <string>
#include <hash_map>
#include <vector>

class symbol
{
protected:
    std::string name;
    symbolType type;
    int offset;
    int index;

public:
    symbol();
    symbol(std::string name, symbolType type);
    const std::string getName();
    symbolType &getType();
    int getOffset() { return offset; }
    int getIndex() { return index; }
    void setOffset(int offset) { this->offset = offset; }
    void setIndex(int index) { this->index = index; }
};

class structTable
{
private:
    std::hash_map<std::string, structSymbol *> structHashTable;
    static int num;

public:
    structTable();
    bool addStructSymbol(structSymbol *func);
    structSymbol *searchStructSymbol(std::string symbolName);
};

class structSymbol : public symbol
{
    std::hash_map<std::string, int> offsetTable;
    int totalOffsets;

public:
    structSymbol();
    structSymbol(std::string name, AbstractASTNode *node);
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







