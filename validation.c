#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validation.h"
#include "student.h"
#define NAME_SIZE 50

int GetValidRollNumber()
{
    int roll;
    int exists;
    do
    {
        printf("Enter Roll Number (positive integer): ");
        scanf("%d", &roll);
        
        exists = RollNumberExists(roll);

        if (exists)
        {
            printf("Roll number already exists! Please enter a different roll number.\n");
        }
        else if (roll <= 0)
        {
            printf("Invalid roll number! Please enter a positive integer.\n");
        }
    } while (roll <= 0 || exists);
    return roll;
}
float GetValidMarks()
{
    float marks;
    do
    {
        printf("Enter Marks (0-100): ");
        scanf("%f", &marks);
        if (marks < 0 || marks > 100)
        {
            printf("Invalid marks! Please enter a value between 0 and 100.\n");
        }
    } while (marks < 0 || marks > 100);
    return marks;
}
void ClearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ; // Discard characters until newline or EOF
}
void GetValidName(char name[])
{
    do
    {
        printf("Enter Name: ");
       
        fgets(name, NAME_SIZE, stdin);
        // Remove newline character if present
        name[strcspn(name, "\n")] = '\0';
        if (strlen(name) == 0)
        {
            printf("Name cannot be empty! Please enter a valid name: ");
        }
    } while (strlen(name) == 0);
}
int RollNumberExists(int roll)
{
    struct Student student;
    FILE *fp = fopen("students.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 0; // Return 0 if file cannot be opened
    }

    while (fscanf(fp, "%d %s %f", &student.roll, student.name, &student.marks) == 3)
    {
        if (student.roll == roll)
        {
            fclose(fp);
            return 1; // Roll number exists
        }
    }

    fclose(fp);
    return 0; // Roll number does not exist
}