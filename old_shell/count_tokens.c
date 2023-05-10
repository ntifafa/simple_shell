#include "main.h"

/**
 * count_tokens - counts the number of tokens available
 *
 * @linePtr: String to be parsed
 * @delim: delimiter for tokenizaton
 * Return: number of tokens
 */

int count_tokens(char *linePtr, const char *delim)
{
	char *token;
	int counterT = 0;

	/*break linePtr_copy string into an array of word*/
	token = strtok(linePtr, delim);
	/*traverse tokens and count*/

	while (token != NULL)
	{
		counterT++;
		token = strtok(NULL, delim);
	}
	/* counterT++; */
	/*printf("token count: %d \n", counterT); print number of tokens*/
	if (token != NULL)
		free(token);
	return (counterT);
}
