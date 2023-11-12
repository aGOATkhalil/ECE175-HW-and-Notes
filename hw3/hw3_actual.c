/*

09/15/2023
Khalil Gatto
hw3.c

This program takes a number (zip code) and outputs the number of digits and translates the input to text.

*/



#include <stdio.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS


int main()
{

	int user_input, temp_var;
	int count = 0;

	printf("Enter a 5-digit area code:");
	scanf("%d", &user_input);


	int flag_digit = user_input % 1000000 / 100000; // if there is a digit, ask user to input again.
	temp_var = user_input;


	//do
	//{
	//	user_input /= 10;
	//	++count;
	//} while (user_input != 0);
		
	while (user_input)
	{
		user_input /= 10;
		++count;

		if (user_input == 0)
		{

			if (count == 5)
			{ 

				int fifth_digit = temp_var % 10; //input: 12345. fifth_digit = 5
				int fourth_digit = temp_var % 100 / 10; //input: 12345. fourth_digit = 4
				int third_digit = temp_var % 1000 / 100;
				int second_digit = temp_var % 10000 / 1000;
				int first_digit = temp_var % 100000 / 10000;

				//printf("%d\n", user_input);
				printf("%d\n", first_digit);
				printf("%d\n", second_digit);
				printf("%d\n", third_digit);
				printf("%d\n", fourth_digit);
				printf("%d\n", fifth_digit);


				switch (first_digit) //this is a sin. switch statements to print number from digit.
				{
					case 0:
						printf("zero ");
						break;
					case 1:
						printf("one ");
						break;
					case 2:
						printf("two ");
						break;
					case 3:
						printf("three ");
						break;
					case 4:
						printf("four ");
						break;
					case 5:
						printf("five ");
						break;
					case 6:
						printf("six ");
						break;
					case 7:
						printf("seven ");
						break;
					case 8:
						printf("eight ");
						break;
					case 9:
						printf("nine ");
						break;
					default:
						printf("Something went wrong. ");
				}

				switch (second_digit)
				{
				case 0:
					printf("zero ");
					break;
				case 1:
					printf("one ");
					break;
				case 2:
					printf("two ");
					break;
				case 3:
					printf("three ");
					break;
				case 4:
					printf("four ");
					break;
				case 5:
					printf("five ");
					break;
				case 6:
					printf("six ");
					break;
				case 7:
					printf("seven ");
					break;
				case 8:
					printf("eight ");
					break;
				case 9:
					printf("nine ");
					break;
				default:
					printf("Something went wrong. ");
				}

				switch (third_digit)
				{
				case 0:
					printf("zero ");
					break;
				case 1:
					printf("one ");
					break;
				case 2:
					printf("two ");
					break;
				case 3:
					printf("three ");
					break;
				case 4:
					printf("four ");
					break;
				case 5:
					printf("five ");
					break;
				case 6:
					printf("six ");
					break;
				case 7:
					printf("seven ");
					break;
				case 8:
					printf("eight ");
					break;
				case 9:
					printf("nine ");
					break;
				default:
					printf("Something went wrong. ");
				}

				switch (fourth_digit)
				{
				case 0:
					printf("zero ");
					break;
				case 1:
					printf("one ");
					break;
				case 2:
					printf("two ");
					break;
				case 3:
					printf("three ");
					break;
				case 4:
					printf("four ");
					break;
				case 5:
					printf("five ");
					break;
				case 6:
					printf("six ");
					break;
				case 7:
					printf("seven ");
					break;
				case 8:
					printf("eight ");
					break;
				case 9:
					printf("nine ");
					break;
				default:
					printf("Something went wrong. ");
				}

				switch (fifth_digit)
				{
				case 0:
					printf("zero ");
					break;
				case 1:
					printf("one ");
					break;
				case 2:
					printf("two ");
					break;
				case 3:
					printf("three ");
					break;
				case 4:
					printf("four ");
					break;
				case 5:
					printf("five ");
					break;
				case 6:
					printf("six ");
					break;
				case 7:
					printf("seven ");
					break;
				case 8:
					printf("eight ");
					break;
				case 9:
					printf("nine ");
					break;
				default:
					printf("Something went wrong. ");
				}

			}
			else if ((count > 5) || (count < 5))
			{
				printf("you entered %d digits.\n", count);

				printf("Enter a 5-digit area code: ");
				scanf("%d", &user_input);
				temp_var = user_input;
				count = 0; //reset count
			}
		}
		else 
		{
			continue;
		}



	}



	printf("\n%d\n", temp_var);
	printf("%d\n", user_input);
	printf("%d\n", count);






























	// Part 2
	//int num1 = 0;
	//int i = 0;
	//int max_val = 0; 

	//

	//while (num1 >= 0)
	//{
	//	scanf("%d", &num1);

	//	if (num1 < 0)
	//	{
	//		break;
	//	}
	//	
	//	if (num1 > max_val)
	//	{
	//		max_val = num1;
	//	}

	//}

	//printf("%d", max_val);



	//for (i = 0; i <= num1; i++)
	//{
	//	 //shift + end to highlight whole line

	//	if (i > num1)
	//	{
	//		max_val = i;
	//	 }




	//}

	//Part 1
	//int num1;
	//int sum = 0;
	//int i = 0;
	//int count = 0;
	//double average;

	//scanf("%d", &num1);

	////int first_digit = num1 % 10;
	////int tenths_digit = num1 % 100 / 10;
	////printf("%d\n%d", tenths_digit, first_digit);

	//if ((num1 >= 10) && (num1 <= 99))
	//{
	//	for (i = num1; i > 10; --i)
	//	{
	//		printf("%d ", i);

	//		int first_digit = i % 10;
	//		int tenths_digit = i % 100 / 10;

	//		int is_first_odd = first_digit % 2;
	//		int is_tenths_odd = tenths_digit % 2;
	//		
	//		count += 1;
	//		sum += i;

	//		if((is_first_odd== 1) && (is_tenths_odd== 1))
	//		{
	//			i = 10; //stop the loop. 
	//			printf("\n");
	//		}
	//	}
	//	average = (double)sum / count;
	//	printf("Average is: %.2lf\n", average);
	//}
	//else
	//{
	//	printf("Input must be 10-99");
	//}



	return 0;
}