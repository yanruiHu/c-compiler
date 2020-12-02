%x COMMENT
%{
#include "y.tab.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
%}

delim   [ \t\n]
whitespace  {delim}+
digit   [0-9]
letter  [A-Za-z_]
id  {letter}({letter}|{digit})*
int   ([1-9]|[1-9]([0-9])+|0)

%%
"/*"                                {BEGIN(COMMENT);}
<COMMENT>"*/"                       {BEGIN(INITIAL);}
<COMMENT>{whitespace}               {printf("inside commenet whitespace\n");}
<COMMENT>([^*]|\en)+|.
<COMMENT><<EOF>>                    {printf("Unterminated comment\n");return 0;}
"//".*\n

{whitespace}                        {;}
{id}                                {yylval.str=atof(yytext);return(ID);}
{int}                               {yylval.str=atof(yytext);return(INT);}

"main"                              {return(MAIN);}
"void"                              {return(VOID);}
"if"                                {return(IF);}
"else"                              {return(ELSE);}
"for"                               {return(FOR);}
"while"                             {return(WHILE);}
"return"                            {return(RETURN);}
"struct"                            {return(STRUCT);}
"."                                 {return(GETMEMBER);}
(>=)|(<=)|(==)|(!=)|<|>             {yylval.str=strdup(yytext);return(RELOP);}
"="                                 {return(ASSIGNOP);}
"!"                                 {return(NOT);} 
"&&"                                {return(AND);}
"||"                                {return(OR);}  
"+"                                 {return(ADD);}
"-"                                 {return(DEC);}
"*"                                 {return(MUL);}
"/"                                 {return(DIV);}
"%"                                 {return(MOD);}
"^"                                 {return(POWER);}
","                                 {return(COM);}
";"                                 {return(SEM);}
"("                                 {return(LB);}
")"                                 {return(RB);}
"["                                 {return(MLB)}
"]"                                 {return(MRB)}
"{"                                 {return(BLB);}
"}"                                 {return(BRB);}
{int}{id}                           {return(ERRID);}
.                                   {return(ERRORCHAR);}

%%
int yywrap(){
    return 1;
}
