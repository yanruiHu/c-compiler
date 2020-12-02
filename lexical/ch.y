%{
#include <stdio.h>
// #include "hdr.h"
#include <string.h>
#include <fstream>
#include "../grammar/ASTtree/BaseNode.h"

class BaseNode;
extern char *yytext;
extern int yylex();
extern FILE * yyin;
void yyerror(const char* s);
BaseNode* root;
extern int yylineno;
%}


%union {
    BaseNode* ast;
    // struct symtab *symp;
    char* str;
}
%locations
%define parse.error verbose

%right <ast> ASSIGNOP
%left <ast> OR
%left <ast> AND
%left <str> RELOP
%left <ast> DEC ADD
%left <ast> MUL DIV MOD
%left <ast> POWER
%right <ast> NOT
%left LB RB MLB MRB
%nonassoc LOWER_THAN_ELSE
%token ERRID
%token <str> ID   //终结符
%token <str> INT VOID
%token COM SEM // , ;
%token STRUCT
%token IF ELSE WHILE FOR CONTINUE RETURN ERRORCHAR GETMEMBER
%token BLB BRB //{}



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
        root = new BaseNode();
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
external_declaration: specifier external_declaration_list SEM {
            $$ = $2;
    }
    | specifier SEM {}
    | specifier func_declarator compound_statement {
        $2->addChildNode($3);
        $$ = $2;
    }
    | specifier func_declarator SEM  {
        $$ = $2;
    }
    | struct_specifier SEM {$$ = $1;}
    | error SEM { yyerrok; $$ = NULL;}
    ;
external_declaration_list: direct_declarator { $$ = $1; }
    | external_declaration_list COM direct_declarator {
        $1->getFinalCousinNode()->addCousinNode($3);
        $$ = $1;
    }
    ;
/*↑*/

/* specifiers 说明符*/
specifier: INT { $$ = strdup("int"); }
    | VOID { $$ = strdup("void"); }
    | INT MUL { $$ = strdup("int ptr"); }
    | VOID MUL { $$ = strdup("void ptr"); }
    ;

struct_specifier: STRUCT ID BLB struct_declaration_list BRB { $$ = NULL; }
    ;

struct_declaration_list: struct_declaration { $$ = NULL; }
    | struct_declaration_list struct_declaration{ $$ = NULL; }
    ;

struct_declaration: specifier ID SEM { $$ = NULL; }
    ;

/* declarationorator 装饰符 声明？格式*/
direct_declarator: ID {
        $$ = new BaseNode($1);
    }
    | ID MLB INT MRB {
        $$ = new BaseNode($3);
    }
    ;
func_declarator: ID LB parameter_list RB { 
        $$ = new BaseNode($1);
    }
    | ID LB RB {
        $$ = new BaseNode($1);
    }
    ;
parameter_list: parameter_list COM parameter_declaration {
        $1->getFinalCousinNode()->addCousinNode($3);
        $$ = $1;
    }
    | parameter_declaration { $$ = $1; }
    ;
parameter_declaration: specifier ID {
        $$ = new BaseNode($1);
    }
    | specifier {}
    ;


/* Statement 声明*/
compound_statement: BLB block_item_list BRB {
        BaseNode* temp = new BaseNode("compound statement");
        temp->addChildNode($2);
        $$ = temp;
    }
    | error BRB { yyerrok; }
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

