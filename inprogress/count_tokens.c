#include "main.h"

/**
 * count_tokens - counts the number of tokens available
 *
 * @linePtr: String to be parsed
 * @delim: delimiter for tokenizaton
 * Return: number of tokens
 */

int count_tokens(char *LinePtr, char *delim)
{
	char *token2 = NULL;
	int counterT = 0;

	/*break linePtr_copy string into an array of word*/
	token2 = strtok(LinePtr, delim);
	/*traverse tokens and count*/

	while (token2 != NULL)
	{
		counterT++;
		token2 = strtok(NULL, delim);
	}
	/* counterT++; */
	/*printf("token count: %d \n", counterT); print number of tokens*/
	if (token2 != NULL)
		free(token2);
	return (counterT);
}
