
#include <stdio.h>
int main(void) {
    const int NUM_ELEMENTS = 4;
    int userVals[4];
    int i;

    userVals[0] = -2;
    userVals[1] = 4;
    userVals[2] = -5;
    userVals[3] = 7;

    for (i = 0; i < NUM_ELEMENTS; ++i) {
        if (userVals[i] < 0) {
            userVals[i] = -1 * userVals[i];
        }
        printf("%d\n", userVals[i]);
    }

    return 0;
}