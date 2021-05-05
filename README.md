# Secret_Information_Search_ACRONIS
## Contents
0. [Brief description](#Description)
1. [Installation](#Installation)
2. [Usage](#Usage)
## Description
Secret Information Search was written for admission to the department of MIPT Acronis. Program is searchin several strings in one text. The code is powered by Knuth–Morris–Pratt algorithm, that works really fast (O(n)). The realisation of the Knuth–Morris–Pratt algorithm was inspired by https://e-maxx.ru/algo/prefix_function. Author: Molozhavenko Alexander MIPT 2021
## Installation
    git clone
    make
## Usage
After executing make the ELF named 'a' will be created. For executing the porgramm type

`./a <input file name> <string container name>`

The output will be printed into terminal for all of the strings in the container. The string in the container should be divided by "\n" sumbol.
