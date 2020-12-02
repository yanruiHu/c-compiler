%{
#include "stdio.h"
// #include "hdr.h"
#include <string.h>
#include <fstream>
#include "../grammar/ASTtree/BaseNode.h"

class BaseNode;

extern int yylex();
extern FILE * yyin;
void yyerror(char* s);
BaseNode* root;
extern int yylineno;
%}


%union {
    /*maybe a tree strurt ?*/
    BaseNode* ast;
    double dval;
    // struct symtab *symp;
    char* str;
}
%right <ast> '='
%left <ast> OR
%left <ast> AND
%left <ast> RELOP
%left <ast> '-' '+'
%left <ast> '*' '/' '%'
%left <ast> '^'
%right <ast> '!'
%left '(' ')' '[' ']'

%token ERRID

%token <str> ID   //终结符
%token <str> INT VOID
%token ',' ';' // , ;
%token STRUCT
%token IF ELSE WHILE FOR CONTINUE RETURN ERRORCHAR GETMEMBER
%token '{' '}' //{}



%nonassoc UMINUS

/*非终结符——>定义了语法树之后再添加类型*/
%type <ast> program translation_unit external_declaration external_declaration_list
%type <str> specifier
%type <ast> struct_specifier struct_declaration_list struct_declaration
%type <ast> direct_declarator func_declarator parameter_list parameter_declaration
%type <ast> compound_statement block_item_list declaration_for expression_statement statement defination declaration_list declaration
%type <ast> expression argument_expression_list
// %
// %start program

