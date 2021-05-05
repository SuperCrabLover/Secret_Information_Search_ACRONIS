#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INPUT_SIZE 999999
#define READ_FAIL 0 
#define READ_SUC_N 1 
#define READ_SUC_E 2

int* pref(char* string);
int isSubStr(char *string, int *prefix, char* file_name);
int read_input(FILE* input_file, char* input);