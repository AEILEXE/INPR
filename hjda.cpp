#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define BLANK " "
char blank[] = BLANK;

struct Student{
	struct Personal{
		char id[12];
		char first_Name[30];
		char middle_Name[30];
		char last_Name[30];
		char address[50];
		char birthdate[11];
		int age;
		char gender[5]; // male/female
		char phone_Number[12];
		char email_Address[30];
		char mother_First_Name[30];
		char mother_Middle_Name[30];
		char mother_Last_Name[30];
		char mother_Occupation[30];
		char father_First_Name[30];
		char father_Middle_Name[30];
		char father_Last_Name[30];
		char father_Occupation[30];
		char guardian_Number[12];
	}per;
	
	struct Documents{
		char has_BirthCertificate;
		char has_MarriageContract;
		char has_Diploma;
		char has_Form137;
		char has_ReportCard;
	}doc;
	
	struct Enrollment{
		int strand;  // 0.STEM 1.HUMSS 2.ABM 3.GAS
		int yearlvl; // 11 = 11, 12=12
		int semester; // 1 = first sem, 2 = second sem.
		int section; // 1 , 2
	}enr;
	
	struct Payment{
		float outstandingbal;
	}pay;
	
	struct Flags{
		int isEnrolled;
	}flg;
};
struct Student stu;

char choice;


void pause(){
	printf("\n");
	system("pause");
	return;
}
void continue_Choice(char cntChoice){
	choice = cntChoice;
	return;
}
void clear_Screen(){
	system("cls");
	return;
}
void call_Error(int mode){
	switch (mode){
		case 1:
			printf("\nError Cannot write to file.");
			break;
		case 6:
			printf("This student is already enrolled");
			break;
		default:
			break;
	}
	return;}
void print_Modal(char header[], int type){
	int c, i;
	switch(type) {
		case 1:
			for(i = 0; i <95 ; i++ )printf("=");printf("\n");
			for(i = 0; i <95 ; i++ ){if(i < 2)printf("|");else if( i > 92)printf("|");else printf("%s", blank);} printf("\n");
			c = ceil(45  - (strlen(header) / 2)); printf("||");for(i = 0; i < c ; i++ )printf(" "); printf(header);  for(i = 0; i < c ; i++ )printf("%s", blank);printf("||\n");
			for(i = 0; i <95 ; i++ ){if(i < 2)printf("|");else if( i > 92)printf("|");else printf("%s", blank);} printf("\n");
			for(i = 0; i <95 ; i++ )printf("=");printf("\n");
		break;
		
		case 2: 
			c = ceil(45  - (strlen(header) / 2)); printf("==");for(i = 0; i < c ; i++ )printf(" "); printf(header);  for(i = 0; i < c ; i++ )printf("%s", blank);printf("==\n\t\t\t\t>");
		break;
	}
	return;
}






