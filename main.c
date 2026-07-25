#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Student
{
    int id;
    char name[50];
    int age;
    char department[30];
    float marks;
};

struct Student students[MAX];
int count = 0;

void loadStudents();
void saveStudents();
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

void loadStudents()
{
    FILE *fp = fopen("students.txt", "r");

    if(fp == NULL)
        return;

    count = 0;

    while(fscanf(fp,"%d %49s %d %29s %f",
                 &students[count].id,
                 students[count].name,
                 &students[count].age,
                 students[count].department,
                 &students[count].marks)==5)
    {
        count++;
    }

    fclose(fp);
}

void saveStudents()
{
    FILE *fp = fopen("students.txt","w");

    if(fp==NULL)
    {
        printf("Unable to save file!\n");
        return;
    }

    for(int i=0;i<count;i++)
    {
        fprintf(fp,"%d %s %d %s %.2f\n",
                students[i].id,
                students[i].name,
                students[i].age,
                students[i].department,
                students[i].marks);
    }

    fclose(fp);
}

void addStudent()
{
    printf("\nEnter Student ID : ");
    scanf("%d",&students[count].id);

    printf("Enter Name : ");
    scanf("%s",students[count].name);

    printf("Enter Age : ");
    scanf("%d",&students[count].age);

    printf("Enter Department : ");
    scanf("%s",students[count].department);

    printf("Enter Marks : ");
    scanf("%f",&students[count].marks);

    count++;

    saveStudents();

    printf("\nStudent Added Successfully!\n");
}

void displayStudents()
{
    if(count==0)
    {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\n-----------------------------------------------------------\n");
    printf("ID\tName\t\tAge\tDepartment\tMarks\n");
    printf("-----------------------------------------------------------\n");

    for(int i=0;i<count;i++)
    {
        printf("%d\t%s\t\t%d\t%s\t\t%.2f\n",
                students[i].id,
                students[i].name,
                students[i].age,
                students[i].department,
                students[i].marks);
    }
}
void searchStudent()
{
    int id, found = 0;

    printf("\nEnter Student ID to Search: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(students[i].id == id)
        {
            printf("\nStudent Found!\n");
            printf("-----------------------------\n");
            printf("ID         : %d\n", students[i].id);
            printf("Name       : %s\n", students[i].name);
            printf("Age        : %d\n", students[i].age);
            printf("Department : %s\n", students[i].department);
            printf("Marks      : %.2f\n", students[i].marks);

            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("\nStudent Not Found!\n");
}

void updateStudent()
{
    int id, found = 0;

    printf("\nEnter Student ID to Update: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(students[i].id == id)
        {
            printf("Enter New Name: ");
            scanf("%s", students[i].name);

            printf("Enter New Age: ");
            scanf("%d", &students[i].age);

            printf("Enter New Department: ");
            scanf("%s", students[i].department);

            printf("Enter New Marks: ");
            scanf("%f", &students[i].marks);

            saveStudents();

            printf("\nStudent Updated Successfully!\n");

            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("\nStudent Not Found!\n");
}

void deleteStudent()
{
    int id, found = 0;

    printf("\nEnter Student ID to Delete: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(students[i].id == id)
        {
            for(int j = i; j < count - 1; j++)
            {
                students[j] = students[j + 1];
            }

            count--;

            saveStudents();

            printf("\nStudent Deleted Successfully!\n");

            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("\nStudent Not Found!\n");
}

int main()
{
    int choice;

    loadStudents();

    while(1)
    {
        printf("\n=====================================\n");
        printf("      STUDENT MANAGEMENT SYSTEM\n");
        printf("=====================================\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("\nThank You! Data Saved Successfully.\n");
                exit(0);

            default:
                printf("\nInvalid Choice! Please Try Again.\n");
        }
    }

    return 0;
}