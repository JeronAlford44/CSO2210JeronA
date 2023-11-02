#include <stdio.h>
#include <stdlib.h>

void dec2bin(unsigned int n, char* binary) {
    for (int i = 31; i >= 0; i--) {
        binary[i] = (n & 1) + '0';
        n >>= 1;
    }
    binary[32] = '\0';
}

int main(int argc, char *argv[]) {
    unsigned int num;
    char binary[33];

    if (argc == 2) {
        num = atoi(argv[1]);
    } else {
        printf("Enter a base-10 number: ");
        scanf("%u", &num);
    }

    dec2bin(num, binary);
    printf("%s\n", binary);

    return 0;
}
