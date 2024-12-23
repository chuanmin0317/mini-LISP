#include "AST.h"

stack<AST_Node*> global_param_stk;

AST_Node* creatNode(AST_Node* expr1, AST_Node* expr2){
    AST_Node* node = new AST_Node;
    node->type = type_stack.top();
    node->left = expr1;
    node->right = expr2;
    type_stack.pop();
    return node;
}

AST_Node* creatNode(AST_Node* expr1, AST_Node* expr2, AST_Node* expr3){
    AST_Node* node = new AST_Node;
    node->type = type_stack.top();
    node->left = expr1;
    AST_Node* rightNode = new AST_Node;
    rightNode->type = type_stack.top();
    rightNode->left = expr2;
    rightNode->right = expr3;
    node->right = rightNode;
    type_stack.pop();
    return node;
}

string getASTTypeName(ASType type) {
    switch (type) {
        case ROOT: return "ROOT";
        case PRINT_NUM: return "PRINT_NUM";
        case PRINT_BOOL: return "PRINT_BOOL";
        case BOOLVAL: return "BOOLVAL";
        case NUMBER: return "NUMBER";
        case ID: return "ID";
        case PLUS: return "PLUS";
        case MINUS: return "MINUS";
        case MULTIPLY: return "MULTIPLY";
        case DIVIDE: return "DIVIDE";
        case MODULUS: return "MODULUS";
        case SMALLER: return "SMALLER";
        case GREATER: return "GREATER";
        case EQUAL: return "EQUAL";
        case AND: return "AND";
        case OR: return "OR";
        case NOT: return "NOT";
        case IF: return "IF";
        case FUN: return "FUN";
        case FUN_DEF_CALL: return "FUN_DEF_CALL";
        case FUN_CALL: return "FUN_CALL";
        case FUN_BODY: return "FUN_BODY";
        case DEFINE: return "DEFINE";
        default: return "UNKNOWN";
    }
}

void printAST(AST_Node* node, const string& label, int depth) {
    for (int i = 0; i < depth; ++i) {
        cout << "  ";
    }

    if (!node) {
        cout << label << ": nullptr" << endl; 
        return;
    }

    cout << label << ": " << getASTTypeName(node->type) << endl;

    printAST(node->left, "LEFT", depth + 1);
    printAST(node->right, "RIGHT", depth + 1);
}

int calNumber(AST_Node* current, map<string, AST_Node*> &local_var_map){
    if (!current) return 1;
    int result;
    ASTValue* temp;
    switch (current->type)
    {
    case PLUS:
        if (current->right){
            result = calNumber(current->left, local_var_map) + calNumber(current->right, local_var_map);
        }else{
            result = calNumber(current->left, local_var_map);
        }
        break;
    case MINUS:
        result = calNumber(current->left, local_var_map) - calNumber(current->right, local_var_map);
        break;
    case MULTIPLY:
        if (current->right){
            result = calNumber(current->left, local_var_map) * calNumber(current->right, local_var_map);
        }else{
            result = calNumber(current->left, local_var_map);
        }
        break;
    case DIVIDE:
        result = calNumber(current->left, local_var_map) / calNumber(current->right, local_var_map);
        break;
    case MODULUS:
        result = calNumber(current->left, local_var_map) % calNumber(current->right, local_var_map);
        break;
    case NUMBER:
        result = ((ASTValue*)current)->number;
        break;
    case FUN:
    case FUN_DEF_CALL:
    case FUN_CALL:
    case ID:
        temp = Traversal(current, local_var_map);
        if (temp->type != NUMBER){
            cout << "Type Error: Except 'number' but got 'boolean'\n" << endl;
            exit(0);
        }
        return temp->number;
        break;
    case SMALLER:
    case GREATER:
    case EQUAL:
    case AND:
    case OR:
    case NOT:
    case BOOLVAL:
        cout << "Type Error: Except 'number' but got 'boolean'\n" << endl;
        exit(0);
        break;
    default:
        result = Traversal(current, local_var_map)->number;
    }

    return result;
}

