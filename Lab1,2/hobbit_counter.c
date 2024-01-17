#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int counter = 0;
    FILE *f = fopen("LOTR.txt", "r");
    if (f == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    char buffer[1024];
    while (fscanf(f, "%1023s", buffer) == 1) {
        if (strcmp(buffer, "hobbit") == 0) {
            counter++;
        }
    }
    printf("Found %d occurences of \"hobbit\"\n", counter);
}