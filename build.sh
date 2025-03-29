#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e
# Treat unset variables as an error when substituting.
set -u
# Pipes fail if any command in the pipe fails (safer)
set -o pipefail

# --- Configuration ---
LEX_FILE="scanner.l"          # Lex source file
YACC_FILE="interpreter.y"     # Yacc source file (Corrected spelling)
CPP_FILES="AST.cpp"           # Add other .cpp files if needed, space-separated
OUTPUT_EXEC="interpreter"     # Name of the final executable (Corrected spelling)
TEST_DIR="./public_test_data" # Directory containing test input (.lsp files)
OUTPUT_DIR="./output"         # Directory to store test output (.out files)
# Compiler and flags
CXX="g++"
# Remove -I.. if AST.h/y.tab.h are in the current directory
INCLUDE_DIRS="" # Example: "-I../include" or leave empty ""
CXXFLAGS="-g -Wall -Wextra ${INCLUDE_DIRS}" # Debug flags, add warnings
LDFLAGS="-ll -lm"                           # Linker flags (libfl, libm)

# --- Build Steps ---

# 1. Check source files
echo "Checking source files..."
if [ ! -f "$LEX_FILE" ]; then echo "Error: Lex file '$LEX_FILE' not found!"; exit 1; fi
if [ ! -f "$YACC_FILE" ]; then echo "Error: Yacc file '$YACC_FILE' not found!"; exit 1; fi
# Add checks for CPP_FILES if needed

# 2. Clean up old files
echo "Cleaning up old files..."
rm -f lex.yy.c y.tab.c y.tab.h y.tab.o lex.yy.o ${CPP_FILES//.cpp/.o} "$OUTPUT_EXEC"
rm -rf "$OUTPUT_DIR" # Remove old output directory

# 3. Run Yacc (Bison)
echo "Running Yacc (Bison)..."
bison -d -o y.tab.c "$YACC_FILE"

# 4. Run Lex (Flex)
echo "Running Lex (Flex)..."
flex -o lex.yy.c "$LEX_FILE"

# 5. Compile generated C/C++ files and user C++ files
echo "Compiling generated files..."
"$CXX" ${CXXFLAGS} -c -o y.tab.o y.tab.c
"$CXX" ${CXXFLAGS} -c -o lex.yy.o lex.yy.c
echo "Compiling C++ source files..."
for cpp_file in $CPP_FILES; do
    if [ ! -f "$cpp_file" ]; then echo "Error: C++ file '$cpp_file' not found!"; exit 1; fi
    obj_file="${cpp_file//.cpp/.o}"
    echo "Compiling $cpp_file -> $obj_file"
    "$CXX" ${CXXFLAGS} -c -o "$obj_file" "$cpp_file"
done

# 6. Link object files into the final executable
echo "Linking..."
OBJECT_FILES="y.tab.o lex.yy.o ${CPP_FILES//.cpp/.o}"
"$CXX" ${CXXFLAGS} -o "$OUTPUT_EXEC" $OBJECT_FILES ${LDFLAGS}

echo "Build completed successfully! Executable is '$OUTPUT_EXEC'."

# --- Testing Steps ---

# 7. Check for executable and test directory
if [ ! -f "$OUTPUT_EXEC" ]; then echo "Error: Executable '$OUTPUT_EXEC' not found."; exit 1; fi
if [ ! -d "$TEST_DIR" ]; then
    echo "Warning: Test directory '$TEST_DIR' not found. Skipping tests."
    exit 0 # Exit gracefully if no tests
fi

# 8. Create output directory
echo "Creating output directory: $OUTPUT_DIR"
mkdir -p "$OUTPUT_DIR"

# 9. Run tests
echo "Running tests from $TEST_DIR..."
for input_file in "$TEST_DIR"/*.lsp; do
    if [ -f "$input_file" ]; then # Ensure it's a file
        filename=$(basename "$input_file" .lsp) # Get name without .lsp extension
        output_file="$OUTPUT_DIR/$filename.out"
        echo "  Testing $filename: '$input_file' -> '$output_file'"
        # Execute interpreter, redirect input from test file, redirect output to output file
        "./$OUTPUT_EXEC" < "$input_file" > "$output_file"
        # Optional: Check for errors during execution
        if [ $? -ne 0 ]; then
            echo "    ERROR: Interpreter exited with non-zero status for $filename!"
            # Optionally remove the potentially incomplete output file: rm -f "$output_file"
        fi
    fi
done

echo "Testing finished. Output files are in '$OUTPUT_DIR'."

exit 0