bool isEqual(AST_Node* current, map<string, AST_Node*> &local_var_map){
    if (current->right){
        if (calNumber(current->left, local_var_map) == calNumber(current->right->left, local_var_map)){
            return isEqual(current->right, local_var_map);
        }else{
            return false;
        }
    }else{
        return true;
    }

}

bool calLogical(AST_Node* current, map<string, AST_Node*> &local_var_map){
    if (!current) return true;
    bool result;
    ASTValue* temp;
    switch (current->type)
    {
    case SMALLER:
        result = calNumber(current->left, local_var_map) < calNumber(current->right, local_var_map);
        break;
    case GREATER:
        result = calNumber(current->left, local_var_map) > calNumber(current->right, local_var_map);
        break;
    case EQUAL:
        result = isEqual(current, local_var_map);
        break;
    case AND:
        if (current->right){
            result = calLogical(current->left, local_var_map) && calLogical(current->right, local_var_map);
        }else{
            result = calLogical(current->left, local_var_map);
        }
        break;
    case OR:
        if (current->right){
            result = calLogical(current->left, local_var_map) || calLogical(current->right, local_var_map);
        }else{
            result = calLogical(current->left, local_var_map);
        }
        break;
    case NOT:
        result = !calLogical(current->left, local_var_map);
        break;
    case BOOLVAL:
        result = ((ASTBool*)current)->boolval;
        break;
    case PLUS:
    case MINUS:
    case MULTIPLY:
    case DIVIDE:
    case MODULUS:
    case NUMBER:
        cout << "Type Error: Except 'boolean' but got 'number'\n" << endl;
        exit(0);
        break;
    case FUN:
    case FUN_DEF_CALL:
    case FUN_CALL:
    case ID:
        temp = Traversal(current, local_var_map);
        if (temp->type != BOOLVAL){
            cout << "Type Error: Except 'boolean' but got 'number'\n" << endl;
            exit(0);
        }
        return temp->number;
        break;
    default:
        result = Traversal(current, local_var_map)->boolval;
    }

    return result;
}

void defineID(AST_Node* current, map<string, AST_Node*> &local_var_map){
    string variable = ((ASTID*)current->left)->id;
    if (local_var_map[variable]){
        cout << "redefine id: " << variable << endl;
        exit(0);
    }else{
        local_var_map[variable] = current->right;
    }
}

ASTValue* function(AST_Node* fun_expr, AST_Node* params, map<string, AST_Node*> &local_var_map){
    AST_Node* fun_id = fun_expr->left;
    AST_Node* fun_body = fun_expr->right;
    AST_Node* fun_params = params;
    map<string, AST_Node*> fun_id_map = local_var_map;
    stack<AST_Node*> param_stk;
    stack<string> id_stk;
    //params == null
    if (!params){
        if (!global_param_stk.empty()){
            while(fun_id){
                id_stk.push(((ASTID*)fun_id->left)->id);
                fun_id = fun_id->right;
            }

            while (id_stk.size()){
                fun_id_map[id_stk.top()] = global_param_stk.top();
                id_stk.pop();
                global_param_stk.pop();
            }    
        }
        return Traversal(fun_body, fun_id_map);
    }

    //params != null
    while(fun_params){
        if (fun_params->left->type == FUN){
            param_stk.push(fun_params->left);
        }else{
            param_stk.push((AST_Node*)Traversal(fun_params->left, fun_id_map));
        }
        fun_params = fun_params->right;
    }
    
    while(fun_id){
        id_stk.push(((ASTID*)fun_id->left)->id);
        fun_id = fun_id->right;
    }

    if (id_stk.size() == param_stk.size()){
        while (!id_stk.empty()){
            fun_id_map[id_stk.top()] = param_stk.top();
            id_stk.pop();
            param_stk.pop();
        }
    }else{
        cout << "parameter numbers don't match: need " << id_stk.size() << " but " << param_stk.size() << endl;
        exit(0);
    }

    return Traversal(fun_body, fun_id_map);
}

