#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *name;
    char input[25];
    printf("Please Enter your name: ");
             
    if (gets(input)){
        name = input;
        printf("Hello %s!\n", name);
        
    } ;              
    return 0;
}