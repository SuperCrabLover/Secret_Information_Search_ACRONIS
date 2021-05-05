#include "kmp.h"

int main(int argc, char** argv)
{
	if (argc < 3)
	{
		printf("Too few arguments! Enter the name of search file and then the name of the secret bytes storage.\n");
		exit(-1);
	}
	FILE* search_file;
	search_file = fopen(argv[1], "r");
	if (NULL == search_file)
	{
		fprintf(stderr, "Cannot open the file with name %s\n", argv[1]);
		exit(-1);
	}
	fclose(search_file);
	FILE* vault;
	vault = fopen(argv[2], "r");
	if (NULL == vault)
	{
		fprintf(stderr, "Cannot open the file with name %s\n", argv[2]);
		fclose(search_file);
		exit(-1);
	}
	int read_flag = 0;
	while(read_flag != READ_SUC_E)
	{
		char* string = (char*)calloc(INPUT_SIZE, sizeof(char));
		if (NULL == string)
		{
			fprintf(stderr, "Calloc error!\n");
			fclose(vault);
			exit(-1);
		}
		read_flag = read_input(vault, string);
		if (read_flag == READ_FAIL)
		{
			fclose(vault);
			free(string);
			exit(-1);
		}
		int *prefix = pref(string);
		if (isSubStr(string, prefix, argv[1]))
		{
			printf("The string \"%s\" was found!\n", string);
			free(string);
			free(prefix);
		}
		else
		{
			printf("The text has finished! The string \"%s\" was not found\n", string);
			free(string);
			free(prefix);
		}
	}
	fclose(vault);
	return 0;
}
