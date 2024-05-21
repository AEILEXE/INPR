#include <stdio.h>

int main() {
    FILE *fptr;
    char filename[100];
    char c;
    printf("Input the file name: ");
    scanf("%s", filename);
    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    printf("This is the content of the file %s.\n", filename);
    while ((c = fgetc(fptr)) != EOF) {
        putchar(c);
    }

    fclose(fptr);
    return 0;
}

