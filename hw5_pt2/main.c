/*

Khalil Gatto
09/30/2023 I love coding on the weekend

PROGRAM DESCRIPTION

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#define PI 3.14159

double find_magnitude(double Vx, double Vy, double Vz)
{
	double magnitude = sqrt((Vx * Vx) + (Vy * Vy) + (Vz * Vz));

	return magnitude;
	
}

void find_dotprod_angledeg(double Vx1, double Vy1, double Vz1, double Vx2, double Vy2, double Vz2, double* dotprod, double* angle_deg)
{
	*dotprod = Vx1 * Vx2 + Vy1 * Vy2 + Vz1 * Vz2;

	double V1V2 = Vx1 * Vx2 + Vy1 * Vy2 + Vz1 * Vz2;
	double mag_V1 = sqrt((Vx1 * Vx1) + (Vy1 * Vy1) + (Vz1 * Vz1));
	double mag_V2 = sqrt((Vx2 * Vx2) + (Vy2 * Vy2) + (Vz2 * Vz2));
	*angle_deg = acos((V1V2) / (mag_V1 * mag_V2)) * (180 / PI);
}


int main(void) {

	char user_input = 'f';
	double Vx1, Vy1, Vz1, Vx2, Vy2, Vz2, Vx, Vy, Vz, magnitude;
	double* dotprod;
	double* angle_deg;

	while (user_input)
	{

		printf("3D Vector calculation\n");
		printf("Enter M or m to find the magnitude\n");
		printf("Enter D or d to find the dot product and angle in degrees\n");
		printf("Enter Q or q to Quit\n");
		printf("Enter your choice: ");
		scanf(" %c", &user_input);

		if ((user_input == 'M') || (user_input == 'm'))
		{
			printf("Enter Vx Vy Vz (seperated by spaces): ");
			scanf("%lf %lf %lf", &Vx, &Vy, &Vz);
			magnitude = find_magnitude(Vx, Vy, Vz);

			printf("magnitude of <%.2lf, %.2lf, %.2lf> is %.4lf\n\n",Vx, Vy,Vz, magnitude);
		}
		else if ((user_input == 'D') || (user_input == 'd'))
		{
			printf("Enter Vx1 Vy1 Vz1 (seperated by spaces): ");
			scanf("%lf %lf %lf", &Vx1, &Vy1, &Vz1);
			printf("Enter Vx2 Vy2 Vz2 (seperated by spaces): ");
			scanf("%lf %lf %lf", &Vx2, &Vy2, &Vz2);

			find_dotprod_angledeg(Vx1, Vy1, Vz1, Vx2, Vy2, Vz2, &dotprod, &angle_deg);
			printf("<%.2lf, %.2lf, %.2lf> dot <%.2lf, %.2lf, %.2lf> is %.4lf\n", Vx1, Vy1, Vz1, Vx2, Vy2, Vz2, dotprod);
			printf("angle between these two vectors is %.4lf degrees\n\n", angle_deg);
		}
		else if ((user_input == 'q') || (user_input == 'Q'))
		{
			printf("Good Bye\n");
			break;
		}
		else
		{
			printf("wrong option entered\n\n");
		}

	}

	return 0;
}
