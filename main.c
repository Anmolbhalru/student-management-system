#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void Menu()
{
    printf("===============================================\n");
    printf("\tStudent Management System \n");
    printf("===============================================\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Search Student\n");
    printf("4. Delete Student\n");
    printf("5. Edit Student\n");
    printf("6. ShowStatistics\n");
    printf("7. Search Student by Name\n");
    printf("8. Sort Students\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
}
int main()
{

    int choice;

    while (1)
    {
        Menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            AddStudent();
            break;
        case 2:
            DisplayStudent();
            break;
        case 3:
            SearchStudent();
            break;
        case 4:
            DeleteStudent();
            break;
        case 5:
            EditStudent();
            break;
        case 6:
            ShowStatistics();
            break;
        case 7:
            SearchStudentByName();
            break;
        case 8:
            SortStudents();
            break;
        case 9:
            printf("Exiting...\n");
            exit(0);
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}