%{
#include "stdio.h"
#include "hdr.h"
#include <string.h>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>

extern int yylex();
// extern FILE * yyin
void yyerror(char* s);
%}


%union {
        /*maybe a tree strurt ?*/
        double  dval;
        struct symtab *symp;
}
%right '='
%left OR
%left AND
%left LT GT LE GE EQ NE
%left '-' '+'
%left '*' '/' '%'
%left '^'
%right '!'
%left '(' ')' '[' ']'

%token <symp> ID  //终结符
%token <dval> INT10
%token ',' ';' //,;
%token STRUCT
%token IF ELSE WHILE DO FOR CONTINUE RETURN ERRORCHAR
%token '{' '}' //{}
%nonassoc UMINUS

    /*非终结符——>定义了语法树之后再添加类型*/
%type <dval> expression 
// %

%%
/*注：有关declarator的和declaration的yacc逻辑过于混乱，保证准确起见参考了lpy的*/
// Program: translation_unit;
translation_unit: external_declaration
    | translation_unit external_declaration
    ;
external_declaration: specifier ExtDecList ';'
    | specifier ';'
    | specifier func_declarator compound_statement
    | specifier func_declarator ';'
    | struct_specifier ';'
    | error ';' { yyerrok; $$ = NULL;}
    ;
ExtDecList: direct_declarator
    | ExtDecList ',' direct_declarator
    ;
/*↑*/

/* specifiers 说明符*/
specifier: TYPE 
    | VOID  
    | TYPE '*'
    | VOID '*'
    ;

struct_specifier: STRUCT ID '{' struct_declaration_list '}' 
    | STRUCT '{' struct_declaration_list '}'
    | STRUCT ID
    ;

struct_declaration_list: struct_declaration
    | struct_declaration_list struct_declaration_list
    ;

struct_declaration: specifier ID ';' ;

/* declarationorator 装饰符 声明？格式*/
direct_declarator: ID
    | ID '[' INT10 ']'
    ;
func_declarator: ID '(' direct_declarator ')' 
    | ID '(' ')' 
    ;
parameter_list: direct_declarator ',' parameter_declaration
    | parameter_declaration
    ;
parameter_declaration: specifier ID 
    | specifier 
    ;


/* Statement 声明*/
compound_statement: '{' block_item_list '}'
    | '{' '}'
    | error '}' { yyerrok; }
    ;

block_item_list: block_item_list statement
    | 
    ;

/*这个不知道是啥*/
declaration_for: Def
    | expression 
    ;
expression_statement: ';'
    | expression ';'
    ;
statement: compound_statement
    | expression ';'
    | STRUCT ID ID ';'
    | Def ';'
    | IF '(' expression ')' statement
    | IF '(' expression ')' statement ELSE statement 
    | WHILE '(' expression ')' statement
    | FOR '(' expression_statement expression_statement ')' statement
    | FOR '(' expression_statement expression_statement expression ')' statement
    // | FOR '(' ';' ';' ')' statement
    | FOR '(' declaration_for ';' ';' ')' statement
    // | FOR '(' ';' expression ';' ')' statement
    // | FOR '(' ';' ';' expression ')' statement
    | FOR '(' declaration_for ';' expression ';' expression ')' statement 
    | FOR '(' declaration_for ';' expression ';' ')' statement 
    | FOR '(' declaration_for ';' ';' expression ')' statement 
    | FOR '(' ';' expression ';' expression ')' statement
    | RETURN expression ';'
    | RETURN ';'
    | error ';' { yyerrok; }  /*官方没报错 参考代码报错了不知道为啥*/
    ;



/* Local Definitions 参考代码上注释是这个*/
Def: specifier declaration_list 
    | error ';' { yyerrok; }
    ;

declaration_list: declaration
    | declaration ',' declaration_list
    ;

declaration: direct_declaration
    | direct_declaration '=' expression
;


/* expressionression */
expression: expression '=' expression
        | expression AND expression
        | expression OR expression
        | expression GE expression
        | expression LE expression
        | expression EQ expression
        | expression NE expression
        | expression GE expression
        | expression LE expression
        | expression '+' expression
        | expression '-' expression
        | expression '*' expression
        | expression '/' expression
        | expression "%" expression
        | expression '^' expression
        | '(' expression ')'
        | '-' expression
        | '!' expression
        | ID '(' argument_expression_list ')'
        | ID '(' ')'
        | expression '[' expression ']'
        | ID
        | ID '[' expression ']'
        | ID  ERRORCHAR ID  // '.'
        | INT10
        | '*' ID
        | error ')' {yyerrok;}  /*当不可计算的表达式被读入后，上述第三条规则将识别出这个错误，解析将继续。yyerror 仍将被调用以打印出一条消息。第三条规则对应的动作是一个宏 yyerrok*/
        ;
argument_expression_list: expression
        | argument_expression_list ',' expression
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
        if(argc>=3){
            yyout=fopen(argv[2],"w");
        }
    }
    while(c=yylex()){
            yyparse()  
        }
    if(argc>=2){
        fclose(yyin);
        if(argc>=3)
            fclose(yyout);
    }
    return 0;
}
