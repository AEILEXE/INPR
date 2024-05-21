/* Name: Recto, Whinelit Mae L.
Section: BSIT-1-YB-1
Activity Name: Assignment No. 7: Error Handling
File Name: RECTO_Assignment7
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>

int main () {
    FILE *f;
    int errornum;

    f = fopen("article.txt", "rb");
    if (f == NULL) {
        errornum = errno;
        fprintf(stderr, "The Value of errno: %d\n", errornum);
        perror("Error message that is printed by perror");
        fprintf(stderr, "Error message for opening file that does not exist: %s\n", strerror(errornum));
    } else {
        fclose(f);
    }
    return 0;
}

