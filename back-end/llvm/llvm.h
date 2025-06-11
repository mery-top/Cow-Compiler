#ifndef LLVM_H
#define LLVM_H

#include "../../middle-end/ir/ir.h"
#include "../../front-end/ast/ast.h"
#include <stdio.h>

void generate_llvm(IRInstruction* ir, FILE* out);

#endif