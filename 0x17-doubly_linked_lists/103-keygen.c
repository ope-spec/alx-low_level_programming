#include "lists.h"


/**
* findLargestNumber - Finds the largest number in an array of characters
*
* @username: The array of characters (username)
* @length: The length of the username
*
* Return: The largest number generated using rand() and bitwise AND operation
*/
int findLargestNumber(char *username, int length)
{
	int largest = *username;
	int i = 0;

	while (i < length)
	{
	if (largest < username[i])
	largest = username[i];
	i++;
	}

	srand(largest ^ 14);
	unsigned int randNum = rand();

	return (randNum & 63);
}

/**
* multiplyChars - Multiplies each character of a username
* @username: Pointer to the username string
* @length: Length of the username string
*
* Return: Multiplied character value
*/
int multiplyChars(char *username, int length)
{
	int output = 0;
	int i = 0;

	while (i < length)
	{
	output += username[i] * username[i];
	i++;
	}

	return (((unsigned int)output ^ 239) & 63);
}


/**
* generateRandomChar - Generates a random character based on the username
* @username: The username
*
* Return: The generated random character
*/
int generateRandomChar(char *username)
{
	int h = 0;
	int i = 0;

	while (i < *username)
	{
	h = rand();
	i++;
	}

	return (((unsigned int)h ^ 229) & 63);
}



/**
* main - Entry point
* @argc: The number of command line arguments
* @argv: Array of command line arguments
*
* Return: 0 on success
*/
int main(int argc, char **argv)
{
	char keygen[7];
	int len, h, vh;
	long alph[] = {
	0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
	0x74767a5835737956, 0x2b554c59634a474f, 0x71786636576a6d34,
	0x723161513346655a, 0x6b756f494b646850
	};
	for (len = 0; argv[1][len]; len++)
	;
	keygen[0] = ((char *)alph)[(len ^ 59) & 63];

	h = vh = 0;
	while (vh < len)
	{
	h += argv[1][vh];
	vh++;
	}
	keygen[1] = ((char *)alph)[(h ^ 79) & 63];

	h = 1;
	vh = 0;
	while (vh < len)
	{
	h = argv[1][vh] * h;
	vh++;
	}
	keygen[2] = ((char *)alph)[(h ^ 85) & 63];

	keygen[3] = ((char *)alph)[findLargestNumber(argv[1], len)];

	keygen[4] = ((char *)alph)[multiplyChars(argv[1], len)];

	keygen[5] = ((char *)alph)[generateRandomChar(argv[1])];
	keygen[6] = '\0';

	for (h = 0; keygen[h]; h++)
	printf("%c", keygen[h]);
	return (0);
}
