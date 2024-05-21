/* Name: Recto, Whinelit Mae L.
Section: BSIT-1-YB-1
Activity Name: Machine Problem 5: Structures
File Name: RECTO_MachineProblem 5
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
const int MAX_COURSES = 20;
const int MAX_STUDENTS = 150;
const int COURSE_CODE_LENGTH = 8;
const int COURSE_TITLE_LENGTH = 60;
struct Course {
char code[COURSE_CODE_LENGTH];
char title[COURSE_TITLE_LENGTH];
int score;
};
struct Student {
char name[50];
struct Course courses[MAX_COURSES];
int numCourses;
};
void courTitle(const char *code);
void studentdeets(struct Student *student);
void stdsummary(const struct Student *student);
int main() {
struct Student students[MAX_STUDENTS];
int numStudents;
printf("Enter number of students: ");
scanf("%d", &numStudents);
for (int i = 0; i < numStudents; i++) {
printf("\nStudent %d Name: ", i + 1);
scanf(" %[^\n]", students[i].name);
studentdeets(&students[i]);
}
printf("\nSUMMARY:\n");
for (int i = 0; i < numStudents; i++) {
stdsummary(&students[i]);
}
return 0;
}
void courTitle(const char *code, char *title) {
if (strcmp(code, "MAT101") == 0)
strcpy(title, "General Mathematics");
else if (strcmp(code, "COMP101") == 0)
strcpy(title, "Computer Programming");
else if (strcmp(code, "ENG101") == 0)
strcpy(title, "Basic English");
else if (strcmp(code, "SCI101") == 0)
strcpy(title, "Introduction to Science");
else if (strcmp(code, "FIL101") == 0)
strcpy(title, "Komunikasyon sa Filipino");
else
strcpy(title, "Unknown Course");
}
void studentdeets(struct Student *student) {
printf("\nEnter number of courses of %s: ", student->name);
scanf("%d", &student->numCourses);
for (int i = 0; i < student->numCourses; i++) {
printf("\nEnter course code%d: ", i + 1);
scanf("%s", student->courses[i].code);
courTitle(student->courses[i].code, student->courses[i].title);
printf("Course Title: %s\n", student->courses[i].title);
printf("Score: ");
scanf("%d", &student->courses[i].score);
}
}
void stdsummary(const struct Student *student) {
char studentName[50];
strcpy(studentName, student->name);
for (int i = 0; studentName[i] != '\0'; i++) {
studentName[i] = toupper(studentName[i]);
}
printf("\nStudent's Name: %s\n", studentName);
printf("Courses enrolled: ");
for (int i = 0; i < student->numCourses; i++) {
char courseTitle[COURSE_TITLE_LENGTH];
strcpy(courseTitle, student->courses[i].title);
for (int j = 0; courseTitle[j] != '\0'; j++) {
courseTitle[j] = toupper(courseTitle[j]);
}
printf("%s", courseTitle);
if (i != student->numCourses - 1)
printf(", ");
}
float totalScore = 0;
for (int i = 0; i < student->numCourses; i++) {
totalScore += student->courses[i].score;
}
printf("\nAverage Scores: %.2f\n", totalScore / student->numCourses);}