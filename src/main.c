#include <stdio.h>
#include <stdlib.h>
#include "../front-end/lexer/lexer.h"
#include "../front-end/ast/ast.h"
#include "../front-end/parser/parser.h"
#include "../front-end/token/token.h"
#include "../back-end/evaluator/eval.h"
#include "../front-end/error/err.h"
#include "../middle-end/ir/ir.h"
#include "../back-end/llvm/llvm.h"
#include "../middle-end/irgen/irgen.h"

int main(int argc, char *argv[]){
    if(argc !=2){
        printf("Include the file");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Could not open file.\n");
        return 1;
    }

    char input[1024];
    fread(input, 1, sizeof(input) - 1, file);
    input[1023] = '\0';
    fclose(file);

    Token *tokens = tokenize(input);
    print_tokens(tokens);

    ASTNode *tree = parse(tokens);
    print_tree(tree);

    IRInstruction* ir = generate_ir_from_ast(tree);

    FILE *llvm_file = fopen("output.ll", "w");
    generate_llvm(ir, llvm_file);
    fclose(llvm_file);

    free_ast(tree);
    free(tokens);


    return 0;
}
