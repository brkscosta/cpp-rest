#!/bin/bash

files=$(find . -name '*.cpp' -o -name '*.h')

if [ -z "$files" ]; then
    echo "No .cpp or.h files found to format."
    exit 0
fi

clang-format --verbose --style=file -i $files

if [ $? -eq 0 ]; then
    echo "Files Formatted"
else
    echo "Fail on format"
    exit 1
fi
