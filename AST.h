#ifndef _AST_H_
#define _AST_H_

#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
#include <stack>
using namespace std;


enum ASType{
    ROOT,

    //PRINT
    PRINT_NUM,
    PRINT_BOOL,

    //VARIABLE
    BOOLVAL,
    NUMBER,
    ID,

    //NUM-OP
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    MODULUS,
    SMALLER,
    GREATER,
    EQUAL,
    
    //LOGICAL-OP
    AND,
    OR,
    NOT,

    //IF-EXP
    IF,

    //FUNCTION
    FUN,
    FUN_DEF_CALL,
    FUN_CALL,
    FUN_BODY,

    //DEFINE
    DEFINE
};

class AST_Node{
    public:
    ASType type;
    AST_Node *left, *right;
};

class ASTValue : public AST_Node{
    public:
    int number;
    string id;
    bool boolval;
};

class ASTNumber : public AST_Node{
    public:
    int number;
};

class ASTID : public AST_Node{
    public:
    string id;
};

class ASTBool : public AST_Node{
    public:
    bool boolval;
};

class ASTIF : public AST_Node{
    public:
    AST_Node* cond_exp;
};

extern stack<ASType> type_stack;
extern map<string, AST_Node*> global_var_map;

AST_Node* creatNode(AST_Node* exp1, AST_Node* exp2);
AST_Node* creatNode(AST_Node* exp1, AST_Node* exp2, AST_Node* exp3);
ASTValue* Traversal(AST_Node* current, map<string, AST_Node*> &local_var_map);
void printAST(AST_Node* node, const string& label = "ROOT", int depth = 0);
#endif