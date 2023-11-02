#include <stdio.h>
#include <stdlib.h>

void dec2hex(unsigned int n, int bits) {
    if (bits == 32) {
        printf("0x%08X\n", n);
    } else if (bits == 64) {
        printf("0x%016llX\n", (unsigned long long)n);
    } else {
        printf("Invalid number of bits. Please choose either 32 or 64.\n");
    }
}

int main(int argc, char *argv[]) {
    unsigned int num;
    int bits;

    if (argc == 3) {
        num = atoi(argv[1]);
        bits = atoi(argv[2]);
    } else {
        printf("Enter a base-10 number: ");
        scanf("%u", &num);
        printf("Enter the number of bits (32 or 64): ");
        scanf("%d", &bits);
    }

    dec2hex(num, bits);

    return 0;
}
