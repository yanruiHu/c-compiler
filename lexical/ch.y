%{
#include <stdio.h>
// #include "hdr.h"
#include <string.h>
#include <fstream>
#include "../grammar/Nodes.h"

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
        $$ = $2;
    }
    | specifier ';' {}
    | specifier func_declarator compound_statement {
        $2->addChildNode($3);
        $$ = $2;
    }
    | specifier func_declarator ';'  {
        $$ = $2;
    }
    | struct_specifier ';' {$$ = $1;}
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

struct_specifier: STRUCT ID '{' struct_declaration_list '}' { $$ = NULL; }
    ;

struct_declaration_list: struct_declaration { $$ = NULL; }
    | struct_declaration_list struct_declaration{ $$ = NULL; }
    ;

struct_declaration: specifier ID ';' { $$ = NULL; }
    ;

/* declarationorator 装饰符 声明？格式*/
direct_declarator: ID {
        $$ = new AST::DefineVarNode($1);
    }
    | ID '[' INT ']' {
        std::string s = "array name: ";
        s = s + $1 + ", length: " + $3;
        $$ = new AST::DefineVarNode(s);
    }
    ;
func_declarator: ID '(' parameter_list ')' { 
        $$ = new AST::DefineFuncNode($1);
    }
    | ID '(' ')' {
        $$ = new AST::DefineFuncNode($1);
    }
    ;
parameter_list: parameter_list ',' parameter_declaration {
        $1->getFinalCousinNode()->addCousinNode($3);
        $$ = $1;
    }
    | parameter_declaration { $$ = $1; }
    ;
parameter_declaration: specifier ID {
        $$ = new AST::DefineVarNode($1);
    }
    | specifier {}
    ;


/* Statement 声明*/
compound_statement: '{' block_item_list '}' {
        BaseNode* temp = new AST::StatementNode(AST::compoundation);
        temp->addChildNode($2);
        $$ = temp;
    }
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

statement: expression ';' { 
        BaseNode* temp = new AST::StatementNode(AST::expression);
        temp->addChildNode($1);
        $$ = temp;
    }
    | defination ';' { 
        BaseNode* temp = new AST::StatementNode(AST::defination);
        temp->addChildNode($1);
        $$ = temp;
    }
    | STRUCT ID ID ';' { $$ =NULL; }
    | compound_statement { $$=$1;}
    | RETURN expression ';' {
        BaseNode* temp = new AST::StatementNode(AST::return_stmt);
        temp->addChildNode($2);
        $$ = temp;
    }
    | RETURN ';' {
        BaseNode* temp = new AST::StatementNode(AST::return_stmt);
        $$ = temp;
    }
    | IF '(' expression ')' statement {  // ok
        BaseNode* temp = new AST::SelectNode(AST::if_stmt);
        temp->addChildNode($3);
        $3->addCousinNode($5);
        $$ = temp;
    }
    | IF '(' expression ')' statement ELSE statement %prec LOWER_THAN_ELSE{
        BaseNode* temp = new AST::SelectNode(AST::if_stmt);
        temp->addChildNode($3);
        $3->addCousinNode($5);
        BaseNode* else_node = new AST::SelectNode(AST::else_stmt);
        else_node->addChildNode($7);
        temp->addCousinNode(else_node);
        $$ = temp;
    }
    | WHILE '(' expression ')' statement { //ok
        BaseNode* temp = new AST::LoopNode(AST::while_loop);
        temp->addChildNode($3);
        $3->addCousinNode($5);
        $$ = temp;
    }

    | FOR '(' ';' ';' ')' statement{ //ok
        BaseNode* temp = new AST::LoopNode(AST::for_loop);
        temp->addChildNode($6);
        $$ = temp;
    }
    | FOR '(' declaration_for ';' ';' ')' statement{

    }
    | FOR '(' ';' expression ';' ')' statement{ //ok
        BaseNode* temp = new AST::LoopNode(AST::for_loop);
        temp->addChildNode($4);
        $4->addCousinNode($7);
        $$ = temp;
    }
    | FOR '(' ';' ';' expression ')' statement{ //OK
        BaseNode* temp = new AST::LoopNode(AST::for_loop);
        temp->addChildNode($5);
        $5->addCousinNode($7);
        $$ = temp;

    }
    | FOR '(' declaration_for ';' expression ';' expression ')' statement { //OK
        BaseNode* temp = new AST::LoopNode(AST::for_loop);
        temp->addChildNode($3);
        $3->addCousinNode($5);
        $5->addCousinNode($7);
        $7->addCousinNode($9);
        $$ = temp;
    }
    | FOR '(' declaration_for ';' expression ';' ')' statement  { //OK
        BaseNode* temp = new AST::LoopNode(AST::for_loop);
        temp->addChildNode($3);
        $3->addCousinNode($5);
        $5->addCousinNode($8);
        $$ = temp;
    }
    | FOR '(' declaration_for ';' ';' expression ')' statement  { //OK
        BaseNode* temp = new AST::LoopNode(AST::for_loop);
        temp->addChildNode($3);
        $3->addCousinNode($6);
        $6->addCousinNode($8);
        $$ = temp;
    }
    | FOR '(' ';' expression ';' expression ')' statement { //OK
        BaseNode* temp = new AST::LoopNode(AST::for_loop);
        temp->addChildNode($4);
        $4->addCousinNode($6);
        $6->addCousinNode($8);
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
        $$ = new AST::OperatorNode("=");
        $$->addChildNode($1);
        $1->addCousinNode($3);
    }
;


/* expressionression */
expression: expression '=' expression {
            BaseNode* temp = new AST::OperatorNode("=");
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression AND expression {
            BaseNode* temp = new AST::OperatorNode("&&");
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression OR expression {
            BaseNode* temp = new AST::OperatorNode("||");
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression RELOP expression {
            BaseNode* temp = new AST::OperatorNode($2);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression '+' expression {
            BaseNode* temp = new AST::OperatorNode("+");
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression '-' expression {
            BaseNode* temp = new AST::OperatorNode("-");
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression '*' expression {
            BaseNode* temp = new AST::OperatorNode("*");
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression '/' expression {
            BaseNode* temp = new AST::OperatorNode("/");
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression '%' expression {
            BaseNode* temp = new AST::OperatorNode("%");
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression '^' expression {
            BaseNode* temp = new AST::OperatorNode("^");
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | '(' expression ')' {
            $$ = $2;
        }
        | '-' expression {
            BaseNode* temp = new AST::OperatorNode("-");
            temp->addChildNode($2);
            $$ = temp;
        }
        | '!' expression {
            BaseNode* temp = new AST::OperatorNode("!");
            temp->addChildNode($2);
            $$ = temp;
        }
        | ID '(' argument_expression_list ')' {
            BaseNode* temp = new AST::CallFuncNode($1);
            temp->addChildNode($3);
            $$ = temp;
        }
        | ID '(' ')' {
            $$ = new AST::CallFuncNode($1);
        }
        | expression '[' expression ']' {
            $$ = NULL;
        }
        | ID {
            $$ = new AST::AssignVarNode($1);
        }
        | ID '[' expression ']' {
            BaseNode* op = new AST::OperatorNode("[]");
            BaseNode* temp = new AST::AssignVarNode($1);
            $$ = op;
            op->addChildNode(temp);
            temp->addCousinNode($3);
        }
        | ID '.' ID {}
        | INT {
            $$ = new AST::LiteralNode($1);
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
    if(root) root->printTree();
    if(root) delete root;
    return 0;
}
