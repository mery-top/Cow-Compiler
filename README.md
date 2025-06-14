# 🐮 Cow Compiler

Welcome to the **Cow Compiler** — a lightweight compiler written in C that compiles a minimalistic language called **CowLang** into **LLVM IR**.

This project walks you through a **complete compilation pipeline**, making it ideal for learning how compilers work at a low level.

---

## 🔧 Compilation Pipeline

This compiler includes the following stages:

- **Lexer**: Tokenizes the input source code.
- **Parser**: Parses tokens into an abstract syntax tree (AST)
- **AST**: Represents the structure of the program
- **IR Generation**: Converts the AST into a simple intermediate representation (IR)
- **LLVM Code Emission**: Emits LLVM IR for a simple `main()` function

---

## 📦 Features

- 🧮 Basic arithmetic expressions (`+`, `-`)
- 📝 Variable declarations
- 🧠 Constant folding via IR
- 🧾 LLVM IR code generation (for testing purposes)
- 🔧 Easy to extend (add new operators, variables, data types)

---

## ⚠️ Notes

- The current LLVM IR backend is **basic and linked-list-based**.
- LLVM output is minimal — a simple `main` function is emitted.
- You are encouraged to:
  - ✅ Extend the linked list IR to support variable types (`VAR`)
  - 🔁 Replace `switch-case` based IR-to-LLVM mapping with real **LLVM C API** for scalability and real-world usage

---

## 🧠 Example

### Input (`input.cow`)
```cow
x = 4 + 4;
```
## Running the Compiler
```
make        # Compile all source files
make run    # Compile + run the CowLang file
```
## For IR 

Custom IR (Extend the Linkedlist for printing):

t0 : const 4
t1 : const 4
t2 : add t0, t1
LLVM IR (saved to output.ll):

define i32 @main() {
entry:
  %t0 = add i32 4, 4
  ret i32 %t0
}

## 🗂️ Project Structure
```
cow-compiler/
├── front-end/
│   ├── lexer/        # Lexical analyzer
│   ├── parser/       # Syntax parser
│   ├── ast/          # Abstract syntax tree definitions
│   └── token/        # Token types and utilities
├── middle-end/
│   ├── ir/           # Custom intermediate representation (IR)
│   └── irgen/        # AST → IR transformation logic
├── back-end/
│   ├── llvm/         # IR → LLVM IR generator
│   └── evaluator/    # IR evaluator (optional)
├── tests/            # Sample test cases for CowLang
├── src/
│   ├── main.c             # Entry point (main compiler driver)
├── Makefile          # Build system
└── README.md         # Project documentation
```

## 💬 Join the Discussion

Have questions, ideas, or suggestions? Want to contribute but don’t know where to start? Let’s talk!

We use **GitHub Discussions** to foster a collaborative and welcoming community around the Cow Compiler project. Whether you're a beginner learning how compilers work or an experienced contributor looking to improve our IR/LLVM pipeline — you’re welcome here!

### 🗣️ What You Can Do:

- 💡 **Ask Questions**  
  Not sure how something works? Curious about compiler internals? Ask away!

- 🧠 **Share Ideas**  
  Got a feature request or a suggestion? We’d love to hear your thoughts.

- 🐞 **Report Issues**  
  Found a bug or unexpected behavior? Drop a message before opening an issue.

- 🙌 **Collaborate on Features**  
  Join other developers to brainstorm or discuss new enhancements.

## 🙌 Contributing
We welcome all contributions — whether you're fixing bugs, improving documentation, or adding exciting new features!
