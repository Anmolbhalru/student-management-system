#include <stdio.h>
#include <string.h>
#include "student.h"
#include "sort.h"

int ReadStudentsFromFile(struct Student students[], int maxStudents)
{
    FILE *fp = fopen(STUDENT_FILE, "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 0;
    }

    int count = 0;
    while (count < maxStudents && fscanf(fp, "%d %s %f", &students[count].roll, students[count].name, &students[count].marks) == 3)
    {
        count++;
    }

    fclose(fp);
    return count;
}

void DisplayStudentsArray(struct Student students[], int count)
{
    printf("Roll\tName\t\tMarks\n");
    printf("-----\t----\t\t-----\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\t%s\t\t%.2f\n", students[i].roll, students[i].name, students[i].marks);
    }
}
void BubbleSort(struct Student students[], int count, int sortBy)
{
    struct Student temp;
    for (int i = 0; i < count - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < count - i - 1; j++)
        {
            int shouldSwap = 0;
            switch (sortBy)
            {
            case SORT_BY_ROLL:
                if (students[j].roll > students[j + 1].roll)
                    shouldSwap = 1;
                break;
            case SORT_BY_NAME:
                if (strcmp(students[j].name, students[j + 1].name) > 0)
                    shouldSwap = 1;
                break;
            case SORT_BY_MARKS:
                if (students[j].marks > students[j + 1].marks)
                    shouldSwap = 1;
                break;
            default:
                printf("Invalid sort option!\n");
                return;
            }

            if (shouldSwap)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
        {
            break; // Exit the inner loop if no s is needed
        }
    }
}
void SortStudents(void)
{
    struct Student studentArray[MAX_STUDENTS];
    int studentCount = 0;
    int sortChoice = 0;

    // Read students from file
    studentCount = ReadStudentsFromFile(studentArray, MAX_STUDENTS);
    
    if (studentCount == 0)
    {
        printf("No students found in file!\n");
        return;
    }

    // Display sort options menu
    printf("\n===== SORT OPTIONS =====\n");
    printf("1. Sort by Roll Number\n");
    printf("2. Sort by Name\n");
    printf("3. Sort by Marks\n");
    printf("========================\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &sortChoice);

    // Validate user input
    if (sortChoice < SORT_BY_ROLL || sortChoice > SORT_BY_MARKS)
    {
        printf("Invalid choice! Please enter 1, 2, or 3.\n");
        return;
    }

    // Sort the students based on user choice
    BubbleSort(studentArray, studentCount, sortChoice);

    // Display sorted results
    printf("\n===== SORTED STUDENTS =====\n");
    DisplayStudentsArray(studentArray, studentCount);
}