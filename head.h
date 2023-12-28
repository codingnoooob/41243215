#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int studentID;
    float grade;
} Student;

Student students[MAX_STUDENTS];
int numStudents = 0;

void addStudent();
void displayStudents();
void searchStudent();
void editStudent();
void deleteStudent();
void saveToFile();
void loadFromFile();
