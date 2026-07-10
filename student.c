#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void AddStudent()
{
    struct Student newStudent;

    printf("Enter Roll Number: ");
    scanf("%d", &newStudent.roll);

    printf("Enter Name: ");
    scanf("%s", newStudent.name);

    printf("Enter Marks: ");
    scanf("%f", &newStudent.marks);

    FILE *fp = fopen("students.txt", "a");

    if (fp == NULL)
    {
        printf("Error opening fp!\n");
        return;
    }
    fprintf(fp, "%d %s %.2f\n", newStudent.roll, newStudent.name, newStudent.marks);

    fclose(fp);
    printf("Student added successfully!\n");
}
void DisplayStudent()
{
    FILE *fp = fopen("students.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    struct Student student;
    printf("Roll\tName\t\tMarks\n");
    printf("-----\t----\t\t-----\n");

    while (fscanf(fp, "%d %s %f", &student.roll, student.name, &student.marks) != EOF)
    {
        printf("%d\t%s\t\t%.2f\n", student.roll, student.name, student.marks);
    }

    fclose(fp);
}

void SearchStudent()
{

    struct Student student;
    int rollToSearch;

    printf("Enter Roll Number to search: ");
    scanf("%d", &rollToSearch);

    FILE *fp = fopen("students.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    int found = 0;
    while (fscanf(fp, "%d %s %f", &student.roll, student.name, &student.marks) != EOF)
    {
        if (student.roll == rollToSearch)
        {
            printf("Student found!\n");
            printf("Roll: %d\n", student.roll);
            printf("Name: %s\n", student.name);
            printf("Marks: %.2f\n", student.marks);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student not found!\n");
    }

    fclose(fp);
}

void DeleteStudent()
{
    struct Student student;
    int rollToDelete;

    printf("Enter Roll Number to delete: ");
    scanf("%d", &rollToDelete);

    FILE *fp = fopen("students.txt", "r");
    FILE *tempFp = fopen("temp.txt", "w");

    if (fp == NULL || tempFp == NULL)
{
    printf("Error opening file!\n");

    if (fp != NULL)
        fclose(fp);

    if (tempFp != NULL)
        fclose(tempFp);

    return;
}
    int found = 0;
    while (fscanf(fp, "%d %s %f", &student.roll, student.name, &student.marks) ==3)
    {
        if (student.roll == rollToDelete)
        {
            found = 1;
            continue; // Skip writing this student to the temp file
        }
        fprintf(tempFp, "%d %s %.2f\n", student.roll, student.name, student.marks);
    }

    fclose(fp);
    fclose(tempFp);

    if (found)
    {
        remove("students.txt");
        rename("temp.txt", "students.txt");
        printf("Student deleted successfully!\n");
    }
    else
    {
        remove("temp.txt"); // Clean up temp file if no deletion occurred
        printf("Student not found!\n");
    }
}