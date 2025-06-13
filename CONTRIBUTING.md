# 🐮 Cow Compiler

Welcome to the Cow Compiler — a small compiler written in C that compiles a minimalistic language (CowLang) into LLVM IR!


This project includes a full compilation pipeline:
- **Lexer** (Tokenization)
- **Parser** (Syntax analysis)
- **AST** (Abstract Syntax Tree)
- **IR Generation**
- **LLVM Code Emission** (Simple main function)

---

## 📦 Features

- Basic arithmetic expressions (`+`, `-`)
- Variable declaration
- Constant folding via IR
- LLVM IR code generation (Testing purpose Only)
- Easy to extend (e.g., add new operators or types)


## Note
- The LLVM IR is based on linkedList format, currently a simple format with the main of LLVM is executed here
- Extend the Linkedlist and add the VAR types in the irgen folder.
- Use LLVM Libraries instead of the switch case here.
---

## 🧠 Example

CowLang input (`input.cow`):

```cow
x = 4 + 4;
```

Running
```
make
make run
```
## Project Structure
```
cow-compiler/
├── front-end/
│   ├── lexer/        # Lexical analyzer
│   ├── parser/       # Parser
│   ├── ast/          # AST definitions
│   └── token/        # Token types
├── middle-end/
│   ├── ir/           # Custom IR structure
│   └── irgen/        # AST to IR generator
├── back-end/
│   ├── llvm/         # LLVM IR code generation
│   └── evaluator/    # IR evaluator (optional)
├── tests/            # Sample CowLang test files
├── src/
│   ├── main/          # Compiler entry point
├── Makefile          # Build system
└── README.md         # Project readme

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

We welcome all contributions — whether you're fixing bugs, improving documentation, or adding new features!

👉 Check out our [CONTRIBUTING.md](CONTRIBUTING.md) to get started.


