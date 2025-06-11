 #include <stdio.h>
 #include <stdlib.h>
 #include "ir.h"

 /*
 typedef struct IRInstruction{
    IRType type;
    char dest[32];
    char arg1[32];
    char arg2[32];
    int value;
    struct IRInstruction* next;
} IRInstruction;


IRInstruction* create_ir_load_const(char* dest, int value);
IRInstruction* create_ir_binary(IRType type, char* dest, char* arg1, char* arg2);
IRInstruction* create_ir_var(char* name);
void append_ir(IRInstruction** list, IRInstruction* instr);
void print_ir(IRInstruction* list);
 */

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

