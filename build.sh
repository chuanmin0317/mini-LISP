#!/bin/bash

# 設定檔案名稱
LEX_FILE="scanner.l"      # Lex 檔案名稱
YACC_FILE="intepreter.y"     # Yacc 檔案名稱
OUTPUT="intepreter"          # 最後的執行檔名稱

# Step 1: 檢查檔案是否存在
if [ ! -f "$LEX_FILE" ]; then
    echo "Error: Lex file '$LEX_FILE' does not exist!"
    exit 1
fi

if [ ! -f "$YACC_FILE" ]; then
    echo "Error: Yacc file '$YACC_FILE' does not exist!"
    exit 1
fi

# Step 2: 清理舊檔案
echo "Cleaning up old files..."
rm -f lex.yy.c y.tab.c y.tab.h y.tab.o lex.yy.o "$OUTPUT"

# Step 3: 執行 Yacc
echo "Running Yacc..."
bison -d -o "y.tab.c" "$YACC_FILE"
if [ $? -ne 0 ]; then
    echo "Yacc encountered an error!"
    exit 1
fi

# Step 4: 編譯 Yacc 輸出
echo "Compiling Yacc output..."
g++ -c -g -I.. "y.tab.c"
if [ $? -ne 0 ]; then
    echo "Failed to compile Yacc output!"
    exit 1
fi

# Step 5: 執行 Lex
echo "Running Lex..."
flex -o lex.yy.c "$LEX_FILE"
if [ $? -ne 0 ]; then
    echo "Lex encountered an error!"
    exit 1
fi

# Step 6: 編譯 Lex 輸出
echo "Compiling Lex output..."
g++ -c -g -I.. lex.yy.c
if [ $? -ne 0 ]; then
    echo "Failed to compile Lex output!"
    exit 1
fi

# Step 7: 連結並生成執行檔
echo "Linking and generating the executable..."
g++ -g -o "$OUTPUT" y.tab.o lex.yy.o AST.cpp -ll -lm
if [ $? -ne 0 ]; then
    echo "Failed to link the executable!"
    exit 1
fi

# 完成
echo "Compilation completed successfully! Executable is '$OUTPUT'."
