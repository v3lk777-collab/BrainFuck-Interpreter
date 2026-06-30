# Brainfuck Interpreter

A lightweight, efficient, and standard-compliant Brainfuck interpreter written in C++. It features a standard 30,000-byte tape, proper cell manipulation, and fully supports nested loops (`[` and `]`).

## ✨ Features
- **Standard Compliant:** Implements all 8 foundational Brainfuck commands.
- **Robust Loop Handling:** Uses inline scanning to gracefully handle deeply nested loops.
- **Comment-Friendly:** Automatically ignores non-instruction characters, allowing clean code comments inside Brainfuck files.
- **Memory Safety:** Built-in 30,000-cell tape initialized to zero.

## 🛠️ Brainfuck Instruction Set

| Command | Action |
|:-------:|:---|
| `>` | Increment the data pointer (move to the next cell). |
| `<` | Decrement the data pointer (move to the previous cell). |
| `+` | Increment the byte at the data pointer. |
| `-` | Decrement the byte at the data pointer. |
| `.` | Output the byte at the data pointer as an ASCII character. |
| `,` | Accept one byte of input, storing its value in the byte at the data pointer. |
| `[` | If the byte at the data pointer is zero, jump forward to the command after the matching `]`. |
| `]` | If the byte at the data pointer is nonzero, jump backward to the command after the matching `[`. |

## 🚀 Getting Started

### Prerequisites
Make sure you have a C++ compiler installed (like `g++` / GCC or Clang).

### Compilation
Open your terminal in the directory containing `main.cpp` and run:
```bash
g++ -O3 -o bf_interpreter main.cpp
```

### Execution
Run the compiled binary:
```bash
./bf_interpreter
```

## 📝 Example Code
The default script included in `main.cpp` is the classic "Hello World!" program:
```brainfuck
++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.
```

## 📜 License
**Mohammmed Tamer Mohammed Ahmed El-Azab Nour**
**GPL v3**

This project is open-source and free to use. Feel free to modify, extend, or integrate it into your own compiler/low-level tooling pipelines!