// no more issues 
void menu_Registration(){
	clear_Screen();
	print_Modal("Registration ", 1);
	
	char gender;
	char menu_Choice;
	
	FILE *fpointer;
	fpointer = fopen("record.txt", "ab+");
	
	if(fpointer == NULL){
		call_Error(1);
	}else{
		print_Modal("Student ID ex.[123456789000]:", 2);gets(stu.per.id);
		print_Modal("Students First Name:", 2);gets(stu.per.first_Name);
		print_Modal("Students Middle Name:", 2);gets(stu.per.middle_Name);
		print_Modal("Students Last Name:", 2);gets(stu.per.last_Name);
		print_Modal("Address:", 2);gets(stu.per.address);
		print_Modal("Birthdate ex.[MM/DD/YYYY]:", 2);gets(stu.per.birthdate);
		print_Modal("Age:", 2);scanf("%i", &stu.per.age);getchar(); // ??? gumagana to idk why
		print_Modal("Gender [male/female]:", 2);gets(stu.per.gender);
		print_Modal("Phone Number ex.[09123456789]:", 2);gets(stu.per.phone_Number);
		print_Modal("Email Address:", 2);gets(stu.per.email_Address);
		print_Modal("Mother's First Name:", 2);gets(stu.per.mother_First_Name);
		print_Modal("Mother's Middle Name:", 2);gets(stu.per.mother_Middle_Name);
		print_Modal("Mother's Last Name:", 2);gets(stu.per.mother_Last_Name);
		print_Modal("Fathers's First Name:", 2);gets(stu.per.father_First_Name);
		print_Modal("Fathers's Middle Name:", 2);gets(stu.per.father_Middle_Name);
		print_Modal("Fathers's Last Name:", 2);gets(stu.per.mother_Last_Name);
		print_Modal("Guardians' Phone Number ex.[09123456789]:", 2);gets(stu.per.guardian_Number);
		print_Modal("Do you want to save this student to the database? [y/n]", 2);menu_Choice = getche();

		if(menu_Choice != 'n'){
				if(fwrite(&stu, sizeof(stu), 1, fpointer) == 1){printf("\nStudent successfuly added to database.\n");
				print_Modal("Do you want to continue to Enrollment? [y/n]", 2);menu_Choice = getch();
					if(menu_Choice == 'y'){continue_Choice('2');}
				}else{call_Error(1);}
		}else{printf("\nStudent not added to database.");continue_Choice('0');;}}
	
	fclose(fpointer);
	fflush(fpointer);
	system("pause");
	return;
}






// no error checking come back to this
void menu_Enrollment(){
	clear_Screen();
	print_Modal("Enrollment ", 1);
	
	char search_Student_Id[12];
	int bolis_Found = 0;
	char menu_Choice;
	char strands[][10] = {"STEM", "HUMSS", "ABM", "GAS"};
	char semester[3] = {'X', 'A', 'B'};
	
	if(choice != '2' && choice != '2'){
		print_Modal("Enter the ID of Student: ", 2);gets(search_Student_Id);
	}else{strcpy(search_Student_Id, stu.per.id);};

	FILE *fpointer;
	fpointer = fopen("record.txt", "rb+");
	while(fread(&stu, sizeof(stu), 1, fpointer) == 1){
		if(strcmp(search_Student_Id, stu.per.id) == 0){
			bolis_Found = 1;break;}}
	
	if(bolis_Found == 1){
		print_Modal("Student Name:", 2);printf("%s, %s %s\n", stu.per.last_Name, stu.per.first_Name, stu.per.middle_Name);
		print_Modal("Address: ", 2);printf("%s\n", stu.per.address);
		print_Modal("Birthdate: ", 2);printf("%s\n", stu.per.birthdate);
		print_Modal("Age: ", 2);printf("%i\n", stu.per.age);
		if(stu.flg.isEnrolled == 1){
			print_Modal("STRAND:", 2);printf("%s\n", strands[stu.enr.strand]);
			print_Modal("SEMESTER:", 2);printf("%c\n", semester[stu.enr.semester]);
			print_Modal("YEAR:" , 2);printf("%i\n", stu.enr.yearlvl);
			print_Modal("SECTION: ", 2);printf("%i\n", stu.enr.section);
			call_Error(6);
			continue_Choice('0');
		}else{
			print_Modal("Enter strand: [0 = STEM / 1 = HUMSS / 2 = ABM / 3 = GAS]:", 2);scanf("%i", &stu.enr.strand);
			print_Modal("Enter year level: [11 / 12]",2);scanf("%i", &stu.enr.yearlvl);
			print_Modal("Enter semester: [1 / 2]",2);scanf("%i", &stu.enr.semester);
			print_Modal("Enter Section: [1 / 2]",2);scanf("%i", &stu.enr.section);getchar(); 
			
			
			print_Modal("Has Birth Certificate? [y/n]",2);stu.doc.has_BirthCertificate = getche();printf("\n");
			print_Modal("Has Marriage Certificate? [y/n]",2);stu.doc.has_Diploma = getche();printf("\n");
			print_Modal("Has Diploma? [y/n]",2);stu.doc.has_Diploma= getche();printf("\n");
			print_Modal("Has Form 137? [y/n]",2);stu.doc.has_Form137 = getche();printf("\n");
			
			print_Modal("Do you want to enroll now? [y/n]",2);menu_Choice = getche();
			if(menu_Choice == 'y'){
				continue_Choice('3');
				stu.pay.outstandingbal = 26731;
				stu.flg.isEnrolled = 1;
				fseek(fpointer, -sizeof(stu), SEEK_CUR);
				fwrite(&stu, sizeof(stu), 1, fpointer);
				printf("\nStudent enrolled successfully");
				//SOMETHING WAS HERE
			}else{printf("\nStudent not enrolled.");continue_Choice('0');}}
	}else{printf("No records found!");continue_Choice('0');}
	
	fclose(fpointer);
	fflush(fpointer);
	pause();
	return;
}





