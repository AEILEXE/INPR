/* Name: Recto, Whinelit Mae L.
Section: BSIT-1-YB-1
Activity Name: Assignment No. 5: File Input and Output
File Name: RECTO_Assignment5_File
*/
#include <stdio.h>

int main() {
    FILE *fp;
    char filename[50], sentence[100], ch;

    printf("Input a sentence for the file: ");
    fgets(sentence, sizeof(sentence), stdin);


    fp = fopen("test.txt", "w");
    if (fp == NULL) {
        printf("Failed to create the file.\n");
        return 1;
    }
    fprintf(fp, "%s", sentence);
    fclose(fp);
    printf("The file test.txt created successfully...!!\n");

    printf("\nInput the file name to be opened: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    printf("The content of the file %s is:\n", filename);
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp);

    return 0;
}
