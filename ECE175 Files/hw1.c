#include <stdio.h>

int main(void) {
	int seconds;
	int minutes;
	int hours;

	printf("Enter an integer of seconds: ");
	scanf("%d", &seconds);

	minutes = seconds / 60; // 1min/60seconds * seconds = min
	hours = minutes / 60;

	printf("\nHours: %d\n", hours);
	printf("Minutes: %d\n", minutes % 60);
	printf("Seconds: %d\n", seconds % 60);

	return 0;
}