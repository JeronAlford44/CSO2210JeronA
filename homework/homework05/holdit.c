#include <stdio.h>
#include <time.h>

void instructions() {
    printf("This program will time how long you can hold your breath. Take a deep breath, then press the 'Enter' key. When you absolutely have to exhale, press the 'Enter' key again. The duration will be displayed in minutes and seconds.\n");
}

int main() {
    instructions();

    printf("Press 'Enter' to begin...");
    getchar();

    time_t start_time = time(NULL);

    printf("Press 'Enter' to stop...");

    getchar();

    time_t end_time = time(NULL);

    double duration = difftime(end_time, start_time);

    int minutes = (int)(duration / 60);
    int seconds = (int)(duration) % 60;

    printf("You held your breath for %d minutes and %d seconds.\n", minutes, seconds);

    return 0;
}
