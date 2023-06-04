#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

char* compliance(char* str, char* c)
{	
	int count = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (tolower(str[i]) == tolower(c))
			count++;
	}

	if (count > 1)
		return true;
	
	return false;
}


char* DuplicateEncoder (const char* string)
{
	char* newString = malloc(strlen(string) * sizeof(char));

	for(int i = 0; i < strlen(string); i++)
		newString[i] = compliance(string, string[i]) ? ')' : '(';
	
	newString[strlen(string)] = '\0';
	return newString;
}

int main()
{
	char test[][15] = { "Supralapsarian","Prespecialized",
						"Prespecialized", ")()())()(()()(",
						"   ()(   ",      "))))())))",
						"Supralapsarian", ")()))()))))()(",
						" ( ( )",         ")))))(",
						"walk",           "((((",
						"Hannah",         "))))))",
						"$$\\",           "))(",
						"walk",           " ( ( )",
						"|", "(",         ""};
	
	for (int i = 0; i < 21; i++)
	{
		printf("\033[33m \"%s\" \033[0m: \033[32m %s \033[0m\n", test[i], DuplicateEncoder(test[i]));
		
	}

	return 0;
}