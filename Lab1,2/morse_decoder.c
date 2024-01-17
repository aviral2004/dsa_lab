#include <stdio.h>
#include <string.h>

void decode(char* letter, char* decoded, int index) {
    if (strcmp(letter, ".-") == 0) {
        decoded[index] = 'a';
    } else if (strcmp(letter, "-...") == 0) {
        decoded[index] = 'b';
    } else if (strcmp(letter, "-.-.") == 0) {
        decoded[index] = 'c';
    } else if (strcmp(letter, "-..") == 0) {
        decoded[index] = 'd';
    } else if (strcmp(letter, ".") == 0) {
        decoded[index] = 'e';
    } else if (strcmp(letter, "..-.") == 0) {
        decoded[index] = 'f';
    } else if (strcmp(letter, "--.") == 0) {
        decoded[index] = 'g';
    } else if (strcmp(letter, "....") == 0) {
        decoded[index] = 'h';
    } else if (strcmp(letter, "..") == 0) {
        decoded[index] = 'i';
    } else if (strcmp(letter, ".---") == 0) {
        decoded[index] = 'j';
    } else if (strcmp(letter, "-.-") == 0) {
        decoded[index] = 'k';
    } else if (strcmp(letter, ".-..") == 0) {
        decoded[index] = 'l';
    } else if (strcmp(letter, "--") == 0) {
        decoded[index] = 'm';
    } else if (strcmp(letter, "-.") == 0) {
        decoded[index] = 'n';
    } else if (strcmp(letter, "---") == 0) {
        decoded[index] = 'o';
    } else if (strcmp(letter, ".--.") == 0) {
        decoded[index] = 'p';
    } else if (strcmp(letter, "--.-") == 0) {
        decoded[index] = 'q';
    } else if (strcmp(letter, ".-.") == 0) {
        decoded[index] = 'r';
    } else if (strcmp(letter, "...") == 0) {
        decoded[index] = 's';
    } else if (strcmp(letter, "-") == 0) {
        decoded[index] = 't';
    } else if (strcmp(letter, "..-") == 0) {
        decoded[index] = 'u';
    } else if (strcmp(letter, "...-") == 0) {
        decoded[index] = 'v';
    } else if (strcmp(letter, ".--") == 0) {
        decoded[index] = 'w';
    } else if (strcmp(letter, "-..-") == 0) {
        decoded[index] = 'x';
    } else if (strcmp(letter, "-.--") == 0) {
        decoded[index] = 'y';
    } else if (strcmp(letter, "--..") == 0) {
        decoded[index] = 'z';
    } else if (strcmp(letter, ".----") == 0) {
        decoded[index] = '1';
    } else if (strcmp(letter, "..---") == 0) {
        decoded[index] = '2';
    } else if (strcmp(letter, "...--") == 0) {
        decoded[index] = '3';
    } else if (strcmp(letter, "....-") == 0) {
        decoded[index] = '4';
    } else if (strcmp(letter, ".....") == 0) {
        decoded[index] = '5';
    } else if (strcmp(letter, "-....") == 0) {
        decoded[index] = '6';
    } else if (strcmp(letter, "--...") == 0) {
        decoded[index] = '7';
    } else if (strcmp(letter, "---..") == 0) {
        decoded[index] = '8';
    } else if (strcmp(letter, "----.") == 0) {
        decoded[index] = '9';
    } else if (strcmp(letter, "-----") == 0) {
        decoded[index] = '0';
    }
}

int main() {
    FILE *f = fopen("msg.txt", "r");
    if (f == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    char line[1024];
    while (fgets(line, 1024, f) != NULL) {
        printf("%s\n", line);
    }    

    char* saveptr1;
    char* saveptr2;

    char *word = strtok_r(line, "/", &saveptr1);

    char decoded[1024];
    int index = 0;
    while (word != NULL) {
        printf("Current word: %s\n", word);
        char* letter = strtok_r(word, " ", &saveptr2);
        while (letter != NULL) {
            printf("Current letter: %s\n", letter);
            decode(letter, decoded, index);
            index++;
            letter = strtok_r(NULL, " ", &saveptr2);
        }
        decoded[index] = ' ';
        index++;
        word = strtok_r(NULL, "/", &saveptr1);
    }
    printf("Decoded message: %s\n", decoded);
}