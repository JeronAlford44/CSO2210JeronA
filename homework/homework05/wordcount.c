#include <stdio.h>
#include <ctype.h>

int countWords(FILE *file) {
    int count = 0;
    int isWord = 0;
    int c;

    while ((c = fgetc(file)) != EOF) {
        if (isspace(c)) {
            isWord = 0;
        } else {
            if (!isWord) {
                count++;
                isWord = 1;
            }
        }
    }

    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (!file) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    int wordCount = countWords(file);

    fclose(file);

    printf("Number of words in %s: %d\n", argv[1], wordCount);

    return 0;
}
