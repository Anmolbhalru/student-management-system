#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void Menu()
{
    printf("===== Student Management System =====\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Search Student\n");
    printf("4. Delete Student\n");
    printf("5. Exit\n");
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
            printf("Exiting...\n");
            exit(0);
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}