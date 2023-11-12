
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS_



int main()
{
	char letter;

	scanf_s("%c", &letter);

	if (letter == letter + 32)
	{
		printf("%c%c", letter + 32, letter);
	}
	else if (!(letter == letter + 32))
	{
		printf("%c%c", letter, letter - 32);
	}
	else if (!(letter == letter + 32) || (letter == letter - 32))
	{
		printf("%c", letter);
	}
	else
		printf("What?");

	return 0;
}