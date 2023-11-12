
//  main.c
//  hw2
//
//  Created by Khalil Gatto on 9/7/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {

    int wages, taxable_interest, unemployment_comp, partner_status, taxes_held, taxable_income;
    int deduction;
    double federal_tax, tax_due;

    scanf_s("%d %d %d %d %d", &wages, &taxable_interest, &unemployment_comp, &partner_status, &taxes_held);

    int agi = wages + taxable_interest + unemployment_comp;

    if (agi <= 120000)
    {
        switch (partner_status)
        {
        case 1:
            deduction = 12000;
            break;
        case 2:
            deduction = 24000;
            break;
        default:
            partner_status = 1;
            deduction = 12000;
            break;
        }

        taxable_income = agi - deduction;

        if (taxable_income < 0)
        {
            taxable_income = 0;
        }
       

        if (partner_status == 1)
        {
            if ((taxable_income <= 10000) && (taxable_income >= 0))
            {
                
                federal_tax = 0.10 * (taxable_income);
            }
            else if ((taxable_income <= 40000) && (taxable_income >= 10001))
            {
                federal_tax = 0.12 * (taxable_income-10000) + 1000;
            }
            else if ((taxable_income <= 85000) && (taxable_income >= 40001))
            {
                federal_tax = 0.22 * (taxable_income- 40000) + 4600;
            }
            else if (taxable_income > 85000)
            {
                federal_tax = 0.24 * (taxable_income-85000) + 14500;
            }
            else
            {
                printf("Something went wrong...1\n");
            }

        }
        else if (partner_status == 2)
        {

            if ((taxable_income <= 20000) && (taxable_income >= 0))
            {
             
                federal_tax = 0.10 * taxable_income;
            }
            else if ((taxable_income <= 80000) && (taxable_income >= 20001))
            {
                federal_tax = 0.12 * (taxable_income-20000) + 2000;
            }
            else if (taxable_income > 80000)
            {
                federal_tax = 0.22 * (taxable_income-80000) + 9200;
            }
            else
            {
                printf("Something went wrong...2\n");
            }

        }
        else
        {
            printf("What");
        }

     
        federal_tax = round(federal_tax);
        tax_due = fabs(federal_tax - taxes_held);



        printf("AGI:  $%d\n", agi);
        printf("Deduction: $%d\n", deduction);
        printf("Taxable income: $%d\n", taxable_income);
        printf("Federal tax: $%.0lf\n", federal_tax);

        if (taxes_held == 0)
        {
            printf("Taxes Owed: $.0lf", tax_due);
        }
        else
        {
            printf("Tax refund: $%.0lf\n", tax_due);
        }
        
    }
    else
    {
        printf("AGI:  $%d\n", agi);
        printf("Error: Income too high to use this form\n");
    }




    return 0;
}
