

/*
Khalil Gatto
09/30/2023 I love coding on the weekend, no joke.

HW5 ECE175

This computes the bill from residential, business, and gov parameters according to their respective rates.

*/



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


double water_billcalculation(char user_type, int water_use) //why is camel case convention for variables in C?
{
    /*
        PARAMETERS:
        Residential - Cost = 0.04 ft^3 IF water_usage <= 400. for first 400 ft^3 PLUS 13.50
                      Cost = 0.062 ft^3 IF 400 < w <= 700. for next 300 ft^3 PLUS 13.50
                      Cost = 0.12 ft^3 IF w > 700. PLUS 13.50

        Government - Cost = 0.035 PLUS 3.75
        Business - Cost = 0.0553 PLUS 17.25

        Tax rate = 8.7% == 0.087


    */

    double cost;
    double cost_after_tax;
    double tax_rate = 0.087;

    if ((user_type == 'r') || (user_type == 'R'))
    {
        if (water_use <= 400) //calculation before tax.
        {
            cost = (double)(water_use) * 0.04 + 13.50;
        }
        else if ((400 < water_use) && (water_use <= 700))
        {
            cost = ((400.0 * 0.04) + 13.50) + ((double)(water_use)- 400.0) * 0.062; //conv int data type to double.
        }
        else if (water_use > 700)
        {
            cost = (400.0 * 0.04) + 13.50 + (300 * 0.062) + ((double)water_use - 700.0) * 0.12;
        }
        cost_after_tax = (tax_rate * cost) + cost;

    }
    else if ((user_type == 'b') || (user_type == 'B')) //calc before and after tax.
    {
       cost = (double)water_use * 0.0553 + 17.25;
       cost_after_tax = (tax_rate * cost) + cost;
    }
    else if ((user_type == 'g') || (user_type == 'G')) //calc before and after tax.
    {
        cost = (double)water_use * 0.035 + 3.75;
        cost_after_tax = (tax_rate * cost) + cost;
    }
    else
    {
        cost_after_tax = 0;
    }

    return cost_after_tax;
}


int main()
{
    //define vars here 
    char user_type; // user types: r g b M R G A B y D. If not r/R, g/G, or b/B, then user type not found.
    int water_use; //units: cubic feet.
    double cost_after_tax;

    FILE* inp;
    inp = fopen("usage_data.txt", "r");

    if (inp != NULL)
    {
        printf("Type\tWater usage\tCost including tax($)\n"); //bring top 3 headers
        while (fscanf(inp, "%c%d ", &user_type, &water_use) != EOF) //read the entire file until EOD.
        {
            switch (user_type) //ensure char is always a lowercase char, for ease of computation
            {
                case 'R':
                    printf("%c\t", user_type);
                    user_type = 'r';
                    break;
                case 'B':
                    printf("%c\t", user_type);
                    user_type = 'b';
                    break;
                case 'G':
                    printf("%c\t", user_type);
                    user_type = 'g';
                    break;
                case 'r':
                    printf("%c\t", user_type);
                    break;
                case 'b':
                    printf("%c\t", user_type);
                    break;
                case 'g':
                    printf("%c\t", user_type);
                    break;
                default:
                    printf("%c\tType is not found\n",user_type);
                    water_use = 0;
                    break;
            }
            
            
            cost_after_tax = water_billcalculation(user_type, water_use);

            if ((cost_after_tax != 0) && (water_use != 0))
            {
                printf("%d\t", water_use);
                printf("\t%.2lf\n", cost_after_tax);
            }
            else
            {
                continue;
            }
        }
        fclose(inp);
    }
    else
    {
        printf("File did not open.\n");
    }

    return 0;
}




