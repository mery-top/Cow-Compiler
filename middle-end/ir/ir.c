 #include <stdio.h>
 #include <stdlib.h>
 #include "ir.h"
 #include <string.h>



 IRInstruction* create_ir_load_const(char* dest, int value){
     IRInstruction* instr = malloc(sizeof(IRInstruction));
     instr->type = IR_LOAD_CONST;
     strcpy(instr->dest, dest);
     instr->value = value;
     instr->next = NULL;
 }

 IRInstruction* create_ir_binary(IRType type, char* dest, char* arg1, char* arg2){
    IRInstruction* instr = malloc(sizeof(IRInstruction));
    instr->type = type;
    strcpy(instr->dest, dest);
    strcpy(instr->arg1, arg1);
    strcpy(instr->arg2, arg2);
    instr->next = NULL;
 }

IRInstruction* create_ir_var(char* name){
    IRInstruction* instr = malloc(sizeof(IRInstruction));
    strcpy(instr->dest, name);
    instr->type = IR_VAR;
    instr->next = NULL;
}


void append_ir(IRInstruction** list, IRInstruction* instr){
    if(*list == NULL){
        *list = instr;
    }else{
        IRInstruction* temp = *list;
        while(temp!=NULL){
            temp = temp->next;
        }
        temp->next = instr;
    }
}

void print_ir(IRInstruction* list){
    while(list){
        switch(list->type){
            case IR_LOAD_CONST:
                printf("%s : const %d\n", list->dest, list->value);
                break;
            case IR_ADD:
                printf("%s : add %s, %s\n", list->dest, list->arg1, list->arg2);
                break;
            case IR_SUB:
                printf("%s : sub %s, %s\n", list->dest, list->arg1, list->arg2);
                break;
            case IR_VAR:
                printf("%s :  VAR\n", list->dest);
                break;
            default:
                printf("unknown IR\n");
        }
        list = list->next;
    }
}

