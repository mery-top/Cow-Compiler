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








#endif