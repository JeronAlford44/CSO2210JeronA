#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    char *name;
    char input[25];
    printf("Please Enter your name: ");

    fgets(input, 25, stdin);
    
    
    printf("Hello %s!\n", input);
    
    return 0;
}