CC = gcc
SRC = src/main.c \
front-end/lexer/lexer.c \
front-end/ast/ast.c \
front-end/parser/parser.c \
back-end/evaluator/eval.c

OUT = build/cow

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(SRC) -o $(OUT)


run: $(OUT)
	./$(OUT)


clean:
	rm -f build/cow
