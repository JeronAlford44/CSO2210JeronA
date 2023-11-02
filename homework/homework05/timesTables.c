#include <stdio.h>
#include <stdlib.h>

void displayTable(int n) {
    printf("   |");
    for (int i = 2; i <= n; i++) {
        printf("%4d", i);
    }
    printf("\n---+");
    for (int i = 2; i <= n; i++) {
        printf("----");
    }
    printf("\n");

    for (int i = 2; i <= n; i++) {
        printf("%2d |", i);
        for (int j = 2; j <= n; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <N>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);

    if (N < 2) {
        printf("N must be at least 2.\n");
        return 1;
    }

    displayTable(N);

    return 0;
}
