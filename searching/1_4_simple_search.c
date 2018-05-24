#include <stdio.h>

int main(int argc, char *argv[]) 
{
    int i, input;
    int data[10000];

    for(i=0; i<1000; i++) {
        data[i] = i + 1;
    }

    printf("Please enter a value to look for");
    scanf("%d", &input);
    for(i=0; i<1000; i++) {
        if(input == data[i]) {
            printf("The value you are trying to find is on %d of the Array data. \n", i);
            break;
        }
    }

    return 0;
}