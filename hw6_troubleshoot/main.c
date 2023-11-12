
/*

	by Khalil Gatto
	10/15/2023
	
	This program decides whether a given IMEI code is valid or not. 

*/



#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS


void print_IMEI(int IMEI[], int size)
{
	//input: an array call IMEI, size is total number of elements in IMEI
	//display 15 digit of IMEI value. End with newline (‘\n’)

	printf("IMEI: ");
	for (int i = 0; i <= size; i++)
	{
		printf("%d", IMEI[i]);
	}
	printf("\n");
}

int calc_sum(int IMEI[], int size)
{
	//input: an array call IMEI, size is total number of elements in IMEI
	//output: return a total sum of 14 digits of the IMEI array using the
	//algorithm on page 1
	int sum_odd = 0;
	int sum_even = 0;
	int sum = 0;
	int div_and_conquer = 0;

	for (int i = 0; i < size - 1; i++)
	{
		if ((i+1) % 2 == 1)
		{
			sum_odd = IMEI[i] + sum_odd;
			//printf("odd %d ", IMEI[i]);
		}

		if ((i+1) % 2 == 0)
		{
			if (2 * IMEI[i] >= 10)
			{
				div_and_conquer = ((2 * IMEI[i]) / (10)) + ((2 * IMEI[i]) % 10);
				//printf("%d, %d\n", ((2 * IMEI[i]) / (10)), ((2 * IMEI[i]) % 10));
				//printf("div and conq = %d\n", div_and_conquer);
			}
			else
			{
				div_and_conquer = 2 * IMEI[i];
				//printf("%d\n", div_and_conquer);
			}

			sum_even = div_and_conquer + sum_even;
			//printf("even %d ", div_and_conquer);
		}

	}

	sum = sum_odd + sum_even;

	//printf("%d\n", sum);

	return sum;

}

int main(void)
{
	FILE *inp;
	inp = fopen("List_IMEI.txt", "r");
	int file_data;
	int count = 0;
	int IMEI[15];
	int sum = 0;

	if (inp != NULL)
	{
		while (fscanf(inp, "%d", &file_data) != EOF)
		{
			/*
				Fill an array of 15 elements. Then pass the array to calc_sum.
				We need the compare the .txt 15 digits and the Luhn digit. If equal, then imei is valid.

				Luhn digit is computed by:
					sum of numbers in odd positions
					2*n of even positioned number.
						if outcome is two digit, add first digit with second.
				If last digit of the computed sum == 0, that is check digit. If not, subtract last dig from computed sum from 10.

				Loop the next line and repeat algorithm.

			*/

			IMEI[count] = file_data;

			if (count == 14)
			{
				print_IMEI(IMEI, count);
				sum = calc_sum(IMEI, 15);

				printf("total sum of %d digits = %d\n", count, sum);
				int luhn_digit = IMEI[count];
				printf("Luhn digit = %d\n", luhn_digit);

				int check_digit = sum % 10;

				switch (check_digit)
				{
				case 0:
					check_digit = check_digit;
					break;
				default:
					check_digit = 10 - check_digit;
					break;
				}

				printf("check digit = %d\n", check_digit);

				if (check_digit == luhn_digit)
				{
					printf("IMEI is valid\n\n");
				}
				else
				{
					printf("IMEI is invalid\n\n");
				}

				count = 0;
			}
			else
			{
				count++;
			}



		}
	}
	else
	{
		printf("File cannot be opened.");
	}

	fclose(inp);


	return 0;
}