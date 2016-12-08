#include <stdio.h>

int main(int argc, char *argv[]) 
{
    int min = 2;
    int max = 131080;
    int iMax = max - min;
    int data[iMax];
    int input, mid;
    for(int i = 0; i < iMax; i++) {
        data[i] = min+i;
        printf("DATA[%d] = %d \n", i, data[i]);
    }

    printf("please enter a value to  look for : \n");
    scanf("%d", &input);
    // check the allowable input range.
    if(input > max-min || input < min) {
        printf("The input value exceeds the allowable range.\n");
        return 0;
    }

    mid = (max + min) / 2;
    printf("data mid : %d \n", mid);
    int tempMax = max;
    int tempMin = min;

    while(1) {

        if(mid == input) {
            printf("Search result  to find is in the data[%d] \n", mid - min );
            return 0;
        }
        else if (mid < input) {
            tempMin = mid;
        }
        else {
           tempMax = mid;
        }
        mid = (tempMax + tempMin) / 2;
        printf("data max - min  : %d  - %d \n", tempMax, tempMin);
        printf("data mid : %d \n", mid);
    }
}