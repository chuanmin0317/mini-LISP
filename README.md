# Mini-Lisp Interpreter

A simple interpreter for a subset of the Lisp language (Mini-Lisp), developed as a course project for "Compilers". This project includes a front-end built with Flex (Lex) and Bison (Yacc) for lexical analysis and parsing, generating an Abstract Syntax Tree (AST), and a backend interpreter written in C++ that evaluates the AST.

## Features

### Basic Language Features

-   [x] **Syntax Validation:** Parses and validates Mini-Lisp code structure.
-   [x] **Printing:** Output numbers (`print-num`) and booleans (`print-bool`) to the console.
-   [x] **Numerical Operations:** Supports `+`, `-`, `*`, `/`, `mod`.
-   [x] **Logical Operations:** Supports `and`, `or`, `not`, `=`, `>`, `<`.
-   [x] **Conditional Execution:** `if` expressions.
-   [x] **Variable Definition:** `define` keyword for global variables.
-   [x] **Anonymous Functions:** Define functions using `fun`.
-   [x] **Named Functions:** Define named functions using `define` and `fun`.

### Bonus Features Implemented

-   [x] **Recursion:** Functions can call themselves.
-   [x] **Basic Type Checking:** Attempts to differentiate between number and boolean operations during interpretation.
-   [x] **Nested Function Calls:** Functions can be called within other expressions.
-   [x] **First-class Functions:** Functions can be passed as arguments or returned (basic implementation).

## Technology Stack

*   **Interpreter Core:** C++
*   **Lexical Analyzer:** Flex (Lex)
*   **Parser Generator:** Bison (Yacc)
*   **Build System:** Make (implied by `build.sh`, please verify)
*   **Version Control:** Git

## Installation & Building

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/chuanmin0317/mini-LISP
    cd mini-LISP
    ```

2.  **Build the interpreter:**
    ```bash
    ./build.sh
    ```

