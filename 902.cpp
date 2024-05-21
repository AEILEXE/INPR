/* Name: Recto, Whinelit Mae L.
Section: BSIT-1-YB-1
Activity Name: Assignment No. 7: Error Handling
File Name: RECTO_Assignment7
*/
#include <stdio.h>

int main() {
	FILE *file;
	
	char filename[100], ch;
	
	printf("Input the file name to be opened: ");
	scanf("%s", filename);
	
	file = fopen(filename, "r");
	
	if (file == NULL) {
	printf("Unable to open the file.\n");
	return 1;
	}
	printf("\nThe content of the file %s is :\n", filename);
	while ((ch = fgetc(file)) != EOF) {
	putchar(ch);
	}
	fclose(file);
return 0;
}
