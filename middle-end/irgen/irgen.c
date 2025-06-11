#include <stdio.h>
#include "../ir/ir.h"
#include "../../front-end/ast/ast.h"

int temp_id =0;

char* new_temp(){
    static char buffer[34];
    snprintf(buffer, sizeof(buffer), "t%d", temp_id++);
    return strdup(buffer); //heap
}

IRInstruction* generate_ir_from_ast(ASTNode* node){
    IRInstruction* list = NULL;
    if(node->type == AST_NUMBER){
        char* temp = new_temp();
        append_ir(&list, create_ir_load_const(temp, node->value));
    }else if(node->type == AST_BINARY){
        IRInstruction* left = generate_ir_from_ast(node->left);
        IRInstruction* right =  generate_ir_from_ast(node->right);

        append_ir(&list, left);
        append_ir(&list, right);

        char* dest = new_temp();
        append_ir(&list, create_ir_binary(
            node->op == '+' : IR_ADD : IR_SUB, 
            dest, left->dest, right->dest
        ));
    }

    return list;
}

