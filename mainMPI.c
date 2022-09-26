#include <stdlib.h>
#include <stdio.h>
#include "crackme.h"


int main(int argc, char** argv) {

	const int alphabet = 127;

	int strSize;

	printf("INSERT VALUE: ");
	scanf("%d", strSize);

	char* str = (char*)malloc((strSize + 1) * sizeof(char));
	for (int i = 0; i < strSize; i++)
	{
		str[i] = -128;
	}

	str[strSize] = '\0';

	time_t t1 = time(0);

	while ((int)str[0] <= alphabet)
	{
		if (p(strSize, str) == 0)
		{
			time_t t2 = time(0);
			printf("Password found: %s, time taken: %f seconds\n", str, difftime(t2, t1));
			free(str);
			return 0;
		}
		
		str[strSize-1] = (int)str[strSize-1]+1;
		printf("%d \n", str[strSize-1]);
		int j = strSize - 1;
		while ((int)str[j] == alphabet)
		{
			if (j > 0)
			{
				str[j] = -128;
				j--;
				str[j] = (int)str[j] + 1;
			}
			else
			{
				free(str);
				return 0;
			}
		}
	}
	
	free(str);

	return 0;
}