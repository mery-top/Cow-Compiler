#ifndef IRGEN_H
#define IRGEN_H
#include "../ir/ir.h"
#include "../../front-end/ast/ast.h"

IRInstruction* generate_ir_from_ast(ASTNode* node);

#endif