void menu_Payment(){
	clear_Screen();
	print_Modal("Payment",1);
	
	char search_Student_Id[12];
	int bolis_Found = 0;
	char menu_Choice = 0;
	float receiveAmnt;
	char strands[][10] = {"STEM", "HUMSS", "ABM", "GAS"};
	char semester[3] = {'X', 'A', 'B'};
	
	if(choice != '3' ){
		printf("Enter the ID of Student: ");gets(search_Student_Id);
	}else{strcpy(search_Student_Id, stu.per.id);}; // hindi na ata to kelangan 
	
	FILE *fpointer;
	fpointer = fopen("record.txt", "rb+");
	while(fread(&stu, sizeof(stu), 1, fpointer) == 1){
		if(strcmp(search_Student_Id, stu.per.id) == 0){
			bolis_Found = 1;break;}}
	
	if(bolis_Found == 1){
		print_Modal("Student Name:  ", 2);printf("%s, %s %s\n", stu.per.last_Name, stu.per.first_Name, stu.per.middle_Name);
		print_Modal("Address: ", 2);printf("%s\n", stu.per.address);
		print_Modal("Birthdate: ", 2);printf("%s\n", stu.per.birthdate);
		print_Modal("Age: ", 2);printf("%i\n", stu.per.age);
		print_Modal("STRAND:", 2);printf("%s\n", strands[stu.enr.strand] );
		print_Modal("SEMESTER:", 2);printf("%c\n", semester[stu.enr.semester]);
		print_Modal("YEAR:", 2);printf("%i\n", stu.enr.yearlvl);
		print_Modal("SECTION: ", 2);printf("%i\n", stu.enr.section);
		printf("\n*Miscellaneous Fees*\nLearning Management Fee             = PHP 850\nMedical Services Fee                = PHP 557\nRegistration Fee                    = PHP 749\nGuidance and Counseling Fee         = PHP 642\nManangement Information System Fee  = PHP 1,079\nLibrary Fee                         = PHP 350\n*Tuition Fee*\nLaboratory Fee                      = PHP 3,342\nSemester Fee (Gened)                = PHP 11,323\nSemester Fee (Specialized)          = PHP 7,839");
		printf("\n\nGRAND TOTAL = PHP 26,731\n");
		print_Modal("Outstanding Balance: ", 2);
		printf("%.2f\n", stu.pay.outstandingbal);
		print_Modal("Receive Amount:  ", 2);scanf("%f", &receiveAmnt);getchar(); // debounce  (also in line 127)
		print_Modal("Change: ", 2);
		if(receiveAmnt > stu.pay.outstandingbal){
			printf("%.2f\n", receiveAmnt-stu.pay.outstandingbal);
			stu.pay.outstandingbal = 0;
		}else{
			printf("No change [%.2f Credited to account]\n", receiveAmnt);
			stu.pay.outstandingbal -= receiveAmnt;
			print_Modal("Outstanding Balance: ", 2);
			printf("%.2f", stu.pay.outstandingbal);}
			fseek(fpointer, -sizeof(stu), SEEK_CUR);
			fwrite(&stu, sizeof(stu), 1, fpointer);
	}else{printf("No records found!");}
	
	fclose(fpointer);
	fflush(fpointer);
	continue_Choice('0');
	pause();
	return;
}

