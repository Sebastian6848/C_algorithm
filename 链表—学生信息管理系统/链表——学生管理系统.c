//链表——学生管理系统
//============================================================================
// Name        : LinkBlank.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>

#define NO_LENGTH  20
#define NAME_LENGTH 11

/* 定义学生结构体的数据结构 */
typedef struct Student{
	char studentNo[NO_LENGTH];
	char studentName[NAME_LENGTH];
}st;

/* 定义每条记录或节点的数据结构 */
typedef struct node
{
	struct Student data; //数据域
	struct node *next; //指针域
}Node,*Link;  //Node为node类型的别名,Link为node类型的指针别名

//定义提示菜单
void myMenu(){
	printf(" * * * * * * * * * 菜     单 * * * * * * * * * *\n");
	printf("     1 增加学生记录            2 删除学生记录                     \n");
	printf("     3 查找学生记录            4 修改学生记录                     \n");
	printf("     5 统计学生人数            6 显示学生记录                     \n");
	printf("     7 退出系统                                     \n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * *\n");
}

void inputStudent(Link l){
	 printf("请输入学生学号:");
	 scanf("%s",l->data.studentNo);
	 printf("请输入学生的姓名:");
	 scanf("%s",l->data.studentName);
	 l->next = NULL;//每个新创建的节点的next域都初始化为NULL
}

void inputStudentNo(char s[],char no[]){
	printf("请输入要%s的学生学号:",s);
	scanf("%s",no);
}

/*1 增加学生记录 */
bool addNode(Link head){
	 Link p,q;   //p,q两个节点一前一后
	 Link node;  //node指针指向新创建的节点
	 node=(Link)malloc(sizeof(Node));
	 inputStudent(node);
	 q = head;
	 p = head->next;  //q指向head后面的第一个有效节点
	 if(head->next==NULL)
		head->next = node;
	 else {
		//循环访问链表中的所有节点
		while(p != NULL){
			if (node->data.studentNo < p->data.studentNo){
				//如果node节点的学号比p节点的学号小，则插在p的前面，完成插入后，提前退出子程序
				q->next = node;
				node->next = p;
				return true;
			}
			else{
				//如果node节点的学号比p节点的学号大，继续向后移动指针（依然保持pq一前一后）
				q = p;
				p = p->next;

			}
		}
		//如果没能提前退出循环，则说明之前没有插入，那么当前node节点的学号是最大值，此时插在链表的最后面
		q->next = node;
	}
	 return true;
}

/*2 删除学生记录*/
int deleteNode(Link head){
    char no[NO_LENGTH];
    Link p,q;
    q = head;
    p = head->next;
	inputStudentNo("修改",no);
    if(head == NULL ||head->next ==NULL)
        return false;
    while(p)
    {
        if(strcmp(p->data.studentNo,no)==0)
        {
            q->next = p->next;
            free(p);
            printf("删除成功！");
            return true;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }    
	return false;
}

/*3 查找学生记录*/
int queryNode(Link head){
	char no[NO_LENGTH];
	inputStudentNo("查找",no);
    Link p = head->next;
    while(p)
    {
        if(strcmp(p->data.studentNo,no)==0)
        {
            printf("查找成功\n");
            printf("学号为：%s\n",no);
            printf("姓名为：%s\n",p->data.studentName);
            return true;
        }
        else
            p = p->next;
    }
    printf("查无此人！");
	return false;
}

/*4 修改学生记录*/
bool modifyNode(Link head)
{
    if (head == NULL || head->next == NULL)
    {
        printf("暂无学生录入！\n");
    }
    //输入要处理的学号
    char no[NO_LENGTH];
    inputStudentNo("修改", no);
    for (Link p = head->next; p != NULL; p = p->next)
    {
        if (strcmp(p->data.studentNo, no) == 0)
        {
            printf("您要修改的学生信息如下 请确认\n");
            printf("学号:%s\n", p->data.studentNo);
            printf("姓名:%s\n", p->data.studentName);

            printf("修改选择(学号:1 姓名:2)\n");
            int y = 0;
            scanf("%d", &y);
            switch (y)
            {
            case 1:
                printf("请输入要修改的学号:\n");
                scanf("%s", p->data.studentNo);
                break;
            case 2:
                printf("请输入要修改的姓名:\n");
                scanf("%s", p->data.studentName);
                break;
            }
            return true;
        }
    }
    return false;
}

/*5 统计学生人数*/
int countNode(Link head)
{
	Link p;
	int count = 0;
    for(p=head->next;p!=NULL;p=p->next)
    {
        count++;
    }
    printf("共记录学生%d人\n",count);
}
/*6 显示学生记录*/
void displayNode(Link head){
    Link p = head->next;
    if(head==NULL || head->next == NULL)
        printf("未录入学生记录！");
    while(p)
    {
        printf("学生信息为：\n");
        printf("学号：%s\n",p->data.studentNo);
        printf("姓名：%s\n",p->data.studentName);
        p = p->next;
    }
}
/*7 退出系统*/
void clearLink(Link head)
{
	Link q,p;
    if(head == NULL || head->next == NULL)
        printf("链表为空，无法执行！");    
    p = head->next;
    q = p->next;
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }    
    free(head);
    printf("清除完成，退出系统！");
}

int main() {
	int select,count;
	Link head;  // 定义链表
	head = (Link)malloc(sizeof(Node));
	head->next = NULL;
	while(1)
	{
		myMenu();
		printf("\n请输入你的选择(0-7):");  //显示提示信息
		scanf("%d",&select);
		switch(select)
		{
		case 1:
			//增加学生记录
			if(addNode(head))
				printf("成功插入一个学生记录。\n\n");
			break;
		case 2:
			//删除学生记录
			if(deleteNode(head))
				printf("成功删除一个学生记录。\n\n");
			else
				printf("没有找到要删除的学生节点。\n\n");
			break;
		case 3:
			//查询学生记录
			if(queryNode(head))
				printf("成功找到学生记录。\n\n");
			else
				printf("没有找到要查询的学生节点。\n\n");
			break;
		case 4:
			//修改学生记录
			if(modifyNode(head))
				printf("成功修改一个学生记录。\n\n");
			else
				printf("没有找到要修改的学生节点。\n\n");
			break;
		case 5:
			//统计学生人数
			count = countNode(head);
			break;
		case 6:
			//显示学生记录
			displayNode(head);
			break;
		case 7:
			//退出前清除链表中的所有结点
            clearLink(head);
			return 0;
		default:
			printf("输入不正确，应该输入0-7之间的数。\n\n");
			break;
		}
	}
    system("pause");
	return 0;
}