#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "validation.h"

void AddStudent()
{
    struct Student newStudent;

    newStudent.roll = GetValidRollNumber();
    ClearInputBuffer();
    GetValidName(newStudent.name);
    newStudent.marks = GetValidMarks();

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

    while (fscanf(fp, "%d %s %f", &student.roll, student.name, &student.marks) == 3)
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
    while (fscanf(fp, "%d %s %f", &student.roll, student.name, &student.marks) == 3)
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
void EditStudent()
{
    struct Student student;
    int rollToEdit;

    printf("Enter Roll Number to edit: ");
    scanf("%d", &rollToEdit);

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
    while (fscanf(fp, "%d %s %f", &student.roll, student.name, &student.marks) == 3)
    {
        if (student.roll == rollToEdit)
        {
            found = 1;
            printf("Enter new Name: ");
            scanf("%s", student.name);
            printf("Enter new Marks: ");
            scanf("%f", &student.marks);
        }
        fprintf(tempFp, "%d %s %.2f\n", student.roll, student.name, student.marks);
    }

    fclose(fp);
    fclose(tempFp);

    if (found)
    {
        remove("students.txt");
        rename("temp.txt", "students.txt");
        printf("Student edited successfully!\n");
    }
    else
    {
        remove("temp.txt"); // Clean up temp file if no edit occurred
        printf("Student not found!\n");
    }
}
void ShowStatistics()
{
    struct Student student;
    FILE *fp = fopen("students.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    int totalStudents = 0;
    float totalMarks = 0.0;
    float highestMarks = 0.0;
    float lowestMarks = 100.0;

    while (fscanf(fp, "%d %s %f", &student.roll, student.name, &student.marks) == 3)
    {
        totalStudents++;

        totalMarks += student.marks;

        if (student.marks > highestMarks)
            highestMarks = student.marks;

        if (student.marks < lowestMarks)
            lowestMarks = student.marks;
    }

    fclose(fp);

    if (totalStudents == 0)
    {
        printf("No students found!\n");
        return;
    }

    float averageMarks = totalMarks / totalStudents;

    printf("===============================================\n");
    printf("\tStudent Statistics \n");
    printf("===============================================\n");
    printf("Total Students: %d\n", totalStudents);
    printf("Average Marks: %.2f\n", averageMarks);
    printf("Highest Marks: %.2f\n", highestMarks);
    printf("Lowest Marks: %.2f\n", lowestMarks);
}
void SearchStudentByName()
{
    struct Student student;
    char nameToSearch[NAME_SIZE];

    ClearInputBuffer(); // Clear the input buffer before reading the name
    GetValidName(nameToSearch);

    FILE *fp = fopen("students.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    int found = 0;
    while (fscanf(fp, "%d %s %f", &student.roll, student.name, &student.marks) == 3)
    {
        if (strcmp(student.name, nameToSearch) == 0)
        {
            printf("======Student found!======\n");
            printf("Roll: %d\n", student.roll);
            printf("Name: %s\n", student.name);
            printf("Marks: %.2f\n", student.marks);
            printf("==========================\n");
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
