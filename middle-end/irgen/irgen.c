#include <stdio.h>
#include "../ir/ir.h"
#include "../../front-end/ast/ast.h"

int temp_id =0;

char* new_temp(){
    static char buffer[34];
    snprintf(buffer, sizeof(buffer), "t%d", temp_id++);
    return strdup(buffer);
}

IRInstruction* 