ASTValue* functionBody(AST_Node* current, map<string, AST_Node*> &local_var_map){
    while(current->right){
        Traversal(current->left, local_var_map);
        current = current->right;
    }

    return Traversal(current->left, local_var_map);
}

ASTValue* functionClosure(AST_Node* current, map<string, AST_Node*> &local_var_map){
    AST_Node* temp = current;
    map<string, AST_Node*> fun_id_map = local_var_map;
    while(fun_id_map[((ASTID*)temp->left)->id]->type != FUN){
        AST_Node* params = temp->right;
        while(params){
            if (params->left->type == FUN){
                global_param_stk.push(params->left);
            }else{
                AST_Node* temp = (AST_Node*)Traversal(params->left, fun_id_map);
                global_param_stk.push(temp);
            }
            params = params->right;
        }
        temp = local_var_map[((ASTID*)temp->left)->id];
    }
    
    return function(local_var_map[((ASTID*)temp->left)->id], temp->right, local_var_map);
}

AST_Node* cond_determine(AST_Node* current, map<string, AST_Node*> &local_var_map){
    bool result;
    result = calLogical(((ASTIF*)current)->cond_exp, local_var_map);
    if (result){
        return current->left;
    }else{
        return current->right;
    }
}

ASTValue* Traversal(AST_Node* current, map<string, AST_Node*> &local_var_map){
    if (!current) return nullptr;
    ASTValue* result = new ASTValue;
    switch (current->type)
    {
    case ROOT:
        Traversal(current->left, local_var_map);
        Traversal(current->right, local_var_map);
        break;
    case PRINT_NUM:
        result = Traversal(current->left, local_var_map);
        cout << result->number << endl;
        break;
    case PRINT_BOOL:
        result = Traversal(current->left, local_var_map);
        if (result->boolval){
            cout << "#t" << endl;
        }else{
            cout << "#f" << endl;
        }
        break;
    case ID:
        if (!local_var_map[((ASTID*)current)->id]){
            cout << "can't find: " << ((ASTID*)current)->id << endl;
            exit(0);
        }
        result = Traversal(local_var_map[((ASTID*)current)->id], local_var_map);
        break;
    case PLUS:
    case MINUS:
    case MULTIPLY:
    case DIVIDE:
    case MODULUS:
    case NUMBER:
        result->type = NUMBER;
        result->number = calNumber(current, local_var_map);
        break;
    case SMALLER:
    case GREATER:
    case EQUAL:
    case AND:
    case OR:
    case NOT:
    case BOOLVAL:
        result->type = BOOLVAL;
        result->boolval = calLogical(current, local_var_map);
        break;
    case IF:
        result = Traversal(cond_determine(current, local_var_map), local_var_map);
        break;
    case FUN:
        result = function(current, nullptr,local_var_map);
        break;
    case FUN_DEF_CALL:
        result = function(current->left, current->right, local_var_map);
        break;
    case FUN_CALL:
        if (!local_var_map[((ASTID*)current->left)->id]){
            cout << "Undefine function name: " << ((ASTID*)current->left)->id << endl;
        }else if (local_var_map[((ASTID*)current->left)->id]->type == FUN){
            result = function(local_var_map[((ASTID*)current->left)->id], current->right, local_var_map);
        }else{
            result = functionClosure(current, local_var_map);
            if (!global_param_stk.empty()){
                cout << "global_param does not match " << global_param_stk.size() << " pararms still exist" << endl;
                exit(0);
            }
        }
        break;
    case FUN_BODY:
        result = functionBody(current, local_var_map);
        break;
    case DEFINE:
        defineID(current, local_var_map);
        break;
    default:
        cout << "error" << endl;
        break;
    }
    return result;
}

