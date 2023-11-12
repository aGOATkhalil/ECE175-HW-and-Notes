//
//  main.c
//  hw7
//
//  Created by Khalil Gatto on 10/19/23.
//

#include <stdio.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

// Fill arrays with data from external file (described in another section. DO NOT MODIFY.)
void ReadCustomerData(char names[][25], char states[][25], double debts[], int size)
{
    int n;
    FILE* dataFile = NULL;
    char dataFileName[25] = "CustomerData.tsv";
    // Open the data file
    dataFile = fopen(dataFileName, "r");
    if (dataFile == NULL)
    {
        printf("Could not open file %s for reading.\n", dataFileName);
        return;
    }
    // Read the customer information
    for (n = 0; n < size; n++)
    {
        fscanf(dataFile, "%s %s %lf", names[n], states[n], &debts[n]);
    }

    // Close the data file
    fclose(dataFile);

}

int main(void)
{

    int size = NULL;
    int debt_limit;
    char fletter_fname;
    char state_abbrev[3];

    char names[size][25];
    char states[size][25];
    double debts[size];

    // Input # of customers and create parallel arrays
    scanf("%d", &names[size][25]);



    // Fill arrays with data from external file (described in another section. DO NOT MODIFY.)
    ReadCustomerData(names, states, debts, size);

    /* Type your code here */
    // Input debt limit, search phrase, and state

    for (int i = 0; i < size; i++)
    {
        printf("%s\t", names[i]);
        printf("%s\t", states[i]);
        printf("%.2lf\n", debts[i]);

    }

    printf("---------------------\n\n");


    scanf("%d %c", &debt_limit, &fletter_fname); //for debugging. its not working.
    printf("%d %c\n", debt_limit, fletter_fname); //not working. need to get state abbreviation as well.


    printf("U.S. Report\n");
    printf("Customers: %d\n", size);




    return 0;
}
