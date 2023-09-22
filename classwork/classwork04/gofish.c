#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ENTRY 25

int main(int argc, char * argv[]){
    char input[10];
    printf("hello word! \n");
    char allNumbers[MAX_ENTRY];
    int index = 0;
    for (int i = 0; i< MAX_ENTRY; i++){
        printf("\n enter an integer:");
        fgets(input, 10, stdin);
        // scanf("%d", &input[i]);
        printf("\n got: %s", input);

        strcpy(allNumbers[i],input);


        // Keep looping through this
        

    }

    //Display all mnumbers together 
    //TODO: Add Numbers Up and average them
    

    //TODO: Display the sum of the numbers


}