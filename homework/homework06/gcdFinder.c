#include <stdio.h>

extern unsigned long long find_gcd(unsigned long long a, unsigned long long b);

int main() {
    unsigned long long a, b, gcd;

    printf("Enter first number: ");
    scanf("%llu", &a);

    printf("Enter second number: ");
    scanf("%llu", &b);

    gcd = find_gcd(a, b);

    printf("GCD of %llu and %llu is %llu\n", a, b, gcd);

    return 0;
}