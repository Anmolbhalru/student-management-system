#ifndef STUDENT_H
#define STUDENT_H
#define NAME_SIZE 50

struct Student {
    int roll;
    char name[NAME_SIZE];
    float marks;
};

void AddStudent();
void DisplayStudent();
void SearchStudent();
void DeleteStudent();
void EditStudent();
int RollNumberExists(int roll);


#endif // STUDENT_H