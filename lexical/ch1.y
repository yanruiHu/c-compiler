#include <string.h>
#include <fstream>
#include "../grammar/Nodes.h"
#include "../grammar/symbol/symbol.h"

using AST::BaseNode;
class BaseNode;
extern char *yytext;
extern int yylex();
extern FILE * yyin;
void yyerror(const char* s);
BaseNode* root = NULL;
extern int yylineno;
%}


%union {
    AST::BaseNode* ast;
    // struct symtab *symp;
    char* str;
}
%locations
%define parse.error verbose

%right <ast> '='
%left <ast> OR
%left <ast> AND
%left <str> RELOP
%left <ast> '-' '+'
%left <ast> '*' '/' '%'
%left <ast> '^'
%right <ast> '!'
%left '(' ')' '[' ']'
%nonassoc LOWER_THAN_ELSE
%token ERRID
%token <str> ID   //终结符
%token <str> INT VOID
%token ',' ';' // , ;
%token STRUCT
%token IF ELSE WHILE FOR CONTINUE RETURN ERRORCHAR GETMEMBER
%token '{' '}' //{}



/*非终结符——>定义了语法树之后再添加类型*/
%type <ast> program translation_unit external_declaration external_declaration_list
%type <str> specifier
%type <ast> struct_specifier struct_declaration_list struct_declaration
%type <ast> direct_declarator func_declarator parameter_list parameter_declaration
%type <ast> compound_statement block_item_list declaration_for  statement defination declaration_list declaration
%type <ast> expression argument_expression_list
// %
// %start program
%%
/*注：有关declarator的和declaration的yacc逻辑过于混乱，保证准确起见参考了lpy的*/
program: translation_unit { 
        root = new BaseNode("code start!", AST::root);
        root->addChildNode($1);
    }
    ;
translation_unit: external_declaration { 
        $$ = $1;
    }
    | translation_unit external_declaration {
        if ($1 == NULL) {
            $$ = $2;
        } else {
            if ($2 != NULL) {
                $1->getFinalCousinNode()->addCousinNode($2);
            }
            $$ = $1;
        }
    }
    ;
external_declaration: specifier external_declaration_list ';' {
        AST::DefineVarNode* tmp = (AST::DefineVarNode*)$2;
        tmp->setAllSymbolType($1);
        $$ = tmp;
    }
    | specifier ';' {}
    | specifier func_declarator compound_statement {
        AST::DefineFuncNode* tmp = (AST::DefineFuncNode*) $2;
        tmp->addChildNode($3);
        tmp->setReturnSymbolType($1);
        $$ = tmp;
    }
    | specifier func_declarator ';'  {
        AST::DefineFuncNode* tmp = (AST::DefineFuncNode*) $2;
        tmp->setReturnSymbolType($1);
        $$ = tmp;
    }
    | struct_specifier ';' { $$ = $1;}
    | error ';' { yyerrok; $$ = NULL;}
    ;
external_declaration_list: direct_declarator { $$ = $1; }
    | external_declaration_list ',' direct_declarator {
        $1->getFinalCousinNode()->addCousinNode($3);
        $$ = $1;
    }
    ;
/*↑*/

/* specifiers 说明符*/
specifier: INT { $$ = strdup("int"); }
    | VOID { $$ = strdup("void"); }
    | INT '*' { $$ = strdup("int ptr"); }
    | VOID '*' { $$ = strdup("void ptr"); }
    ;
