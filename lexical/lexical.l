%x COMMENT
%{
#include "y.tab.h"
#include <stdio.h>
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
{id}                                {yylval.str=strdup(yytext);return(ID);}
{int}                               {yylval.str=strdup(yytext);return(INT);}

"main"                              {yylval.str=strdup(yytext);return(ID);}
"void"                              {return(VOID);}
"if"                                {return(IF);}
"else"                              {return(ELSE);}
"for"                               {return(FOR);}
"while"                             {return(WHILE);}
"return"                            {return(RETURN);}
"struct"                            {return(STRUCT);}
"."                                 {return(GETMEMBER);}
(>=)|(<=)|(==)|(!=)|<|>             {yylval.str=strdup(yytext);return(RELOP);}


"&&"                                {return(AND);}
"||"                                {return(OR);}  

    
{int}{id}                           {return(ERRID);}
.                                   {return(ERRORCHAR);}

%%
int yywrap(){
    return 1;
}
