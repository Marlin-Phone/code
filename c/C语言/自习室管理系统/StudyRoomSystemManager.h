#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//学生信息
typedef struct _Student
{
	int stuNum;
	char name[20];
	int otherdata; //（其它数据）(未使用) 
}Student;

//结点信息
typedef struct _Node
{
	Student student;
	struct _Node* next;
}Node;

void welcome(); //孙少奇 

void inputStudent(Node* head);

void printStudent(Node* head);

void countStudyRoomSeats(Node* head);

void findStudent(Node* head);

void saveStudent(Node* head);

void loadStudent(Node* head);

void modifyStudent(Node* head);

void deleteStudent(Node* head);

void freeSeats(); 