statement: expression SEM { 
        BaseNode* temp = new BaseNode("expression statement");
        temp->addChildNode($1);
        $$ = temp;
    }
    | defination SEM { 
        BaseNode* temp = new BaseNode("defination statement");
        temp->addChildNode($1);
        $$ = temp;
    }
    | STRUCT ID ID SEM {$$ =NULL;}
    | compound_statement { $$=$1;}
    | RETURN expression SEM {
        BaseNode* temp = new BaseNode("return statement");
        temp->addChildNode($2);
        $$ = temp;
    }
    | RETURN SEM {
        BaseNode* temp = new BaseNode("return statement");
        $$ = temp;
    }
    | IF LB expression RB statement {  // ok
        BaseNode* temp = new BaseNode("select statement(if)");
        temp->addChildNode($3);
        $3->addCousinNode($5);
        $$ = temp;
    }
    | IF LB expression RB statement ELSE statement %prec LOWER_THAN_ELSE{
        BaseNode* temp = new BaseNode("select statement(if)");
        temp->addChildNode($3);
        $3->addCousinNode($5);
        BaseNode* else_node = new BaseNode("select statement(else)");
        else_node->addChildNode($7);
        temp->addCousinNode(else_node);
        $$ = temp;
    }
    | WHILE LB expression RB statement { //ok
        BaseNode* temp = new BaseNode("loop statement(while)");
        temp->addChildNode($3);
        $3->addCousinNode($5);
        $$ = temp;
    }

    | FOR LB SEM SEM RB statement{ //ok
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode($6);
        $$ = temp;
    }
    | FOR LB declaration_for SEM SEM RB statement{

    }
    | FOR LB SEM expression SEM RB statement{ //ok
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode($4);
        $4->addCousinNode($7);
        $$ = temp;
    }
    | FOR LB SEM SEM expression RB statement{ //OK
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode($5);
        $5->addCousinNode($7);
        $$ = temp;

    }
    | FOR LB declaration_for SEM expression SEM expression RB statement { //OK
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode($3);
        $3->addCousinNode($5);
        $5->addCousinNode($7);
        $7->addCousinNode($9);
        $$ = temp;
    }
    | FOR LB declaration_for SEM expression SEM RB statement  { //OK
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode($3);
        $3->addCousinNode($5);
        $5->addCousinNode($8);
        $$ = temp;
    }
    | FOR LB declaration_for SEM SEM expression RB statement  { //OK
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode($3);
        $3->addCousinNode($6);
        $6->addCousinNode($8);
        $$ = temp;
    }
    | FOR LB SEM expression SEM expression RB statement { //OK
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode($4);
        $4->addCousinNode($6);
        $6->addCousinNode($8);
        $$ = temp;
    }
    | error SEM { yyerrok; }  /*官方没报错 参考代码报错了不知道为啥*/
    ;


/* Local Definitions 参考代码上注释是这个*/
defination: specifier declaration_list  {
        $$ = $2;
    }
    | error SEM { yyerrok; }
    ;

declaration_list: declaration { $$ = $1; }
    | declaration COM declaration_list {
        $1->getFinalCousinNode()->addCousinNode($3);
        $$ = $1;
    }
    ;

declaration: direct_declarator { $$ = $1; }
    | direct_declarator ASSIGNOP expression {
        $1->addChildNode($3);
        $$ = $1;
    }
;


/* expressionression */
expression: expression ASSIGNOP expression {
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
            // char* s = "";
            // sprintf(s, "operator: %s", $2);
            BaseNode* temp = new BaseNode($2);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression ADD expression {
            BaseNode* temp = new BaseNode("operator: +", op);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression DEC expression {
            BaseNode* temp = new BaseNode("operator: -", op);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression MUL expression {
            BaseNode* temp = new BaseNode("operator: *", op);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression DIV expression {
            BaseNode* temp = new BaseNode("operator: /", op);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression MOD expression {
            BaseNode* temp = new BaseNode("operator: %", op);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression POWER expression {
            BaseNode* temp = new BaseNode("operator: ^", op);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | LB expression RB {
            $$ = $2;
        }
        | DEC expression {
            BaseNode* temp = new BaseNode("operator: -", op);
            temp->addChildNode($2);
            $$ = temp;
        }
        | NOT expression {
            BaseNode* temp = new BaseNode("operator: !", op);
            temp->addChildNode($2);
            $$ = temp;
        }
        | ID LB argument_expression_list RB {
            BaseNode* temp = new BaseNode($1);
            temp->addChildNode($3);
            $$ = temp;
        }
        | ID LB RB {
            $$ = new BaseNode($1);
        }
        | expression MLB expression MRB {
            $$ = NULL;
        }
        | ID {
            $$ = new BaseNode($1);
        }
        | ID MLB expression MRB {
            BaseNode* op = new BaseNode("operator: []");
            BaseNode* temp = new BaseNode($1);
            $$ = op;
            op->addChildNode(temp);
            temp->addCousinNode($3);
        }
        | ID '.' ID {}
        | INT {
            $$ = new BaseNode($1);
        }
        | MUL ID {}
        | error RB {yyerrok;}  /*当不可计算的表达式被读入后，上述第三条规则将识别出这个错误，解析将继续。yyerror 仍将被调用以打印出一条消息。第三条规则对应的动作是一个宏 yyerrok*/
        ;
argument_expression_list: expression {
            $$ = $1;
        }
        | argument_expression_list COM expression {
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
void yyerror(const char* s) {
	fprintf(stderr, "Parse error: At line %d. %s\n", yylineno, s);
	exit(1);
}

int main(int argc,char * argv[]){  //不确定语法的在哪里输出

    int c,j=0;
    yyin=fopen("./test.txt","r");
    // if(argc>=2){
    //     if()==NULL){
    //         printf("Can't open file %s\n",argv[1]);
    //         return 1;
    //     }
    // }
    do {
		yyparse();
	} while(!feof(yyin));
    fclose(yyin);
    root->printTree();
    return 0;
}
