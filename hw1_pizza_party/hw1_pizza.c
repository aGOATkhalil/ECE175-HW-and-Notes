
#include <stdio.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS






int main(void) 
{
    int num_people_f, num_people_sat, num_people_sun, pizzas_per_box;
    double avg_slices_pp_f, avg_slices_pp_sat, avg_slices_pp_sun, pizza_cost_f, pizza_cost_sat, pizza_cost_sun;
    double num_boxes_f, num_boxes_sat, num_boxes_sun, num_slices_f, num_slices_sat, num_slices_sun;

    
    double sales_tax = 0.07;
    double delivery_fee = 0.2;
    pizzas_per_box = 8;
    

    scanf_s("%d %lf %lf", &num_people_f, &avg_slices_pp_f, &pizza_cost_f);
    scanf_s("%d %lf %lf", &num_people_sat, &avg_slices_pp_sat, &pizza_cost_sat);
    scanf_s("%d %lf %lf", &num_people_sun, &avg_slices_pp_sun, &pizza_cost_sun);


    num_slices_f = num_people_f * avg_slices_pp_f; // person * slice/person == slice
    num_boxes_f = ceil(num_slices_f / pizzas_per_box); // 8slices/box * slices/person == box/person 

    num_slices_sat = num_people_sat * avg_slices_pp_sat; // person * slice/person == slice
    num_boxes_sat = ceil(num_slices_sat / pizzas_per_box); // 8slices/box * slices/person == box/person 

    num_slices_sun = num_people_sun * avg_slices_pp_sun; // person * slice/person == slice
    num_boxes_sun = ceil(num_slices_sun / pizzas_per_box); // 8slices/box * slices/person == box/person 

    double total_cost_f = pizza_cost_f * ceil(num_boxes_f); // $/box * box = $
    double tax_of_total_f = total_cost_f * sales_tax;
    double delivery_fee_f = delivery_fee * (total_cost_f + tax_of_total_f);
    double new_total_f = tax_of_total_f + total_cost_f + delivery_fee_f;

    double total_cost_sat = pizza_cost_sat * ceil(num_boxes_sat); // $/box * box = $
    double tax_of_total_sat = total_cost_sat * sales_tax;
    double delivery_fee_sat = delivery_fee * (total_cost_sat + tax_of_total_sat);
    double new_total_sat = tax_of_total_sat + total_cost_sat + delivery_fee_sat;

    double total_cost_sun = pizza_cost_sun * ceil(num_boxes_sun); // $/box * box = $
    double tax_of_total_sun = total_cost_sun * sales_tax;
    double delivery_fee_sun = delivery_fee * (total_cost_sun + tax_of_total_sun);
    double new_total_sun = tax_of_total_sun + total_cost_sun + delivery_fee_sun;

    double weekend_total = new_total_f + new_total_sat + new_total_sun;
  
    printf("Friday Night Party\n");
    printf("%.0lf Pizzas: $%0.2lf\n", ceil(num_boxes_f), total_cost_f);
    printf("Tax: $%.2lf\n", tax_of_total_f);
    printf("Delivery: $%.2lf\n", delivery_fee_f);
    printf("Total: $%.2lf\n", new_total_f);

    printf("\n");
    printf("Saturday Night Party\n");
    printf("%.0lf Pizzas: $%0.2lf\n", ceil(num_boxes_sat), total_cost_sat);
    printf("Tax: $%.2lf\n", tax_of_total_sat);
    printf("Delivery: $%.2lf\n", delivery_fee_sat);
    printf("Total: $%.2lf\n", new_total_sat);

    printf("\n");
    printf("Sunday Night Party\n");
    printf("%.0lf Pizzas: $%0.2lf\n", ceil(num_boxes_sun), total_cost_sun);
    printf("Tax: $%.2lf\n", tax_of_total_sun);
    printf("Delivery: $%.2lf\n", delivery_fee_sun);
    printf("Total: $%.2lf\n", new_total_sun);

    printf("Weekend Total: $%.2lf\n", weekend_total);


	return 0;
}