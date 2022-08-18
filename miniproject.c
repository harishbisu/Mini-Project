#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define numberOfCouses 6     // currently only 6 courses for making program practical (for question 5,000)
#define noOfStudents 2     // currently only 2 students for making program practical (for question 100,000)
int roll_No = 1; //base roll no (you can change it)
int registered = 0; //will be used as if students are registered (in simple language it will be used as boolean)
// List of Available Courses(list - 1)(list can be expanded by changing value of courses)
char *courses[numberOfCouses] = {"maths", "english", "hindi", "arts", "Social Science", "Humanities"};
typedef struct node{
    int data;
    struct node *next;
} node;
typedef struct student
{
    char *studentName;
    node *classes;          
    int rollNo;
} student;
node *newNode(int val)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = val;
    new->next = NULL;
    return new;
}
student *list[noOfStudents + 1];
student *newStudent(char *studentName){
    char *studentName2;
    studentName2 = (char *)malloc(30);
    strcpy(studentName2, studentName);
    student *new = (student *)malloc(sizeof(student));
    new->studentName = studentName2;
    new->classes = NULL;
    return new;
}
void listCourses()
{
    printf("List of Courses open for Registration\n");
    for (int i = 0; i < numberOfCouses; i++)
    {
        printf("%d. %s\n", i + 1, courses[i]);
    }
}
//function for starting the Registration
void StartRegistration(student *curr)
{
    listCourses();
    printf("Enter numbers corresponding to your choice of course AND enter 0 and then press Enter to confirm registration\n");
    int i;
    node *classList;
    for (i = 0; i < numberOfCouses;)
    {
        int t;
        scanf("%d", &t);
        if (t > numberOfCouses || t < 0)
        {
            printf("Please Enter a valid choice\n");
            continue;
        }
        if (t == 0 && i == 0)
        {
            printf("You have to choose atleast one course\n");
            continue;
        }
        if (t == 0)
            break;
        node *num = newNode(t - 1);
        if (curr->classes == NULL){
            curr->classes = num;
        }
        else{
            num->next = curr->classes;
            curr->classes = num;
        }
        i++;
    }
}
void startRegistration()
{
    char studentName[30];
    for (int i = 0; i < noOfStudents; i++)
    {
        printf("\nEnter your studentName\t: ");
        scanf("%29s", studentName);
        student *student = newStudent(studentName);
        student->rollNo = i + roll_No;
        StartRegistration(student);
        list[i] = student;
        printf("Registration Successful your rollNo is %d\n", i + roll_No);
    }
    printf("\n\nRegistration Ended\n\n");
    registered = 1;
}
void List2()
{
    if(!registered) {
        printf("Please Register and get your roll_Number first\n");
    }
    printf("\n\nList of Courses for each Student\n\n");
    for (int i = 0; i < noOfStudents; i++)
    {
        student *curr = list[i];
        printf("studentName = %s\nRoll_No = %d\nOpted Course List\n", curr->studentName,curr->rollNo);
        node *temp = curr->classes;
        int i = 1;
        while (temp != NULL)
        {
            printf("%d.%s\n", i++,courses[temp->data]);
            temp = temp->next;
        }
    }
}
void userChoice() {
    int c;
    printf("\nEnter Your Choice \n");
    while (1) {
        printf("1. List opted Course List for a Student.\n");
        printf("2. List All Students with opted Courses.\n");
        printf("3. Quit\n");
        scanf("%d", &c);
        if (c == 1) {
            int rn;
            printf("Enter Your Roll Number\n");
            scanf("%d", &rn);
            if (rn >= 1 && rn <= 1 +noOfStudents ) {
                int idx = rn - 1;
                student *curr = list[idx];
                printf("studentName = %s\n", curr->studentName);
                node *temp = curr->classes;
                while (temp != NULL)
                {
                    printf("%s\n", courses[temp->data]);
                    temp = temp->next;
                }
            }
            else {
                printf("Invalid Roll Number\n");
            }
        }
        else if(c == 2) {
            List2();
        }
        else if (c == 3) {
                return;
            }
        else {
            printf("Invalid Response\n");
            printf("Try Again\n");
        }
    }
}
void main()
{
    listCourses();
    startRegistration();
    List2();
    userChoice();
    printf("Course registration ended\n");
}
