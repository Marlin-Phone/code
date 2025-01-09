#include "StudyRoomSystemManager.h"

int main() {
	//创建头结点
	Node* head = malloc(sizeof(Node));
	head->next = NULL;
	loadStudent(head);

	while (1) {

		welcome();

		char c = _getch();

		switch (c)
		{
		case '1':  //录入学生登陆信息 
			inputStudent(head);
			break;
		case '2':  //打印学生信息
			printStudent(head);
			break;
		case '3':  //统计座位数目 
			countStudyRoomSeats(head);
			break;
		case '4':  //查找学生信息
			findStudent(head);
			break;
		case '5':  //修改学生信息
			modifyStudent(head);
			break;
		case '6':  //删除学生信息
			deleteStudent(head);
			break;
		/*case '7': //释放所有座位
		 	freeSeats();
		 	system("cls");
		 	printf("已释放所有座位！\n");
			printf("欢迎下次使用本系统，再见！\n");
			exit(0);
			break;*/
		case '8':  //退出系统
			system("cls");
			printf("欢迎下次使用本系统，再见！\n");
			exit(0);
			break;
		default:
			printf("请重新输入\n");
			break;
		}
	}

	return 0;
}

void welcome() {
	printf("*********************************\n");
	printf("*\t自习室管理系统\t\t*\n");
	printf("*********************************\n");
	printf("*\t请选择功能列表\t\t*\n");
	printf("*********************************\n");
	printf("*\t1.录入学生信息\t\t*\n");
	printf("*\t2.打印学生信息\t\t*\n");
	printf("*\t3.统计座位个数\t\t*\n");
	printf("*\t4.查找学生信息\t\t*\n");
	printf("*\t5.修改学生信息\t\t*\n");
	printf("*\t6.删除学生信息\t\t*\n");
	printf("*\t7.释放所有座位\t\t*\n");
	printf("*\t8.退出系统\t\t*\n");

	printf("*********************************\n");
}

void inputStudent(Node* head) {

	Node* fresh = malloc(sizeof(Node));
	fresh->next = NULL;
	printf("请输入学生的学号，姓名\n");
	scanf("%d%s", &fresh->student.stuNum, fresh->student.name);

	Node* move = head;
	while (move->next != NULL) {
		move = move->next;
	}
	//将学生插入到尾部
	move->next = fresh;

	saveStudent(head);
	//暂停程序
	system("pause");
	//清空控制台
	system("cls");
}

void printStudent(Node* head) {
	Node* move = head->next;
	while (move != NULL) {
		printf("学号:%d 姓名:%s \n", move->student.stuNum, move->student.name);
		move = move->next;
	}
	//暂停程序
	system("pause");
	//清空控制台
	system("cls");
}

void countStudyRoomSeats(Node* head) {
	int count = 0;
	Node* move = head->next;
	while (move != NULL) {
		count++;
		move = move->next;
	}
	printf("剩余座位个数为:%d\n",100 - count);
	//暂停程序
	system("pause");
	//清空控制台
	system("cls");
}

void findStudent(Node* head) {
	printf("请输入要查找的学生的学号: ");
	int stuNum;
	scanf("%d", &stuNum);
	Node* move = head->next;
	while (move != NULL) {
		if (stuNum == move->student.stuNum) {
			printf("学号: %d 姓名:%s ", move->student.stuNum, move->student.name);
			//暂停程序
			system("pause");
			//清空控制台
			system("cls");
			return;
		}
		move = move->next;
	}
	printf("未找到学生信息\n");
	//暂停程序
	system("pause");
	//清空控制台
	system("cls");
}

void saveStudent(Node* head) {
	FILE* file = fopen("data.txt", "w");
	Node* move = head->next;
	while (move != NULL) {
		if (fwrite(&move->student, sizeof(Student), 1, file) != 1) {
			printf("写入失败\n");
			return;
		}
		move = move->next;
	}
	fclose(file);
}

void loadStudent(Node* head) {
	FILE* file = fopen("data.txt", "r");
	if (!file) {
		printf("没有学生文件,跳过读取\n");
		return;
	}
	Node* fresh = malloc(sizeof(Node));
	fresh->next = NULL;
	Node* move = head;
	while (fread(&fresh->student, sizeof(Student), 1, file) == 1) {
		move->next = fresh;
		move = fresh;
		fresh = malloc(sizeof(Student));
		fresh->next = NULL;
	}
	free(fresh);
	fclose(file);
	printf("读取成功\n");
}

void modifyStudent(Node* head) {
	printf("请输入要修改的学生的学号: ");
	int stuNum;
	scanf("%d", &stuNum);
	Node* move = head->next;
	while (move != NULL) {
		if (move->student.stuNum == stuNum) {
			printf("请输入学生姓名\n");
			scanf("%s", move->student.name);
			saveStudent(head);
			printf("修改成功\n");
			//暂停程序
			system("pause");
			//清空控制台
			system("cls");
			return;
		}
		move = move->next;
	}
	printf("未找到学生信息\n");
	//暂停程序
	system("pause");
	//清空控制台
	system("cls");
}

void deleteStudent(Node* head) {
	printf("请输入要删除的学生学号 ");
	int stuNum = 0;
	scanf("%d", &stuNum);

	Node* move = head;
	while (move->next != NULL) {
		
		if (move->next->student.stuNum == stuNum) {
			Node* tmp = move->next;
			move->next = move->next->next;
			free(tmp);
			tmp = NULL;
			saveStudent(head);
			printf("删除成功\n");
			//暂停程序
			system("pause");
			//清空控制台
			system("cls");
			return;
		}

		move = move->next;
	}
	printf("未找到学生信息\n");
	//暂停程序
	system("pause");
	//清空控制台
	system("cls");
}


/*int freeSeats() {
    const char *filename = "data.txt";

    // 打开文件以清空内容
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // 关闭文件
    fclose(file);

    printf("已释放所有座位\n", filename);

    return 0;
}*/
