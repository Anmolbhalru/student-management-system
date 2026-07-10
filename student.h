#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    int roll;
    char name[50];
    float marks;
};

void AddStudent();
void DisplayStudent();
void SearchStudent();
void DeleteStudent();
void EditStudent();

#endif // STUDENT_H