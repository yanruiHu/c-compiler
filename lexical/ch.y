%{
#include <stdio.h>
// #include "hdr.h"
#include <string.h>
#include <fstream>
#include "../grammar/Nodes.h"
#include "../grammar/symbol/symbol.h"
#include "../grammar/InterMediate/InterMediate.h"
#include "../grammar/InterMediate/AsmGenerator.h"

using AST::BaseNode;
using SMB::StructTable;
class BaseNode;
extern char *yytext;
extern int yylex();
extern FILE * yyin;
void yyerror(const char* s);
BaseNode* root = NULL;
StructTable *struct_table = NULL;
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
%left <ast> '&'
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
%type <ast> compound_statement block_item_list declaration_for 
%type <ast> expression argument_expression_list statement defination declaration_list declaration
%type <ast> init_declarator_list init_declarator
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
        AST::BaseNode* stmt = new AST::StatementNode(AST::defination);
        AST::DefineVarNode* tmp = (AST::DefineVarNode*)$2;
        tmp->setAllSymbolType($1);
        stmt->addChildNode(tmp);
        $$ = stmt;
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
external_declaration_list: init_declarator_list { $$ = $1; }  //修改
    | external_declaration_list ',' init_declarator_list {
        $1->getFinalCousinNode()->addCousinNode($3);
        $$ = $1;
    }
    ;
init_declarator_list:init_declarator { $$ = $1; }
    | init_declarator_list ',' init_declarator {
        $1->getFinalCousinNode()->addCousinNode($3);
        $$ = $1;
    }
    ;
init_declarator: direct_declarator { $$ = $1; }
    | direct_declarator '=' INT {
        AST::BaseNode* op = new AST::OperatorNode("=", AST::assign);
        AST::BaseNode* tmp = new AST::LiteralNode($3);
        op->addChildNode($1);
        $1->addCousinNode(tmp);
        $$ = op;
    }
    ;
/*↑*/

/* specifiers 说明符*/
specifier: INT { $$ = strdup("int"); }
    | VOID { $$ = strdup("void"); }
    | INT '*' { $$ = strdup("int ptr"); }
    | VOID '*' { $$ = strdup("void ptr"); }
    ;

struct_specifier: STRUCT ID '{' struct_declaration_list '}' { 
        if(struct_table == NULL){
            struct_table = new SMB::StructTable();
        }
        SMB::StructSymbol* curr_struct = new SMB::StructSymbol($2,$4);
        struct_table->addStruct(curr_struct);
        $$ = NULL;
    }
    ;

struct_declaration_list: struct_declaration { $$ = $1; }
    | struct_declaration_list struct_declaration{
        $1->getFinalCousinNode()->addCousinNode($2); 
        $$ = $1; }
    ;

struct_declaration: specifier ID ';' { 
        AST::DefineVarNode* var = new AST::DefineVarNode($2);
        var->setAllSymbolType($1);
        $$ = var; }
    ;

/* declarationorator 装饰符 声明？格式*/
direct_declarator: ID {
        $$ = new AST::DefineVarNode($1);
    }
    | ID '[' INT ']' {
        // std::string s = "array name: ";
        // s = s + $1 + ", length: " + $3;
        AST::DefineVarNode* tmp = new AST::DefineVarNode($1);
        tmp->setAllSymbolType("array");
        tmp->setArrayLength($3);
        $$ = tmp;
    }
    ;
func_declarator: ID '(' parameter_list ')' { 
        $$ = new AST::DefineFuncNode($1, $3);
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
        AST::DefineVarNode* tmp = new AST::DefineVarNode($2);
        tmp->setAllSymbolType($1);
        $$ = tmp;
    }
    | specifier {
        AST::DefineVarNode* tmp = new AST::DefineVarNode("");
        tmp->setAllSymbolType($1);
        $$ = tmp;
    }
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
    | { $$ = NULL; }
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
    | STRUCT ID ID ';' { 
        BaseNode* temp = new AST::StatementNode(AST::defination);
        BaseNode* struct_def = new AST::DefineVarNode($3, $2);
        temp->addChildNode(struct_def);
        $$ = temp; }
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
        AST::SelectNode* temp = new AST::SelectNode(AST::if_stmt);
        temp->setBodyNode($5);
        // temp->addChildNode($5);
        temp->setCondNode($3);
        $$ = temp;
    }
    | IF '(' expression ')' statement ELSE statement %prec LOWER_THAN_ELSE{
        AST::SelectNode* temp = new AST::SelectNode(AST::if_stmt);
        temp->setBodyNode($5);
        // temp->addChildNode($5);
        temp->setCondNode($3);
        // AST::SelectNode* else_node = new AST::SelectNode(AST::else_stmt);
        // else_node->addChildNode($7);
        // temp->addCousinNode(else_node);
        temp->setElseNode($7);
        $$ = temp;
    }
    | WHILE '(' expression ')' statement { //ok
        BaseNode* temp = new AST::LoopNode("", AST::while_loop, $3);
        temp->addChildNode($5);
        $$ = temp;
    }

    | FOR '(' ';' ';' ')' statement{
        BaseNode* temp = new AST::LoopNode("", AST::for_loop, NULL, NULL, NULL);
        temp->addChildNode($6);
        $$ = temp;
    }
    | FOR '(' declaration_for ';' ';' ')' statement{
        BaseNode* temp = new AST::LoopNode("", AST::for_loop, NULL, $3, NULL);
        temp->addChildNode($7);
        $$ = temp;
    }
    | FOR '(' ';' expression ';' ')' statement{ 
        BaseNode* temp = new AST::LoopNode("", AST::for_loop, $4, NULL, NULL);
        temp->addChildNode($7);
        $$ = temp;
    }
    | FOR '(' ';' ';' expression ')' statement{
        BaseNode* temp = new AST::LoopNode("", AST::for_loop, NULL, NULL, $5);
        temp->addChildNode($7);
        $$ = temp;
    }
    | FOR '(' declaration_for ';' expression ';' expression ')' statement {
        BaseNode* temp = new AST::LoopNode("", AST::for_loop, $5, $3, $7);
        temp->addChildNode($9);
        $$ = temp;
    }
    | FOR '(' declaration_for ';' expression ';' ')' statement  { //OK
        BaseNode* temp = new AST::LoopNode("", AST::for_loop, $5, $3, NULL);
        temp->addChildNode($8);
        $$ = temp;
    }
    | FOR '(' declaration_for ';' ';' expression ')' statement  { //OK
        BaseNode* temp = new AST::LoopNode("", AST::for_loop, NULL, $3, $6);
        temp->addChildNode($8);
        $$ = temp;
    }
    | FOR '(' ';' expression ';' expression ')' statement { //OK
        BaseNode* temp = new AST::LoopNode("", AST::for_loop, $4, NULL, $6);
        temp->addChildNode($8);
        $$ = temp;
    }
    | error ';' { yyerrok; }  /*官方没报错 参考代码报错了不知道为啥*/
    ;


