#include <stdio.h>

int main() {
    FILE *fptr;
    char filename[] = "test.txt";
    char sentence[100];

    printf("Input a sentence for the file: ");
    fgets(sentence, sizeof(sentence), stdin);

    fptr = fopen(filename, "w");

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fptr, "%s", sentence);

    fclose(fptr);

    printf("The file %s created successfully...!!\n", filename);

    return 0;
}

