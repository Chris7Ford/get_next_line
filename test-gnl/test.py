#!/bin/bash

import subprocess
import os
import filecmp
import difflib

Lyou = []
Ltrue = []
cwd = os.getcwd()
os.system("gcc -Wall -Werror -Wextra ../get_next_line/get_next_line.c main.c ../get_next_line/libft/libft.a -o test")
p = subprocess.Popen(["ls", "books"], stdout=subprocess.PIPE)
books = p.communicate()[0]
books = books.split("\n")
books.pop()
for book in books:
    print("Testing the file " + book)
    print "..."
    book_path = "books/" + book;
    test = cwd + "/test"
    p = subprocess.Popen([test, book_path], stdout=subprocess.PIPE)
    your_output = p.communicate()[0];
    Lyou.append(your_output)
    book_file = open(book_path, "r")
    true_output = book_file.read()
    Ltrue.append(true_output)
    if your_output == true_output:
        print " -> SUCCESS"
    else:
        print " -> FAILURE"
    book_file.close()

f = open("diff.trace", "w+")
for line in difflib.context_diff(Lyou, Ltrue):
    f.write(line)
print "diff.trace created"
f.close()