%%
/*注：有关declarator的和declaration的yacc逻辑过于混乱，保证准确起见参考了lpy的*/
program: translation_unit { 
        root = new BaseNode(root_);
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
external_declaration: specifier external_declaration_list ';' {}
    // | specifier ';' {}
    | specifier func_declarator compound_statement {
        $2->addChildNode($3);
        $$ = $2;
    }
    | specifier func_declarator ';'  {
        $$ = $2;
    }
    | struct_specifier ';' {}
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
specifier: INT { $$ = (char*)("int"); }
    | VOID { $$ = (char*)("void"); }
    | INT '*' { $$ = (char*)("int ptr"); }
    | VOID '*' { $$ = (char*)("void ptr"); }
    ;

struct_specifier: STRUCT ID '{' struct_declaration_list '}' { $$ = NULL; }
    | STRUCT '{' struct_declaration_list '}' { $$ = NULL; }
    | STRUCT ID { $$ = NULL; }
    ;

struct_declaration_list: struct_declaration { $$ = NULL; }
    | struct_declaration_list struct_declaration_list { $$ = NULL; }
    ;

struct_declaration: specifier ID ';' { $$ = NULL; }
    ;

/* declarationorator 装饰符 声明？格式*/
direct_declarator: ID {
        char* s = "";
        sprintf(s, "variable defination, name: %s", $1);
        $$ = new BaseNode(s, dec_var);
    }
    | ID '[' INT ']' {
        char* s = "";
        sprintf(s, "variable defination (array), name: %s", $1);
        $$ = new BaseNode(s, dec_var);
    }
    ;
func_declarator: ID '(' direct_declarator ')' { 
        char* s = "";
        sprintf(s, "func defination, name: %s", $1);
        $$ = new BaseNode(s, dec_func);
    }
    | ID '(' ')' {
        char* s = "";
        sprintf(s, "func defination, name: %s", $1);
        $$ = new BaseNode(s, dec_func);
    }
    ;
parameter_list: direct_declarator ',' parameter_declaration {
        $1->getFinalCousinNode()->addCousinNode($3);
        $$ = $1;
    }
    | parameter_declaration { $$ = $1 }
    ;
parameter_declaration: specifier ID {
        char* s = "";
        sprintf(s, "variable defination, name: %s", $1);
        $$ = new BaseNode(s, dec_var);
    }
    | specifier {}
    ;


/* Statement 声明*/
compound_statement: '{' block_item_list '}' {
        BaseNode* temp = new BaseNode("compound statement");
        temp->addChildNode($2);
        $$ = temp;
    }
    | '{' '}' {}
    | error '}' { yyerrok; }
    ;

block_item_list: block_item_list statement {
        if ($1 == NULL) {
            $$ = $2;
        } else {
            $1->getFinalCousinNode()->addCousinNode($2);
        }
    }
    | {
        $$ = NULL;
    }
    ;

  /*这个不知道是啥*/
declaration_for: defination { $$ = $1; }
    | expression { $$ = $1; }
    ;
expression_statement: ';' {}
    | expression ';' { 
        BaseNode* temp = new BaseNode("statement inside for");
        temp->addChildNode($1);
        $$ = temp;
    }
    ;
statement: compound_statement
    | expression ';' { 
        BaseNode* temp = new BaseNode("expression statement");
        temp->addChildNode($1);
        $$ = temp;
    }
    | STRUCT ID ID ';' {}
    | defination ';' { 
        BaseNode* temp = new BaseNode("defination statement");
        temp->addChildNode($1);
        $$ = temp;
    }
    | IF '(' expression ')' statement { 
        BaseNode* temp = new BaseNode("select statement(if)");
        temp->addChildNode($3);
        $3->addCousinNode($5);
        $$ = temp;
    }
    | IF '(' expression ')' statement ELSE statement {
        BaseNode* temp = new BaseNode("select statement(if)");
        temp->addChildNode($3);
        $3->addCousinNode($5);
        BaseNode* else_node = new BaseNode("select statement(else)");
        else_node->addChildNode($7);
        temp->addCousinNode(else_node);
        $$ = temp;
    }
    | WHILE '(' expression ')' statement {
        BaseNode* temp = new BaseNode("loop statement(while)");
        temp->addChildNode($3);
        $3->addCousinNode($5);
        $$ = temp;
    }
    | FOR '(' expression_statement expression_statement ')' statement {
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode($3);
        $3->addCousinNode($4);
        $4->addCousinNode($6);
        $$ = temp;
    }
    | FOR '(' expression_statement expression_statement expression ')' statement {
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode($3);
        $3->addCousinNode($4);
        $4->addCousinNode($5);
        $5->addCousinNode($7);
        $$ = temp;
    }
    // | FOR '(' ';' ';' ')' statement
    | FOR '(' declaration_for ';' ';' ')' statement {
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode($3);
        $3->addCousinNode($7);
        $$ = temp;
    }
    // | FOR '(' ';' expression ';' ')' statement
    // | FOR '(' ';' ';' expression ')' statement
    | FOR '(' declaration_for ';' expression ';' expression ')' statement {
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode($3);
        $3->addCousinNode($5);
        $5->addCousinNode($7);
        $7->addCousinNode($9);
        $$ = temp;
    }
    | FOR '(' declaration_for ';' expression ';' ')' statement  {
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode($3);
        $3->addCousinNode($5);
        $5->addCousinNode($8);
        $$ = temp;
    }
    | FOR '(' declaration_for ';' ';' expression ')' statement  {
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode($3);
        $3->addCousinNode($6);
        $6->addCousinNode($8);
        $$ = temp;
    }
    | FOR '(' ';' expression ';' expression ')' statement {
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode($4);
        $4->addCousinNode($6);
        $6->addCousinNode($8);
        $$ = temp;
    }
    | RETURN expression ';' {
        BaseNode* temp = new BaseNode("return statement");
        temp->addChildNode($2);
        $$ = temp;
    }
    | RETURN ';' {
        BaseNode* temp = new BaseNode("return statement");
        $$ = temp;
    }
    | error ';' { yyerrok; }  /*官方没报错 参考代码报错了不知道为啥*/
    ;



/* Local Definitions 参考代码上注释是这个*/
defination: specifier declaration_list  {
        $$ = $2;
    }
    | error ';' { yyerrok; }
    ;

declaration_list: declaration { $$ = $1; }
    | declaration ',' declaration_list {
        $1->getFinalCousinNode()->addCousinNode($3);
        $$ = $1;
    }
    ;

declaration: direct_declarator { $$ = $1; }
    | direct_declarator '=' expression {
        $1->addChildNode($3);
        $$ = $1;
    }
;


/* expressionression */
expression: expression '=' expression {
            BaseNode* temp = NULL;
            temp = new BaseNode("operator: =", op);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression AND expression {
            BaseNode* temp = new BaseNode("operator: &&", op);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression OR expression {
            BaseNode* temp = new BaseNode("operator: ||", op);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression RELOP expression {
            char* s = "";
            sprintf(s, "operator: %s", $2);
            BaseNode* temp = new BaseNode(s, op);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression '+' expression {
            BaseNode* temp = new BaseNode("operator: +", op);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression '-' expression {
            BaseNode* temp = new BaseNode("operator: -", op);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression '*' expression {
            BaseNode* temp = new BaseNode("operator: *", op);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression '/' expression {
            BaseNode* temp = new BaseNode("operator: /", op);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression '%' expression {
            BaseNode* temp = new BaseNode("operator: %", op);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression '^' expression {
            BaseNode* temp = new BaseNode("operator: ^", op);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | '(' expression ')' {
            $$ = $2;
        }
        | '-' expression {
            BaseNode* temp = new BaseNode("operator: -", op);
            temp->addChildNode($2);
            $$ = temp;
        }
        | '!' expression {
            BaseNode* temp = new BaseNode("operator: !", op);
            temp->addChildNode($2);
            $$ = temp;
        }
        | ID '(' argument_expression_list ')' {
            char* s = "";
            sprintf(s, "call function name: %s", $1);
            BaseNode* temp = new BaseNode(s);
            temp->addChildNode($3);
            $$ = temp;
        }
        | ID '(' ')' {
            char* s = "";
            sprintf(s, "call function name: %s", $1);
            BaseNode* temp = new BaseNode(s);
        }
        | expression '[' expression ']' {
            $$ = NULL;
        }
        | ID {
            $$ = new BaseNode($1);
        }
        | ID '[' expression ']' {
            BaseNode* op = new BaseNode("operator: []");
            char* s = "";
            sprintf(s, "variable: %s", $1);
            BaseNode* temp = new BaseNode(s);
            $$ = op;
            op->addChildNode(temp);
            temp->addCousinNode($3);
        }
        | ID '.' ID {}
        | INT {
            char* s = "";
            sprintf(s, "literal: %s", $1);
            $$ = new BaseNode(s);
        }
        | '*' ID {}
        | error ')' {yyerrok;}  /*当不可计算的表达式被读入后，上述第三条规则将识别出这个错误，解析将继续。yyerror 仍将被调用以打印出一条消息。第三条规则对应的动作是一个宏 yyerrok*/
        ;
argument_expression_list: expression {
            $$ = $1;
        }
        | argument_expression_list ',' expression {
            $1->getFinalCousinNode()->addCousinNode($3);
            $$ = $1;
        }
        ;
%%

/*
* Editor:Liuyin
* Content: Add main() modify yyerror
* 
*/
void yyerror(char* s) {
	fprintf(stderr, "Parse error: At line %d. %s\n", yylineno, s);
	exit(1);
}

int main(int argc,char ** argv){  //不确定语法的在哪里输出

    int c,j=0;
    if(argc>=2){
        if((yyin=fopen(argv[1],"r"))==NULL){
            printf("Can't open file %s\n",argv[1]);
            return 1;
        }
    }
    do {
		yyparse();
	} while(!feof(yyin));
    if(argc>=2){
        fclose(yyin);
    }
    root->printTree();
    return 0;
}
