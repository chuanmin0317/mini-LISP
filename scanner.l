%{
    #include "AST.h"
    #include "y.tab.h"

    extern "C"{
        int yylex();
    }
%}

%option nounput

%%

"+" {
    type_stack.push(PLUS);
    return yytext[0];
}

"-" {
    type_stack.push(MINUS);
    return yytext[0];
}

"/" {
    type_stack.push(DIVIDE);
    return yytext[0];
}

"*" {
    type_stack.push(MULTIPLY);
    return yytext[0];
}

"=" {
    type_stack.push(EQUAL);
    return yytext[0];
}

"<" {
    type_stack.push(SMALLER);
    return yytext[0];
}

">" {
    type_stack.push(GREATER);
    return yytext[0];
}

"mod" {
    type_stack.push(MODULUS);
    return mod;
}

"and" {
    type_stack.push(AND);
    return andop;
}

"or" {
    type_stack.push(OR);
    return orop;
}

"not" {
    type_stack.push(NOT);
    return notop;
}

"print-num" {
    type_stack.push(PRINT_NUM);
    return printnum;
}

"print-bool" {
    type_stack.push(PRINT_BOOL);
    return printbool;
}

"if" {
    type_stack.push(IF);
    return ifop;
}

"define" {
    type_stack.push(DEFINE);
    return define;
}

"fun" {
    type_stack.push(FUN);
    return fun;
}


[ \t\n\r] {;}

0|[1-9][0-9]*|-[1-9][0-9]* {
    yylval.ival = atoi(yytext);
    return number;
}

[a-z]([a-z]|[0-9]|"-")* {
    yylval.id = strdup(yytext);
    return id;
}

"#t"|"#f" {
    if (yytext[1] == 't'){
        yylval.boolval = true;
    }else{
        yylval.boolval = false;
    }
    return boolval;
}

. {
    return yytext[0];
}

%%