/* Local Definitions 参考代码上注释是这个*/
defination: specifier declaration_list  {
        if ($2->getASTNodeType() == AST::op) {
            AST::OperatorNode* tmp = (AST::OperatorNode*)$2;
            tmp->setAllSymbolType($1);
        } else {
            AST::DefineVarNode* tmp = (AST::DefineVarNode*)$2;
            tmp->setAllSymbolType($1);
        }
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
        $$ = new AST::OperatorNode("=", AST::assign);
        $$->addChildNode($1);
        $1->addCousinNode($3);
    }
;


/* expressionression */
expression: expression '=' expression {
            AST::OperatorNode* temp = new AST::OperatorNode("=", AST::assign);
            if ($1->getASTNodeType() == AST::op) {
                AST::OperatorNode *tmp = (AST::OperatorNode *)$1;
                if (tmp->getOpType() == AST::get_member) {
                    temp->setOpType(AST::assign_member);
                } else if (tmp->getOpType() == AST::get_arr_var) {
                    temp->setOpType(AST::assign_arr);
                }
            }
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression AND expression {
            BaseNode* temp = new AST::OperatorNode("&&", AST::and_op);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression OR expression {
            BaseNode* temp = new AST::OperatorNode("||", AST::or_op);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression RELOP expression {
            BaseNode* temp = new AST::OperatorNode($2, AST::relop);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression '+' expression {
            BaseNode* temp = new AST::OperatorNode("+", AST::add);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression '-' expression {
            BaseNode* temp = new AST::OperatorNode("-", AST::minus);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression '*' expression {
            BaseNode* temp = new AST::OperatorNode("*", AST::multi);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression '/' expression {
            BaseNode* temp = new AST::OperatorNode("/", AST::div);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression '%' expression {
            BaseNode* temp = new AST::OperatorNode("%", AST::mod);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | expression '^' expression {
            BaseNode* temp = new AST::OperatorNode("^", AST::pow);
            temp->addChildNode($1);
            $1->addCousinNode($3);
            $$ = temp;
        }
        | '(' expression ')' {
            $$ = $2;
        }
        | '-' expression {
            BaseNode* temp = new AST::OperatorNode("-", AST::negative);
            temp->addChildNode($2);
            $$ = temp;
        }
        | '!' expression {
            BaseNode* temp = new AST::OperatorNode("!", AST::not_op);
            temp->addChildNode($2);
            $$ = temp;
        }
        | '&' ID {
            BaseNode* op = new AST::OperatorNode("&", AST::get_address);
            BaseNode* temp = new AST::AssignVarNode($2);
            $$ = op;
            op->addChildNode(temp);
        }
        | ID '(' argument_expression_list ')' {
            AST::CallFuncNode* temp = new AST::CallFuncNode($1);
            temp->setVarList($3);
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
            BaseNode* op = new AST::OperatorNode("[]", AST::get_arr_var);
            BaseNode* temp = new AST::AssignVarNode($1);
            $$ = op;
            op->addChildNode(temp);
            temp->addCousinNode($3);
        }
        | ID GETMEMBER ID {
            BaseNode* op = new AST::OperatorNode(".", AST::get_member);
            AST::AssignVarNode * var1 = new AST::AssignVarNode($1);
            AST::AssignVarNode * var2 = new AST::AssignVarNode($3);
            op->addChildNode(var1);
            var1->addCousinNode(var2);
            $$ = op;
        }
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
std::string replaceExtName(char* filename) {
    int dotIndex = 0;
    int nameLength = strlen(filename);
    for (int i = nameLength - 1; i >= 0; i--) {
        if (filename[i] == '.') {
            dotIndex = i;
            break;
        }
    }
    char* buf = new char[dotIndex];
    strncpy(buf, filename, dotIndex);
    std::string rev(buf);
    rev += ".asm";
    return rev;
}
int main(int argc,char * argv[]){  //不确定语法的在哪里输出

    int c,j=0;
    char * filename =NULL;
    filename=argv[1];
    std::cout<<"filename"<<filename<<std::endl;
    yyin=fopen(filename,"r");
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
    // SMB::SymbolTable* root_symbol_table = new SMB::SymbolTable(NULL,false);
    // SMB::tree(root_symbol_table,root,0);
    IM::InterMediate *im = new IM::InterMediate(root, struct_table);
    im->generate(root, im->getTable());
   
    im->print();
    //add ASM
    AsmGenerator* asmgenerator = new AsmGenerator(im->getQuads(), im->getTempVars(), im->getTable());
    asmgenerator->generate();
    // if (flag_print_asm) {
    std::cout << asmgenerator->getAsmCode();
    // }

    std::string outfilename = replaceExtName(filename);
    std::ofstream outasm(outfilename);

    outasm << asmgenerator->getAsmCode();

    if(root) delete root;
    return 0;
}
