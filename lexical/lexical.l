%{
#include "y.tab.h"
#include "hdr.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LT 1
#define LE 2
#define GT 3
#define GE 4
#define EQ 5

#define ADD 6
#define DEC 7
#define MUL 8
#define DIV 9

#define SEM 10

#define LB 11
#define RB 12
#define BLB 13
#define BRB 14
#define VOID   42
#define MAIN   43
#define TYPE   44
#define WHILE   18
#define DO  19
#define IF  20
#define THEN    21
#define ELSE    22
#define FOR 23
#define ID      24
#define NUMBER  25

#define REAL8   26
#define REAL10  27
#define REAL16  28

#define INT8    29
#define INT10   30
#define INT16   31

#define NEWLINE 40
#define ERRORCHAR 41


%}

delim   [ \t\n]
whitespace  {delim}+
digit   [0-9]
letter  [A-Za-z_]
id  {letter}({letter}|{digit})*
number  {digit}+(\.{digit}+)?([eE][+-]?{digit}+)?

int8    (0([0-7])+)
int10   ([1-9]|[1-9]([0-9])+|0)
int16   (0[xX]([A-Fa-f0-9])+)

real8   (0([0-7])+\.([0-7])*)
real10  (([1-9]|[1-9]([0-9])+)\.[0-9]+|0\.([0-9])+)
real16  0[xX]([A-Fa-f0-9])+\.([A-Fa-f0-9])*

%%
{whitespace}    {;}
(while|WHILE)   {return (WHILE);}
(main|MAIN)   {return (MAIN);}
(void|VOID)   {return (VOID);}
(int|TYPE)   {return (TYPE);}
(do|DO)     {return (DO);}
(if|IF)         {return (IF);}
(then|THEN)         {return (THEN);}
(else|ELSE)         {return (ELSE);}
(for|FOR)         {return (FOR);}

{id}        {yylval.symp=symlook(yytext);return (ID);}


{int8}      {return (INT8);}
{int10}     {yylval.dval = atof(yytext);return (INT10);}
{int16}     {return (INT16);}

{real8}     {return (REAL8);}
{real10}    {return (REAL10);}
{real16}    {return (REAL16);}

"<"     {return (LT);}
"<="             {return (LE);}
">"             {return (GT);}
">="             {return (GE);}
"=="             {return (EQ);} 
"!="              {return (NE);}

    /* 
    * Editor:Liuyin
    * content:
    * "="     { return(ASSIGNOP); }
    * (>=)|(<=)|(==)|(!=)|<|>           { yylval.str=strdup(yytext); return(RELOP); } 
                                            strdup cmp symlook? 
    * "!"     {return (NOT)}    
    * "||"    { return(OR); }   
    * "&&"    { return(AND); }                                 
    */
"+"             {return (ADD);}
"-"             {return (DEC);}
"*"             {return (MUL);}
"/"             {return (DIV);}
";"             {return (SEM);}
"("             {return (LB);}
")"             {return (RB);}
    /*
    * "[" {return (MLB)}
    * "]" {return (MRB)}
    */
"{"      {return (BLB);}
"}"      {return (BRB);}

.       {return (ERRORCHAR);}

%%
int yywrap(){
    return 1;
}

void writeout(int c){
    switch(c){
        case ERRORCHAR:fprintf(yyout,"(ERRORCHAR,\"%s\")",yytext);
            break;
case INT10:fprintf(yyout,"(INT10,\"%s\",\"%s\")",yytext,yytext);
                        break;

 case INT16:fprintf(yyout,"(INT16,\"%s\")",yytext);
                        break;

            case INT8:fprintf(yyout,"(INT8,\"%s\")",yytext);
                        break; 
        case WHILE:fprintf(yyout,"(WHILE,\"%s\")",yytext);
                        break; 
        case TYPE:fprintf(yyout,"(TYPE,\"%s\")",yytext);
                        break; 
        case MAIN:fprintf(yyout,"(MAIN,\"%s\")",yytext);
                        break; 
        case VOID:fprintf(yyout,"(VOID,\"%s\")",yytext);
                        break; 
        case DO:fprintf(yyout,"(DO,\"%s\")",yytext);
                        break; 
        case IF:fprintf(yyout,"(IF,\"%s\")",yytext);
                        break; 
        case THEN:fprintf(yyout,"(THEN,\"%s\")",yytext);
                        break; 
        case ELSE:fprintf(yyout,"(ELSE,\"%s\")",yytext);
                        break; 
        case FOR:fprintf(yyout,"(FOR,\"%s\")",yytext);
                        break; 
        case ID:fprintf(yyout,"(ID,\"%s\",\"%p\")",yytext,symlook(yytext));
                        break; 
        //case NUMBER:fprintf(yyout,"(NUMBER,\"%s\")",yytext);
                //      break;
        case RB:fprintf(yyout,"(RB,\"%s\")",yytext);
                        break; 
        case LB:fprintf(yyout,"(LB,\"%s\")",yytext);
                        break; 
        case SEM:fprintf(yyout,"(SEM,\"%s\")",yytext);
                        break; 
        case DIV:fprintf(yyout,"(DIV,\"%s\")",yytext);
                        break; 
        case MUL:fprintf(yyout,"(MUL,\"%s\")",yytext);
                        break; 
        case DEC:fprintf(yyout,"(DEC,\"%s\")",yytext);
                        break; 
        case ADD:fprintf(yyout,"(ADD,\"%s\")",yytext);
                        break; 
        case EQ:fprintf(yyout,"(EQ,\"%s\")",yytext);
                        break; 
        case GE:fprintf(yyout,"(GE,\"%s\")",yytext);
                        break; 
        case GT:fprintf(yyout,"(GT,\"%s\")",yytext);
                        break; 
        case LE:fprintf(yyout,"(LE,\"%s\")",yytext);
                        break; 
        case LT:fprintf(yyout,"(LT,\"%s\")",yytext);
                        break; 
        case BLB:fprintf(yyout,"(BLB,\"%s\")",yytext);
            break;
        case BRB:fprintf(yyout,"(BRB,\"%s\")",yytext);
            break;
        case NEWLINE:fprintf(yyout,"\n");
            break; 
        case REAL8:fprintf(yyout,"(REAL8,\"%s\")",yytext);
                        break; 
        case REAL10:fprintf(yyout,"(REAL10,\"%s\")",yytext);
                        break; 
        case REAL16:fprintf(yyout,"(REAL16,\"%s\")",yytext);
                        break; 
        default:break; 

        }
    return;
}

struct symtab *
symlook(char *s){
        char *p;
        struct symtab *sp;
        for(sp=symtab;sp<&symtab[NSYMS];sp++){
                if(sp->name && !strcmp(sp->name,s))
                        return sp;
        if(!sp->name){
                sp->name=strdup(s);
                return sp;
                }
        }
        perror("Too many symbols.");
        exit(1);
}
/* 
* Editor:Liuyin
* Content: delete main()
// int main(int argc,char ** argv){  //写入文件
//     int c,j=0;
//     if(argc>=2){
//         if((yyin=fopen(argv[1],"r"))==NULL){
//             printf("Can't open file %s\n",argv[1]);
//             return 1;
//         }
//         if(argc>=3){
//             yyout=fopen(argv[2],"w");
//         }
//     }
//     while(c=yylex()){
//         writeout(c);
//         j++;
//         if(j%5==0)
//             writeout(NEWLINE);
//         }
//     if(argc>=2){
//         fclose(yyin);
//         if(argc>=3)
//             fclose(yyout);
//     }
//     return 0;
// }