void print_Registration_Card() {
    FILE *fptr;
    fptr = fopen("registration_card.txt", "w");

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fptr, "Registration Card\n");
    fprintf(fptr, "Student ID: %s\n", stu.per.id);
    fprintf(fptr, "Name: %s %s %s\n", stu.per.first_Name, stu.per.middle_Name, stu.per.last_Name);
    fprintf(fptr, "Address: %s\n", stu.per.address);
    fprintf(fptr, "Birthdate: %s\n", stu.per.birthdate);
    fprintf(fptr, "Age: %d\n", stu.per.age);
    fprintf(fptr, "Gender: %s\n", stu.per.gender);
    fprintf(fptr, "Phone Number: %s\n", stu.per.phone_Number);
    fprintf(fptr, "Email Address: %s\n", stu.per.email_Address);
    fprintf(fptr, "Mother's Name: %s %s %s\n", stu.per.mother_First_Name, stu.per.mother_Middle_Name, stu.per.mother_Last_Name);
    fprintf(fptr, "Mother's Occupation: %s\n", stu.per.mother_Occupation);
    fprintf(fptr, "Father's Name: %s %s %s\n", stu.per.father_First_Name, stu.per.father_Middle_Name, stu.per.father_Last_Name);
    fprintf(fptr, "Father's Occupation: %s\n", stu.per.father_Occupation);
    fprintf(fptr, "Guardian's Phone Number: %s\n", stu.per.guardian_Number);
    fprintf(fptr, "STRAND: %d\n", stu.enr.strand);
    fprintf(fptr, "Year Level: %d\n", stu.enr.yearlvl);
    fprintf(fptr, "Semester: %d\n", stu.enr.semester);
    fprintf(fptr, "Section: %d\n", stu.enr.section);
    fprintf(fptr, "Outstanding Balance: %.2f\n", stu.pay.outstandingbal);

    fclose(fptr);
    printf("Registration card saved to registration_card.txt\n");
    return;
}


void debug_menu_Search(){
	clear_Screen();
	char student_Id[12];
	int bolis_Found = 0;
	printf("Enter the ID of student: ");
	gets(student_Id);
	
	FILE *fpointer;
	fpointer = fopen("record.txt", "rb");
	while(fread(&stu,sizeof(stu),1,fpointer) == 1){
		if(strcmp(student_Id, stu.per.id) == 0 ){
			bolis_Found = 1;
			break;
		}
	}
	
	if(bolis_Found == 1){
		printf("\nThe student is found!");
		printf("\nID: %s", stu.per.id);
		printf("\nName; %s", stu.per.first_Name);
		printf("\nSTRAND: %c", stu.enr.strand);
		printf("\nSEMESTER: %c", stu.enr.semester);
		printf("\nYEAR: %c", stu.enr.yearlvl);
		printf("\nSECTION: %c", stu.enr.section);
			getch();
	}else{
		printf("No records found!");
		getch();
	}
	

	
	
	fclose(fpointer);
	return;
}

