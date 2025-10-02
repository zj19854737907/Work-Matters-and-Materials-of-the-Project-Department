#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10000
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float score;
} Student;

void displayAll(Student students[], int count);
Student* findStudentByName(Student students[], int count, const char* name);
void printStudentInfo(const Student* student);

int main() {

    displayAll(students, studentCount);

    char searchName[MAX_NAME_LENGTH];
    printf("Enter student name to search: ");
    scanf("%s", searchName);
    Student* foundStudent = findStudentByName(students, studentCount, searchName);
    if (foundStudent != NULL) {
        printStudentInfo(foundStudent);
    } else {
        printf("Student not found.\n");
    }

    return 0;
}

void displayAll(Student students[], int count) {
    printf("All Students Information:\n");
    for (int i = 0; i < count; i++) {
        printStudentInfo(&students[i]);
    }
}

Student* findStudentByName(Student students[], int count, const char* name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return &students[i];
        }
    }
    return NULL;
}
void printStudentInfo(const Student* student) {
    printf("Name: %s, Age: %d, Score: %.2f\n", student->name, student->age, student->score);
}
