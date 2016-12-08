#include <stdio.h>

int main(int argc, char *argv[]) 
{
    int i, input;
    int data[1000];

    for(i=0; i<1000; i++) {
        data[i] = i + 1;
    }

    printf("Please enter a value to look for");
    return 0;
}