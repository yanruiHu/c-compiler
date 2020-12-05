#ifndef SYMBOLTYPE_H
#define SYMBOLTYPE_H

#include<string>

namespace SMB {

    static std::string symbol_string[] = {
        "none",
        "int",
        "ptr",
        "bool",
        "void",
        "struct",
        "array",
        "literal",
        "func",
    };

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
}
#endif