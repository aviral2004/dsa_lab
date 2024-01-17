#include <stdio.h>
#include <stdlib.h>

int main() {
    //  For this, you need to write a menu-driven program that asks the user for the initial length of the array, and then stores those corresponding strings (also taken as input) into a dynamic array initialised with that length
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);
    char *arr[length];
    for (int i = 0; i < length; i++) {
        printf("Enter the string %d: ", i + 1);
        arr[i] = malloc()
        scanf("%s", arr[i]);
    }

    for (int i = 0; i < length; i++) {
        printf("%s\n", array[i]);
    }
}