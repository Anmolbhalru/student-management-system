#ifndef SORT_H
#define SORT_H

int ReadStudentsFromFile(struct Student students[], int maxStudents);
void DisplayStudentsArray(struct Student students[], int count);
void BubbleSort(struct Student students[], int count, int sortBy);
void SortStudents(void);



#endif // SORT_H