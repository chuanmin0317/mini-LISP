%{
    #include "AST.h"

    AST_Node* root;
    map<string, AST_Node*> global_var_map;
    stack<ASType> type_stack;

    extern "C"{
        extern int yylex(void);
        void yyerror(const char* messages);
    }

%}
%union{
    int ival;
    bool boolval;
    char* id;
    AST_Node* node;
}


%type <node> PROGRAM
%type <node> STMT STMT_LIST PRINT-STMT DEF-STMT
%type <node> EXP EXP_LIST
%type <node> NUM-OP LOGICAL-OP
%type <node> PLUS MINUS MULTIPLY DIVIDE MODULUS GREATER SMALLER EQUAL
%type <node> AND-OP OR-OP NOT-OP 
%type <node> VARIABLE VARIABLE_LIST
%type <node> PARAM PARAM_LIST
%type <node> FUN-EXP FUN-CALL FUN-IDs FUN-BODY FUN-NAME FUN_STMT_LIST FUN_STMT
%type <node> IF-EXP TEST-EXP THEN-EXP ELSE-EXP

%token <ival> number
%token <boolval> boolval
%token <id> id
%token mod
%token andop orop notop
%token printnum printbool define fun ifop

%left '>' '<' '='
%left '+''-'
%left '*''/' mod
%token '('')''['']'
%%

PROGRAM : STMT STMT_LIST {
            type_stack.push(ROOT);
            $$ = creatNode($1, $2);
            root = $$;
        }
        ;

STMT_LIST : STMT STMT_LIST {
              type_stack.push(ROOT);
              $$ = creatNode($1, $2);
          } 
          | { $$ = nullptr; }
          ;

STMT : EXP
     | DEF-STMT
     | PRINT-STMT
     ;

//print statement
PRINT-STMT  : '(' printnum EXP ')' { 
                type_stack.push(PRINT_NUM);
                $$ = creatNode($3, nullptr);
            }
            | '(' printbool EXP ')' {
                type_stack.push(PRINT_BOOL);
                $$ = creatNode($3, nullptr);
            }
            ;

EXP_LIST : EXP EXP_LIST {
             AST_Node* new_node = new AST_Node;
             new_node->type = type_stack.top();
             new_node->left = $1;
             new_node->right = $2;
             $$ = new_node;
         }
         | { $$ = nullptr; }
         ;

EXP : boolval {
        ASTBool* new_node = new ASTBool;
        new_node->type = BOOLVAL;
        new_node->boolval = $1;
        $$ = (AST_Node*)new_node;
    }
    | number {
        ASTNumber* new_node = new ASTNumber;
        new_node->type = NUMBER;
        new_node->number = $1;
        $$ = (AST_Node*)new_node;
    }
    | VARIABLE
    | NUM-OP
    | LOGICAL-OP
    | IF-EXP
    | FUN-EXP
    | FUN-CALL
    ;

//numerical operations
NUM-OP  : PLUS
        | MINUS 
        | MULTIPLY 
        | DIVIDE 
        | MODULUS 
        | GREATER
        | SMALLER 
        | EQUAL
        ;

PLUS : '(' '+' EXP EXP EXP_LIST ')' { $$ = creatNode($3, $4, $5); }
MINUS : '(' '-' EXP EXP ')' { $$ = creatNode($3, $4); }
MULTIPLY : '(' '*' EXP EXP EXP_LIST ')' { $$ = creatNode($3, $4, $5); }
DIVIDE : '(' '/' EXP EXP ')' { $$ = creatNode($3, $4); }
MODULUS : '(' mod EXP EXP ')' { $$ = creatNode($3, $4); }
GREATER : '(' '>' EXP EXP ')' { $$ = creatNode($3, $4); }
SMALLER : '(' '<' EXP EXP ')' { $$ = creatNode($3, $4); }
EQUAL : '(' '=' EXP EXP EXP_LIST ')' { $$ = creatNode($3, $4, $5); }

//logical operations
LOGICAL-OP  : AND-OP
            | OR-OP
            | NOT-OP
            ;

AND-OP : '(' andop EXP EXP EXP_LIST ')' { $$ = creatNode($3, $4, $5); }
OR-OP : '(' orop EXP EXP EXP_LIST ')' { $$ = creatNode($3, $4, $5); }
NOT-OP : '(' notop EXP ')' { $$ = creatNode($3, nullptr); }

//define statement
DEF-STMT : '(' define VARIABLE EXP ')' { $$ = creatNode($3, $4); }

VARIABLE : id {
             ASTID* new_node = new ASTID;
             new_node->type = ID;
             new_node->id = $1;
             $$ = (ASTID*)new_node;
         }

//function
FUN-EXP : '(' fun FUN-IDs FUN-BODY ')' { $$ = creatNode($3, $4); }

FUN-IDs : '(' VARIABLE_LIST ')' { $$ = $2; }
    | '(' ')' {}
    ;

FUN_STMT_LIST : FUN_STMT FUN_STMT_LIST {
                  type_stack.push(FUN_BODY);
                  $$ = creatNode($1, $2);
              }
              | { $$ = nullptr; }

FUN_STMT : EXP | DEF-STMT
         ;

FUN-BODY : FUN_STMT_LIST
    ;

FUN-CALL : '(' FUN-EXP PARAM_LIST ')' {
             type_stack.push(FUN_DEF_CALL);
             $$ = creatNode($2, $3);
         }
         | '(' FUN-NAME PARAM_LIST ')' {
             type_stack.push(FUN_CALL);
             $$ = creatNode($2, $3);
         }
         ;

PARAM_LIST : PARAM PARAM_LIST {
               type_stack.push(NUMBER);
               $$ = creatNode($1, $2);
           }
           | { $$ = nullptr; }
           ;

PARAM : EXP
    ;

FUN-NAME : VARIABLE
    ;

VARIABLE_LIST : VARIABLE VARIABLE_LIST {
                  type_stack.push(ID);
                  $$ = creatNode($1, $2);
              }
              | { $$ = nullptr; }
              ;

//if expression
IF-EXP : '(' ifop TEST-EXP THEN-EXP ELSE-EXP ')' {
    ASTIF* new_node = new ASTIF;
    new_node->type = type_stack.top();
    new_node->cond_exp = $3;
    new_node->left = $4;
    new_node->right = $5;
    type_stack.pop();
    $$ = (AST_Node*)new_node;
}

TEST-EXP : EXP
         ;

THEN-EXP : EXP
         ;

ELSE-EXP : EXP
         ;
%%

void yyerror(const char* message){
    cout << message << endl;
}

int main(void) {
    yyparse();
    Traversal(root, global_var_map);
//    printAST(root);
    return 0;
}
