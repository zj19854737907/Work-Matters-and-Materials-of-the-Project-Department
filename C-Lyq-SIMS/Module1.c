#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_MAJOR_LENGTH 100
#define INITIAL_CAPACITY 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char gender[10];
    char major[MAX_MAJOR_LENGTH];
} Student;

typedef struct {
    Student *students;
    int size;
    int capacity;
} StudentList;

void initializeStudentList(StudentList *list) {
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    list->students = (Student *)malloc(list->capacity * sizeof(Student));
    if (list->students == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
}

void addStudent(StudentList *list, const char *name, int age, const char *gender, const char *major) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->students = (Student *)realloc(list->students, list->capacity * sizeof(Student));
        if (list->students == NULL) {
            perror("Failed to reallocate memory");
            exit(EXIT_FAILURE);
        }
    }
    strncpy(list->students[list->size].name, name, MAX_NAME_LENGTH - 1);
    list->students[list->size].name[MAX_NAME_LENGTH - 1] = '\0';
    list->students[list->size].age = age;
    strncpy(list->students[list->size].gender, gender, 9);
    list->students[list->size].gender[9] = '\0';
    strncpy(list->students[list->size].major, major, MAX_MAJOR_LENGTH - 1);
    list->students[list->size].major[MAX_MAJOR_LENGTH - 1] = '\0';
    list->size++;
}

void printStudents(const StudentList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("Name: %s, Age: %d, Gender: %s, Major: %s\n", list->students[i].name, list->students[i].age, list->students[i].gender, list->students[i].major);
    }
}

void freeStudentList(StudentList *list) {
    free(list->students);
}

int main() {
    StudentList studentList;
    initializeStudentList(&studentList);

    char name[MAX_NAME_LENGTH];
    int age;
    char gender[10];
    char major[MAX_MAJOR_LENGTH];
    char choice;

    do {
        printf("Enter student's name: ");
        scanf("%49s", name); // Read up to 49 characters to leave space for null terminator
        printf("Enter student's age: ");
        scanf("%d", &age);
        printf("Enter student's gender: ");
        scanf("%9s", gender); // Read up to 9 characters to leave space for null terminator
        printf("Enter student's major: ");
        scanf("%99s", major); // Read up to 99 characters to leave space for null terminator

        addStudent(&studentList, name, age, gender, major);

        printf("Do you want to add another student? (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to consume any leftover newline character
    } while (choice == 'y' || choice == 'Y');

    printf("\nCurrent students in the list:\n");
    printStudents(&studentList);

    freeStudentList(&studentList);
    return 0;
}
