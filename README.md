# CVM++ 🚀
## Custom Stack-Based Virtual Machine & Bytecode Compiler in C++

A lightweight educational programming language runtime built completely from scratch in C++.

CVM++ demonstrates how modern programming languages work internally by transforming high-level source code into executable bytecode and executing it on a custom-built stack-based Virtual Machine (VM).

---

# 📚 Table of Contents

- [Overview](#-overview)
- [Project Motivation](#-project-motivation)
- [Key Concepts Implemented](#-key-concepts-implemented)
- [Architecture](#️-architecture)
- [Compilation Pipeline](#-compilation-pipeline)
- [Project Structure](#-project-structure)
- [Language Features](#-language-features)
- [Example Programs](#-example-programs)
- [Bytecode Example](#-bytecode-example)
- [AST Example](#-ast-example)
- [Virtual Machine Design](#-virtual-machine-design)
- [How to Build](#-how-to-build)
- [How to Run](#-how-to-run)
- [Learning Outcomes](#-learning-outcomes)
- [Future Improvements](#-future-improvements)

---

# 📌 Overview

CVM++ is an educational systems programming project focused on compiler construction and virtual machine design.

The project implements the complete execution pipeline of a custom scripting language:

```text
Source Code → Lexer → Parser → AST → Bytecode Compiler → Virtual Machine → Execution Result
```

Instead of directly interpreting source code, CVM++ compiles code into custom bytecode instructions which are then executed by a stack-based Virtual Machine.

This project helps in understanding:

- Compiler internals
- Parsing techniques
- Bytecode generation
- Stack-based execution models
- Language runtime systems
- Instruction Set Architectures (ISA)

---

# 🎯 Project Motivation

CVM++ was built to explore:

- How source code becomes machine-understandable instructions
- How parsers build syntax trees
- How bytecode works
- How virtual machines execute instructions
- How interpreters and compilers are designed

The project serves as a simplified educational model of systems like:

- Python VM
- Java JVM
- Lua VM
- JavaScript Engines

---

# 🧠 Key Concepts Implemented

## Compiler Design

- Lexical Analysis
- Recursive Descent Parsing
- Syntax Validation
- AST Construction
- Bytecode Compilation

## Virtual Machine Concepts

- Stack-Based Execution
- Operand Stack
- Instruction Pointer
- Bytecode Interpretation
- Custom Opcodes

## Language Runtime Concepts

- Variables
- Arithmetic Expressions
- Boolean Expressions
- Input/Output
- Operator Precedence

---

# ⚙️ Architecture

```text
           ┌────────────────┐
           │   Source Code  │
           └────────┬───────┘
                    │
                    ▼
           ┌────────────────┐
           │     Lexer      │
           └────────┬───────┘
                    │ Tokens
                    ▼
           ┌────────────────┐
           │     Parser     │
           └────────┬───────┘
                    │ AST
                    ▼
           ┌────────────────┐
           │ Bytecode Gen   │
           └────────┬───────┘
                    │ Bytecode
                    ▼
           ┌────────────────┐
           │ Virtual Machine│
           └────────┬───────┘
                    │
                    ▼
           ┌────────────────┐
           │ Program Output │
           └────────────────┘
```

---

# 🔄 Compilation Pipeline

## 1. Lexical Analysis

The Lexer converts raw source code into tokens.

Example:

```c
let x = 10 + 20;
```

Generated Tokens:

```text
LET
IDENTIFIER(x)
EQUALS
NUMBER(10)
PLUS
NUMBER(20)
SEMICOLON
```

---

## 2. Parsing

The Parser analyzes token sequences and constructs an Abstract Syntax Tree (AST).

---

## 3. AST Construction

Example AST:

```text
Assignment
 ├── Identifier(x)
 └── Add
      ├── 10
      └── 20
```

---

## 4. Bytecode Generation

The compiler converts the AST into low-level VM instructions.

Example Bytecode:

```text
PUSH 10
PUSH 20
ADD
STORE x
```

---

## 5. Virtual Machine Execution

The VM executes bytecode instructions using a stack-based execution model.

---

# 📂 Project Structure

```text
CVMpp/
│
├── src/
│   ├── lexer/
│   ├── parser/
│   ├── compiler/
│   ├── vm/
│   └── main.cpp
│
├── include/
│
├── examples/
│   ├── hello.cvm
│   ├── calculator.cvm
│   ├── math.cvm
│   └── variables.cvm
│
├── README.md
├── LICENSE
└── .gitignore
```

---

# ✨ Language Features

## Variables

```c
let x = 10;
```

---

## Arithmetic Operations

```c
print(10 + 20);
print(5 * 2);
```

---

## User Input

```c
input(x);
```

---

## Boolean Values

```c
let flag = true;
```

---

## Comparison Operators

```c
print(10 > 5);
print(5 == 5);
```

---

## Logical Operators

```c
print(true && false);
```

---

# 🔥 Example Programs

## Hello World

```c
print("Hello World");
```

---

## Arithmetic

```c
let a = 10;
let b = 20;

print(a + b);
```

---

## Boolean Example

```c
let isAdmin = true;

print(isAdmin);
```

---

## Input Example

```c
let age;

input(age);

print(age >= 18);
```

---

# ⚡ Bytecode Example

Source Code:

```c
let x = 10;
let y = 20;

print(x + y);
```

Generated Bytecode:

```text
PUSH 10
STORE x

PUSH 20
STORE y

LOAD x
LOAD y
ADD
PRINT
```

---

# 🌳 AST Example

```text
Print
 └── Add
      ├── Identifier(x)
      └── Identifier(y)
```

---

# 🖥️ Virtual Machine Design

CVM++ uses a stack-based execution model.

## Core Components

- Operand Stack
- Instruction Pointer (IP)
- Bytecode Memory
- Variable Table

## Execution Flow

```text
FETCH → DECODE → EXECUTE
```

---

# 🛠️ How to Build

## Compile

```bash
g++ src/main.cpp -o cvm
```

---

# ▶️ How to Run

## Execute Script

```bash
./cvm examples/hello.cvm
```

---

# 📖 Learning Outcomes

This project helped explore:

- Compiler Construction
- Parsing Theory
- Bytecode Systems
- Virtual Machine Internals
- Stack Data Structures
- Recursive Descent Parsing
- Language Runtime Design

---

# 🚀 Future Improvements

## Planned Features

- Functions
- Loops
- Conditionals
- Arrays
- String Support
- Error Recovery

---

# Done By

## Rama Neeraj Dungala

---