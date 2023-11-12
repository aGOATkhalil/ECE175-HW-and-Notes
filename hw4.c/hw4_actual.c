/*

Created by Khalil Gatto
09/25/2023

BRIEF DESCRIPTION OF PROGRAM

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Calculate AGI and repair any negative values
int CalcAGI(int wages, int interest, int unemployment) {
	/* Complete the function and update the return statement */

	int local_agi = abs(wages) + abs(interest) + abs(unemployment);

	return local_agi;
}

// Calculate deduction depending on single, dependent or married
int GetDeduction(int status) {
	
	int deduction;

	switch (status)
	{
	case 0: //dependent
		deduction = 6000;
		break;
	case 1: //single
		deduction = 12000;
		break;
	case 2: //married
		deduction = 24000;
		break;
	default: 
		deduction = 6000;
		break;
	}

	return deduction;
}

// Calculate taxable but not allow negative results
int CalcTaxable(int agi, int deduction) {
	
	int taxable_amount = agi - deduction;

	if (taxable_amount < 0)
	{
		taxable_amount = 0;
	}


	return taxable_amount;
}

// Calculate tax for single or dependent
int CalcTax(int status, int taxable) {
	
	double tax_amount;

	if ((status == 1) || (status == 0)) //for single and dependent people
	{
		if ((taxable >= 0) && (taxable <= 10000))
		{
			tax_amount = 0.10 * taxable;
		}
		else if ((taxable >= 10001) && (taxable <= 40000))
		{
			tax_amount = (0.12 * (taxable - 10000)) + 1000;
		}
		else if ((taxable >= 40001) && (taxable <= 85000))
		{
			tax_amount = (0.22 * (taxable - 40000)) + 4600;
		}
		else if (taxable > 85000)
		{
			tax_amount = (0.24 * (taxable - 85000)) + 14500;
		}
		else
		{
			printf("Something went wrong.");
		}
	}
	else if (status == 2) //for married couples
	{
		if ((taxable >= 0) && (taxable <= 20000))
		{
			tax_amount = 0.10 * taxable;
		}
		else if ((taxable >= 20001) && (taxable <= 80000))
		{
			tax_amount = (0.12 * (taxable - 20000)) + 2000;
		}
		else if (taxable > 80000)
		{
			tax_amount = (0.22 * (taxable - 80000)) + 9200;
		}
		else
		{
			printf("Something went wrong.");
		}
	}


	tax_amount = round(tax_amount);
	tax_amount = (int)tax_amount;

	return tax_amount;
}

// Calculate tax due and check for negative withheld
int CalcTaxDue(int tax, int withheld) {
	

	if (withheld < 0)
	{
		withheld = 0;
	}

	int tax_due = tax - withheld;

	return tax_due;
}

int main(void) {
	int wages, interest, unemployment, status, withheld;
	int tax, agi, due, deduction, taxable;

	scanf("%d %d %d %d %d", &wages, &interest, &unemployment, &status, &withheld);

	// Step #2: Calculate AGI
	agi = CalcAGI(wages, interest, unemployment);
	deduction = GetDeduction(status);
	taxable = CalcTaxable(agi, deduction);
	tax = CalcTax(status, taxable);
	due = CalcTaxDue(tax, withheld);


	printf("AGI: $%d\n", agi);
	printf("Deduction: $%d\n", deduction);
	printf("Taxable income: $%d\n", taxable);
	printf("Federal tax: $%d\n", tax);
	printf("Tax due: $%d\n", due);

	return 0;
}


/*

int main()
{
	FILE* inp, * outp;
	char corrupted_romeo;

	inp = fopen("Romeo.txt", "r");
	outp = fopen("Romeofixed.txt", "w");

	if (inp != NULL)
	{
		printf("File opened.");

		for (int i = 0; i <= 8; i++) //iterate 8 times because there are 8 characters to check for.
		{
			while (fscanf(inp, "%c", &corrupted_romeo) != EOF) //while the file is not at the end....
			{
				printf("%c", corrupted_romeo); //print char in terminal for me
				switch (corrupted_romeo) //for each case of actual character, assign var with corrected char and output to file.
				{
				case '#':
					corrupted_romeo = '\'';
					fprintf(outp,"%c", corrupted_romeo);
					break;
				case '*':
					corrupted_romeo = '.';
					fprintf(outp, "%c", corrupted_romeo);
					break;

				case '>':
					corrupted_romeo = 'a';
					fprintf(outp, "%c", corrupted_romeo);
					break;

				case '/':

					corrupted_romeo = 'e';
					fprintf(outp, "%c", corrupted_romeo);
					break;

				case '{':

					corrupted_romeo = 'i';
					fprintf(outp, "%c", corrupted_romeo);
					break;

				case '6':

					corrupted_romeo = 'o';
					fprintf(outp, "%c", corrupted_romeo);
					break;

				case ']':

					corrupted_romeo = 'u';
					fprintf(outp, "%c", corrupted_romeo);
					break;

				default:
					fprintf(outp, "%c", corrupted_romeo);
				}
			}
		}
	}
	else
	{
		printf("This file does not exist.");
	}

	fclose(inp);
	fclose(outp);
	return 0;
}





*/