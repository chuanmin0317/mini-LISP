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

2.  **Build the interpreter and run tests:**
    ```bash
    ./build.sh
    ```
    *   This script will:
        *   Clean previous build artifacts.
        *   Run Bison (Yacc) and Flex (Lex) to generate parser and scanner code.
        *   Compile the generated code and the C++ source files (`AST.cpp`).
        *   Link everything into an executable named `interpreter`.
        *   If the `public_test_data` directory exists, it will automatically run all `.lsp` test files found there.
        *   The output for each test file (e.g., `test1.lsp`) will be saved in the `output/` directory (e.g., `output/test1.out`).

## Usage

After running `build.sh`, you can run the interpreter directly:

```bash
./interpreter
```
## Known Issues & Limitations
* **Memory Management:** The current C++ implementation uses manual new for AST nodes and strdup for identifiers without corresponding delete or free calls. This leads to memory leaks.

* **Error Handling:** Error reporting is basic, often printing a message and exiting (exit(0)). It lacks detailed information like line numbers.

* **Global type_stack Dependency:** The parser (Yacc) relies on the lexer (Lex) pushing expected node types onto a global stack (type_stack). This is a fragile design prone to errors if the push/pop order doesn't perfectly align.

* **Limited Data Types:** Only supports numbers (integers) and booleans. No strings, lists (proper Lisp lists), etc.
## To-Do List / Future Enhancements
* **Refactor Memory Management:** Implement smart pointers (std::unique_ptr, std::shared_ptr) to prevent memory leaks.

* **Remove type_stack Dependency:** Modify createNode function to accept the node type as a parameter and update Yacc rules accordingly.

* **Improve Error Handling:** Implement exception handling or more detailed error messages including line numbers.

* **Free strdup-ed Memory:** Ensure identifier strings allocated by strdup are properly freed.

* **Add More Data Types:** Implement support for strings, floating-point numbers, or proper Lisp lists.

* **Implement Garbage Collection:** (Advanced) Introduce a garbage collector for more robust memory management, especially for closures and lists.

* **File Input:** Allow the interpreter to read and execute code from a .lisp file.

* **Expand Standard Library:** Add more built-in functions.

* **Write Unit Tests:** Add tests to verify correctness and prevent regressions.


