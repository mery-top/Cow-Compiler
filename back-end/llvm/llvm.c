#include "llvm.h"

void generate_llvm(IRInstruction* ir, FILE* out){
    fprintf(out, "define i32 @main() {\n");

    while(ir){
        switch(ir->type){
            case IR_LOAD_CONST:
                fprintf(out, "  %%%s = add i32 0, %d\n", ir->dest, ir->value);
                break;
            case IR_ADD:
                fprintf(out,  "  %%%s = add i32 %%%s, %%%s\n", ir->dest, ir->arg1, ir->arg2);
                break;
            case IR_SUB:
                fprintf(out, "  %%%s = sub i32 %%%s, %%%s\n", ir->dest, ir->arg1, ir->arg2);
                break;
            default:
                break;
        }
        ir = ir->next;
    }
    
    fprintf(out, "  ret i32 0\n}\n");

}
