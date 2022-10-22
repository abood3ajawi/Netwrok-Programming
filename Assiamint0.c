#include <stdio.h>
#include <string.h>
 struct information {
    char courseName[100];
    char code[100];
    int credit;
    int grade;
    }info[4];

void readFile(){
    char const* const fileName = "/home/abood/CProjects/untitled/input.txt";
    FILE* file = fopen(fileName, "r");
    if(!file){
        printf("\n Unable to open : %s ", fileName);
        return ;
    }
    char line[500];
    int index = 0;
    int toggle = 1;
    while (fgets(line, sizeof(line), file)) {
        for (int i = 0; i < sizeof(line); ++i) {
            if(line[i] == ','){
                toggle++;
                continue;
            }
            if(toggle == 1){
                strncat(info[index].courseName,&line[i],1);
            }
            else if(toggle == 2){
                strncat(info[index].code,&line[i],1);

            }
            else if(toggle == 3){
                info[index].credit =(int)line[i]-48;
            }
            else if(toggle == 4){
                int firstNumber = (int)line[i]-48;
                int secondNumber = (int)line[i+1]-48;

                info[index].grade =(firstNumber*10)+secondNumber;
                break;
            }
        }
        index++;
        toggle=1;
    }
    fclose(file);
}
void  displayCoursesInformation() {
    for (int i = 0; i < 4; ++i) {
        printf("Name   :  %s\n", info[i].courseName);
        printf("Code   :  %s\n", info[i].code);
        printf("credit : %i\n", info[i].credit);
        printf("--------\n");
    }
}
void displayGPA(){
    int GPA = 0;
    for (int i = 0; i < 4; ++i) {
        GPA = GPA + info[i].grade/4;
    }
    printf("GPA : %i\n",GPA);
}

void displayHighestGradeCourse(){
    int highestGPA = info[0].grade;
    for (int i = 1; i < 4; ++i) {
        if(highestGPA<info[i].grade)
            highestGPA = info[i].grade;
    }
    printf("highest GPA : %i\n",highestGPA);
}
void displayLowestGradeCourse(){
    int lowestGPA = info[0].grade;
    for (int i = 1; i < 4; ++i) {
        if(lowestGPA>info[i].grade)
            lowestGPA = info[i].grade;
    }
    printf("lowest GPA : %i\n",lowestGPA);
}
void displayCode(){
    int credit;
    printf("Enter an credit: ");
    scanf("%d", &credit);
    for (int i = 0; i < 4; ++i) {
        if(info[i].credit == credit)
            printf("%s\n",info[i].code);
    }
}
void displayCourseInformation(){
    char code[30];
    printf("Enter an code: ");
    scanf(" %[^\n]s",&code);
    for (int i = 0; i < 4; ++i) {
        if(strcmp(code,info[i].code)==0) {
            printf("Name   :  %s\n", info[i].courseName);
            printf("Credit : %i\n", info[i].credit);
            printf("Grade : %i\n", info[i].grade);
            printf("--------\n");
        }
    }
}
void GradeLetterFormat(int grade ){
    if(grade >= 95){
        printf("A+\n");
    }
    else if(grade>=85){
        printf("A\n");
    }
    else if(grade>=80){
        printf("A-\n");

    }
    else if(grade>=78){
        printf("B+\n");

    }
    else if(grade>=74){
        printf("B\n");

    }
    else if( grade>=70){
        printf("B-\n");

    }
    else if( grade>=67){
        printf("C+\n");

    }
    else if(grade>=64){
        printf("C\n");

    }
    else if(grade>=60){
        printf("C-\n");

    }
    else if( grade>=57){
        printf("D+\n");

    }
    else if( grade>=54){
        printf("D\n");

    }
    else if(grade>=50){
        printf("D-\n");
    }
    else{
        printf("F\n");
    }
}
void displayGradeLetter(){
    char code[20];
    printf("Enter an code: ");
    scanf(" %[^\n]s",&code);
    for (int i = 0; i < 4; ++i) {
        if(strcmp(code,info[i].code)==0) {
            printf("Name   :  %s\n", info[i].courseName);
            printf("credit : %i\n", info[i].credit);
            GradeLetterFormat(info[i].grade);
            printf("--------\n");
        }
    }
}
void start(){
    int choose;
    while (1) {
        printf("1. Display all courses information\n"
               "2. Compute GPA of all courses\n"
               "3. Display highest grade and the corresponding course name\n"
               "4. Display lowest grade and the corresponding course name\n"
               "5. Display course(s) code(s) whose credit hours are based on your input\n"
               "6. Display course information for given course code\n"
               "7. Display the grade as letter format for given course code(ex: 85 is B)\n"
               "8. Exit\n");
        printf("Enter number from the list : ");
        scanf("%d", &choose);
        if(choose == 1)
            displayCoursesInformation();
        else if(choose == 2)
            displayGPA();
        else if(choose == 3)
            displayHighestGradeCourse();
        else if(choose == 4)
            displayLowestGradeCourse();
        else if(choose == 5)
            displayCode();
        else if(choose == 6)
            displayCourseInformation();
        else if(choose == 7)
            displayGradeLetter();
        else if(choose == 8)
            return;
    }
}
int main() {
    readFile();
    start();
    return 0;
}
