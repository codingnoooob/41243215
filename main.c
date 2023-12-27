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

int main() {
    int choice;

    loadFromFile();

    do {
        printf("\n學生資訊管理系統\n");
        printf("1. 新增學生\n");
        printf("2. 顯示學生資訊\n");
        printf("3. 查詢學生\n");
        printf("4. 編輯學生資訊\n");
        printf("5. 刪除學生\n");
        printf("6. 保存到文件\n");
        printf("0. 保存並退出\n");
        printf("請選擇: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            editStudent();
            break;
        case 5:
            deleteStudent();
            break;
        case 6:
            saveToFile();
            break;
        case 0:
            // 保存到文件並退出
            saveToFile();
            printf("感謝使用學生資訊管理系統！\n");
            break;
        default:
            printf("請輸入有效的選擇。\n");
        }
    } while (choice != 0);

    return 0;
}

void addStudent() {
    if (numStudents < MAX_STUDENTS) {
        printf("\n新增學生\n");
        printf("姓名: ");
        scanf("%s", students[numStudents].name);
        printf("學號: ");
        scanf("%d", &students[numStudents].studentID);
        printf("成績: ");
        scanf("%f", &students[numStudents].grade);

        numStudents++;
        printf("\n學生資訊已新增。\n");
    }
    else {
        printf("\n系統已滿，無法新增更多學生。\n");
    }
}

void displayStudents() {
    if (numStudents > 0) {
        printf("\n學生資訊\n");
        printf("%-15s%-15s%-15s\n", "姓名", "學號", "成績");
        for (int i = 0; i < numStudents; i++) {
            printf("%-15s%-15d%-15.2f\n", students[i].name, students[i].studentID, students[i].grade);
        }
    }
    else {
        printf("\n目前沒有學生資訊。\n");
    }
}

void searchStudent() {
    int searchID;
    printf("\n查詢學生\n");
    printf("請輸入要查詢的學號: ");
    scanf("%d", &searchID);

    printf("%-15s%-15s%-15s\n", "姓名", "學號", "成績");

    for (int i = 0; i < numStudents; i++) {
        if (students[i].studentID == searchID) {
            printf("%-15s%-15d%-15.2f\n", students[i].name, students[i].studentID, students[i].grade);
            return;
        }
    }

    printf("\n找不到學號為 %d 的學生。\n", searchID);
}


void editStudent() {
    int editID;
    printf("\n編輯學生資訊\n");
    printf("請輸入要編輯的學號: ");
    scanf("%d", &editID);

    for (int i = 0; i < numStudents; i++) {
        if (students[i].studentID == editID) {
            printf("請輸入新的資訊：\n");
            printf("姓名: ");
            scanf("%s", students[i].name);
            printf("學號: ");
            scanf("%d", &students[i].studentID);
            printf("成績: ");
            scanf("%f", &students[i].grade);
            printf("學生資訊已更新。\n");
            return;
        }
    }

    printf("\n找不到學號為 %d 的學生。\n", editID);
}

void deleteStudent() {
    int deleteID;
    printf("\n刪除學生\n");
    printf("請輸入要刪除的學號: ");
    scanf("%d", &deleteID);

    for (int i = 0; i < numStudents; i++) {
        if (students[i].studentID == deleteID) {
            // 將要刪除的學生資訊後的內容整體往前移動
            for (int j = i; j < numStudents - 1; j++) {
                students[j] = students[j + 1];
            }

            numStudents--;
            printf("學生資訊已刪除。\n");
            return;
        }
    }

    printf("\n找不到學號為 %d 的學生。\n", deleteID);
}

void saveToFile() {
    FILE *file = fopen("students.txt", "w");

    if (file != NULL) {
        for (int i = 0; i < numStudents; i++) {
            fprintf(file, "%s %d %.2f\n", students[i].name, students[i].studentID, students[i].grade);
        }

        fclose(file);
        printf("學生資訊已保存到文件。\n");
    }
    else {
        printf("無法打開文件。\n");
    }
}

void loadFromFile() {
    FILE *file = fopen("students.txt", "r");

    if (file != NULL) {
        while (fscanf(file, "%s %d %f", students[numStudents].name, &students[numStudents].studentID, &students[numStudents].grade) == 3) {
            numStudents++;
            if (numStudents >= MAX_STUDENTS) {
                printf("文件中的學生數量超出系統容量。\n");
                break;
            }
        }

        fclose(file);
        printf("已載入學生資訊。\n");
    }
}
