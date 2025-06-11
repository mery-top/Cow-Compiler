#ifndef COW_IR_H
#define COW_IR_H

typedef enum{
    IR_ADD,
    IR_SUB,
    IR_LOAD_CONST
} IRType;


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


#endif