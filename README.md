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
g++ main.cpp -o build/brainfuck
```

### Execution
Run the compiled binary:
```bash
./build/brainfuck.exe ./example/main.bf
```

## 📝 Example Code
The default script included in `example/main.bf` is the classic "Hello World!" program:
```brainfuck
++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.
```

## 📜 License
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

Copyright © 2026 **Mohammed Tamer Mohammed Ahmed El-Azab Nour**

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.