
//Question 5 on practice exam

#include <stdio.h>

int main(void) {
	int i, j, val = 0;
	int Mat[3][3] = { {-5,-3,-4}, {-3,-1,10},{1,1,2} };
	int num[] = { -100,-100,-100 };

	for (j = 0; j < 3; j++) {
		val = val + Mat[j][j];
		for (i = 0; i < 3; i++) {
			if (Mat[i][j] > num[j]) {
				num[j] = Mat[i][j];
			}
		}
		printf("%d\t",num[j]);
	}
	printf("\n%d", val);

	return 0;
}