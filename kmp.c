#include "kmp.h"

int* pref(char* string) 
{
	int n = strlen(string);
	int * pr = (int *)calloc(n, sizeof(int));
	if (pr == NULL)
	{
		printf("Prefix function error: calloc error!\n");
		exit(-1);
	}
	for (int i = 1; i < n; i++) 
	{
		int j = pr[i-1];
		while (j > 0 && string[i] != string[j])
		{
			j = pr[j-1];
		}
		if (string[i] == string[j])  
		{
			j++;
		}
		pr[i] = j;
	}
	return pr;
}

int isSubStr(char *string, int *prefix, char* file_name)
{
	char letr;
	int len = strlen(string);
	int i = 0;
	FILE* file = fopen(file_name, "r");
	while(1)
	{
		letr = fgetc(file);
		if (letr == EOF)
		{
			fclose(file);
			return 0;
		}
		if (letr == ' ')
		{
			i = 0;
		}
		else if (string[i] == letr)
		{
			i++;
			if (i == len)
			{
				fclose(file);
				return 1;
			}
		}
		else 
		{
			while (1)
			{
				if (i == 0)
				{
					break;
				}
				i = prefix[i - 1];
				if (i == 0)
				{
					if (string[0] == letr)
					{
						i++;
						break;
					}
					else
					{
						break;
					}
				}
				if (string[i] == letr)
				{
					i++;
					break;
				}
			}
		}
	}
}

int read_input(FILE* input_file, char* input)
{
	char new_let = fgetc(input_file);
	int i;
	for(i = 0; new_let != '\n' && new_let != EOF; i++)
	{
		if (i == INPUT_SIZE - 2)
		{
			//0 is read failed flag
			fprintf(stderr, "The input expression is too long!\n");
			return READ_FAIL;
		}
		else
		{
			input[i] = new_let;
			new_let = fgetc(input_file);
		}
	}
	if (new_let == EOF)
	{
		//2 is EOF read succes flag
		return READ_SUC_E;
	}
	input[i] = '\0';
	//1 is \n read succes flag
	return READ_SUC_N;
}

