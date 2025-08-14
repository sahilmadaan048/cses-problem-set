#!/bin/bash
shopt -s autocd        # allows changing directories by typing folder name
shopt -s globstar       # enables ** recursion if needed

while true; do
    # Ask for folder relative to current directory
    read -e -p "Enter folder (Tab for autocomplete, or '.' for current folder): " folder
    if [ -d "$folder" ]; then
        break
    else
        echo "Folder does not exist. Try again."
    fi
done

# Change to that folder
cd "$folder" || exit 1

# Ask for C++ file inside this folder
while true; do
    read -e -p "Enter C++ file name (with .cpp, Tab autocomplete works): " cppfile
    if [ -f "$cppfile" ]; then
        break
    else
        echo "File does not exist. Try again."
    fi
done

# Get filename without extension
exe="${cppfile%.cpp}.exe"

# Compile with C++17
g++ -std=c++17 "$cppfile" -o "$exe"
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

# Run executable
echo "Running $exe..."
"./$exe"
