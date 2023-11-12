
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int input_num;
	//long double output_of_num;

	printf("Enter any integer: ");
	scanf_s("%d", &input_num);

	while (input_num != 1)
	{
		if (input_num % 2 == 0)
		{
			input_num = input_num / 2;
		}
		else if (input_num % 2 == 1)
		{
			input_num = 3 * input_num + 1;
		}
		//output_of_num = input_num;
		printf("%d\n", input_num);
		input_num = input_num;
	}
	//to get this running, i have to create a new project for each file and select "set as startup project" to run indiv.
	//the conjecture is limited to the data types defined in C. Cannot get past 15 digits.
	return 0;

}