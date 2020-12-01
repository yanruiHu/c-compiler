#ifndef _SYMBOL_H_
#define _SYMBOL_H_

namespace SMB {
    enum SymbolType {
        none = 0,
        integer = 1,
        pointer = 2,
        boolean = 3,
        void_type = 4,
        struct_type = 5,   // for struct
        array = 6,
        literal = 7,
        function = 8,
    };
} // namespace SMB


#endif