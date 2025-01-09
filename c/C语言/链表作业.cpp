#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int studentID;
    char name[50];
    int age;
    struct Student* next;
};

struct Student* createStudent(int id, char *studentName, int studentAge) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->studentID = id;
    strcpy(newStudent->name, studentName);
    newStudent->age = studentAge;
    newStudent->next = NULL;
    return newStudent;
}

void insertNode(struct Student* head, int position, struct Student* newStudent) {
    struct Student* temp = head;
    int i = 1;
    while (i < position && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    newStudent->next = temp->next;
    temp->next = newStudent;
}

// 删除节点
void deleteNode(struct Student* head, int id) {
    struct Student* temp = head;
    struct Student* prev = NULL;
    while (temp != NULL && temp->studentID != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Student not found\n");
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// 遍历链表
void traverseList(struct Student* head) {
    struct Student* temp = head;
    while (temp != NULL) {
        printf("Student ID: %d, Name: %s, Age: %d\n", temp->studentID, temp->name, temp->age);
        temp = temp->next;
    }
}

int main() {
    struct Student* head = createStudent(1, "Alice", 20);
    insertNode(head, 1, createStudent(2, "Bob", 22));
    insertNode(head, 2, createStudent(3, "Charlie", 19));
    insertNode(head, 3, createStudent(4, "David", 21));

    printf("Original List:\n");
    traverseList(head);

    insertNode(head, 2, createStudent(5, "Eva", 23));
    printf("\nList after inserting a new student:\n");
    traverseList(head);

    deleteNode(head, 3);
    printf("\nList after deleting a student:\n");
    traverseList(head);

    return 0;
}

