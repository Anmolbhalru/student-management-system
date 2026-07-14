#ifndef VALIDATION_H
#define VALIDATION_H 
#define NAME_SIZE 50   

int GetValidRollNumber();
float GetValidMarks();
void GetValidName(char name[]);
int RollNumberExists(int roll);
void ClearInputBuffer();

#endif // VALIDATION_H