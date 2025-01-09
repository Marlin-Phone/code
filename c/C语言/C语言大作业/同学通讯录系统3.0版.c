/**
 * 项目名称：同学通讯录系统3.0版
 * 功能介绍：用文件存储同学录信息（完整的增、删、改、查功能）
 * 开发日期：
 * 作    者：
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INSERT 1    //增加某个同学
#define QUERY  2    //查找某个同学
#define UPDATE 3    //修改同学信息
#define DELETE 4    //删除某个同学
#define LIST   5    //列出所有同学
#define QUIT   0    //退出系统

FILE *fp;

typedef struct
{
    char name[100];   //同学姓名
    char addr[100];   //家庭住址
    char phone[100];  //联系电话
    char workfor[100];//工作单位
} TX;

TX txl[100];   //记录同学录的数组，最多100名同学
int last = 0;  //当前同学录中人数

void showMenu();
void doChoice(int);
int getChoice();
void doQuit();
void doInsert();
void doUpdate();
void doQuery();
void doDelete();
void doListAll();
void init();

int main(int argc, char *argv[])
{
    int choice; //用户的功能选择

    init();     //从文件中读入初始化同学录信息

    while (1)
    {
        //1. 显示功能主菜单
        showMenu();

        //2. 获取用户功能选择
        choice = getChoice();

        //3. 根据选择执行相应的功能
        doChoice(choice);
        
        //暂停，让用户看清楚，按任意键继续
        system("pause>nul");
    }    
    
    system("pause");
    return 0;
}

void init()
{
    int i = 0;

    if ((fp = fopen("txl.dat", "rb")) == NULL)
    {
        //printf("不能打开同学录信息文件txl.dat，请检查！");
        //exit(0);
        last = 0; //不存在数据文件，同学录为空。
    }
    else
    {
        while (!feof(fp))
        {
            if (fread(&txl[i], sizeof(TX), 1, fp) == 1)
            {
                //printf("读取第%d个同学\n", i);
                //system("pause");
                i++;
            }
        }

        last = i;
    }
    
    fclose(fp);
}

void save() //保存同学录到文件txl.dat中。
{
    int i = 0;

    if ((fp = fopen("txl.dat", "wb")) == NULL)
    {
        printf("不能打开同学录信息文件txl.dat，请检查！");
        exit(0);
    }

    while (i < last)
    {
        fwrite(&txl[i], sizeof(TX), 1, fp);
        //printf("保存第%d个同学\n", i);
        //system("pause");
        i++;
    }

    fclose(fp);
}

void showMenu()
{
    system("cls"); //调用DOS命令cls清屏
    printf("====同学录管理信息系统====\n");
    printf("\t1. 增加同学信息\n");
    printf("\t2. 查找同学信息\n");
    printf("\t3. 修改同学信息\n");
    printf("\t4. 删除同学信息\n");
    printf("\t5. 列出所有同学\n");
    printf("\t0. 退出系统\n");
    printf("========================\n");
    printf("请输入你的选择（0-5）：");
}

void doQuit()
{
    printf("\n欢迎下次使用本系统，再见！");
    exit(0);
}

void doInsert()
{
    printf("处理增加......\n");
    printf("姓名：");
    scanf("%s", &txl[last].name);
    printf("住址：");
    scanf("%s", &txl[last].addr);
    printf("电话：");
    scanf("%s", &txl[last].phone);
    printf("单位：");
    scanf("%s", &txl[last].workfor);
    printf("增加同学成功！\n");
    last++; //成功增加一名同学，人数加1。
    save();
}

void doUpdate()
{
    char tname[100]; //临时存放输入的姓名
    int i;
    int find = 0;   //是否找到该同学

    printf("处理修改......\n");
    printf("请输入要修改的同学姓名：");
    scanf("%s", &tname);

    for (i = 0; i < last && !find; i++)
    {
        if (!strcmp(tname, txl[i].name))
        {
            find = 1;
            printf("你找的同学信息如下：\n");
            printf("======================================================================\n");
            printf("姓名：%s\t", txl[i].name);
            printf("住址：%s\t", txl[i].addr);
            printf("电话：%s\t", txl[i].phone);
            printf("单位：%s\n", txl[i].workfor);
            printf("======================================================================\n");
            printf("\n请输入修改后的信息：\n");
            printf("姓名：");
            scanf("%s", &txl[i].name);
            printf("住址：");
            scanf("%s", &txl[i].addr);
            printf("电话：");
            scanf("%s", &txl[i].phone);
            printf("单位：");
            scanf("%s", &txl[i].workfor);
        }
    }
    if (!find)
    {
        printf("抱歉，姓名为%s的同学还没登入同学录中。", tname);
    }
    else
    {
        printf("姓名为%s的同学的信息已经成功修改！", tname);
        save();
    }
}

void doListAll()
{
    int i;

    printf("同学录中共有%d个同学的信息：\n", last);
    
    for (i = 0; i < last; i++)
    {
        printf("======================================================================\n");
        printf("姓名：%s\t", txl[i].name);
        printf("住址：%s\t", txl[i].addr);
        printf("电话：%s\t", txl[i].phone);
        printf("单位：%s\n", txl[i].workfor);
    }
    printf("======================================================================\n");
}

void doQuery()
{
    char tname[100]; //临时存放输入的姓名
    int i;
    int find = 0;   //是否找到该同学

    printf("处理查询......\n");
    printf("请输入同学姓名：");
    scanf("%s", &tname);

    for (i = 0; i < last && !find; i++)
    {
        if (!strcmp(tname, txl[i].name))
        {
            find = 1;
            printf("你找的同学信息如下：\n");
            printf("======================================================================\n");
            printf("姓名：%s\t", txl[i].name);
            printf("住址：%s\t", txl[i].addr);
            printf("电话：%s\t", txl[i].phone);
            printf("单位：%s\n", txl[i].workfor);
            printf("======================================================================\n");
        }
    }
    if (!find)
    {
        printf("抱歉，姓名为%s的同学还没登入同学录中。", tname);
    }
}

void doDelete()
{
    char tname[100]; //临时存储欲删的同学姓名
    int i;
    int find = 0;    //是否找到该同学
    int index;       //记录待删除的同学在数组中的下标
    
    printf("处理删除......\n");
    printf("请输入同学姓名：");
    scanf("%s", &tname);

    for (i = 0; i < last && !find; i++)
    {
        if (!strcmp(tname, txl[i].name))
        {
            find = 1;
            index = i; //存储待删的同学的下标位置
            break;
        }
    }
    if (!find)
    {
        printf("抱歉，姓名为%s的同学还没登入同学录中。", tname);
    }
    else
    {
        //执行删除该同学的操作
        for (i = index; i <= last; i++)
        {
            //将原来的第i+1个同学的信息复制到第i个位置
            strcpy(txl[i].name, txl[i+1].name);
            strcpy(txl[i].addr, txl[i+1].addr);
            strcpy(txl[i].phone, txl[i+1].phone);
            strcpy(txl[i].workfor, txl[i+1].workfor);
        }
        last--; //同学录中减少一名同学
        printf("姓名为%s的同学信息已经成功从同学录中删除！", tname);
        save();
    }
}

int getChoice()
{
    int choice;

    scanf("%d", &choice);
    
    return choice;
}

void doChoice(int choice)
{
    printf("正在处理第%d个选择!\n", choice);

    switch (choice)
    {
        case INSERT:
            doInsert();
            break;
        case QUERY:
            doQuery();
            break;
        case UPDATE:
            doUpdate();
            break;
        case DELETE:
            doDelete();
            break;
        case LIST:
            doListAll();
            break;
        case QUIT:
            doQuit();    
    }
}
