CC = gcc
SRC = src/main.c \
front-end/lexer/lexer.c \
front-end/ast/ast.c \
front-end/parser/parser.c \
back-end/evaluator/eval.c \
front-end/error/err.c \
middle-end/ir/ir.c \
back-end/llvm/llvm.c \
middle-end/irgen/irgen.c

OUT = build/cow

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(SRC) -o $(OUT)

run:
	./$(OUT) src/test.cow

clean:
	rm -f build/cow
