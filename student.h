#ifndef STUDENT_H
#define STUDENT_H
#define NAME_SIZE 50
#define MAX_STUDENTS 100
#define STUDENT_FILE "students.txt"


#define SORT_BY_ROLL  1
#define SORT_BY_NAME  2
#define SORT_BY_MARKS 3

struct Student {
    int roll;
    char name[NAME_SIZE];
    float marks;
};

void AddStudent();
void DisplayStudent();
void SearchStudent();
void DeleteStudent();
void ShowStatistics();
void SearchStudentByName(); 
void EditStudent();
int RollNumberExists(int roll);


#endif // STUDENT_H