void debug_Flex(){
	clear_Screen();
			printf("\n*Miscellaneous Fees*\nLearning Management Fee             = PHP 850\nMedical Services Fee                = PHP 557\nRegistration Fee                    = PHP 749\nGuidance and Counseling Fee         = PHP 642\nManangement Information System Fee  = PHP 1,079\nLibrary Fee                         = PHP 350\n*Tuition Fee*\nLaboratory Fee                      = PHP 3,342\nSemester Fee (Gened)                = PHP 11,323\nSemester Fee (Specialized)          = PHP 7,839");
	printf("\n\nGRAND TOTAL = PHP 26,731");
	
		system("pause");
		return;
}
void display_All_Students() {
    clear_Screen();
    printf("All Students in the Database:\n\n");
	char strands[][10] = {"STEM", "HUMSS", "ABM", "GAS"};
	char semester[3] = {'X', 'A', 'B'};
    FILE *fpointer;
    fpointer = fopen("record.txt", "rb");
    if (fpointer == NULL) {
        printf("Error!\n");
        return;
    }

    while (fread(&stu, sizeof(stu), 1, fpointer) == 1) {
        printf("\nStudent ID: %s\n", stu.per.id);
        printf("\nName: %s %s %s\n", stu.per.first_Name, stu.per.middle_Name, stu.per.last_Name);
        printf("\nYear Level: %i\n", stu.enr.yearlvl);
        printf("\nSTRAND: %s\n", strands[stu.enr.strand]);
        printf("\nSection: %d\n\n", stu.enr.section);
    }
    fclose(fpointer);
    fflush(fpointer);
    pause();
    return;
}

void display_All_Students_Per_Section_Per_Year() {
    clear_Screen();
    char strands[][10] = {"STEM", "HUMSS", "ABM", "GAS"};
	char semester[3] = {'X', 'A', 'B'};
    printf("All Students Per Section Per Year Level:\n\n");

    FILE *fpointer;
    fpointer = fopen("record.txt", "rb");
    if (fpointer == NULL) {
        printf("Error!\n");
        return;
    }

    for (int year = 11; year <= 12; year++) {
        printf("\nYear Level: %d\n", year);
        for (int section = 1; section <= 2; section++) {
            printf("\nSection %d:\n", section);
            rewind(fpointer); 
            while (fread(&stu, sizeof(stu), 1, fpointer) == 1) {
                if (stu.enr.yearlvl == year && stu.enr.section == section) {
                    printf("\nStudent ID: %s\n", stu.per.id);
                    printf("\nName: %s %s %s\n", stu.per.first_Name, stu.per.middle_Name, stu.per.last_Name);
                    printf("\nSTRAND: %s\n", strands[stu.enr.strand]);
                    printf("\n");
                }
            }
        }
    }

    fclose(fpointer);
    fflush(fpointer);
    pause();
    return;
}

int main(){
	do{
		if(choice != '2' && choice != '3'){
			clear_Screen();
			print_Modal("Student Record System", 1);
			printf("\n\t\t\t\t\tA.Registration");
			printf("\n\t\t\t\t\tB.Enrollment");
			printf("\n\t\t\t\t\tC.Payment");
			printf("\n\t\t\t\t\tD.Reports");
			printf("\n\t\t\t\t\tE.Exit\n");
			print_Modal("Enter your choice: ", 2);choice = getche();
		}

		switch (choice){
		case 'a':
		case 'A':
			menu_Registration();
			break;
		case 'b':
		case 'B':
		case '2':
			menu_Enrollment();
			break;
		case 'c':
		case 'C':
		case '3':
			menu_Payment();
			print_Registration_Card();
			break;
	case 'd':
            case 'D':
                clear_Screen();
                printf("Reports:\n\n");
                printf("[1.] Display all students in the database\n");
                printf("[2.] Display all students per section per year level\n");
                printf("\nEnter your choice: ");
                choice = getche();

                switch (choice) {
                    case '1':
                        display_All_Students();
                        break;
                    case '2':
                        display_All_Students_Per_Section_Per_Year();
                        break;
                    default:
                        printf("\nInvalid option for reports.\n");
                        break;
                }
                continue_Choice('0');
				break;
				
		case 'e':
		case 'E':
			return 0;
			break;
			
		case 'x': //debug
		case 'X':
			debug_menu_Search();
			break;
		case 'y': //debug
		case 'Y':
			debug_Flex();
			break;
		default: 
			printf("Invalid option");
			break;
		}
	}while(choice != 'e' );
	return 0;
}
