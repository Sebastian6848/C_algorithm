//������ѧ������ϵͳ

#include <stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>

#define NO_LENGTH  20
#define NAME_LENGTH 11

/* ����ѧ���ṹ������ݽṹ */
typedef struct Student{
	char studentNo[NO_LENGTH];
	char studentName[NAME_LENGTH];
}st;

/* ����ÿ����¼��ڵ�����ݽṹ */
typedef struct node
{
	struct Student data; //������
	struct node *next; //ָ����
}Node,*Link;  //NodeΪnode���͵ı���,LinkΪnode���͵�ָ�����

//������ʾ�˵�
void myMenu(){
	printf(" * * * * * * * * * ��     �� * * * * * * * * * *\n");
	printf("     1 ����ѧ����¼            2 ɾ��ѧ����¼                     \n");
	printf("     3 ����ѧ����¼            4 �޸�ѧ����¼                     \n");
	printf("     5 ͳ��ѧ������            6 ��ʾѧ����¼                     \n");
	printf("     7 �˳�ϵͳ                                     \n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * *\n");
}

void inputStudent(Link l){
	 printf("������ѧ��ѧ��:");
	 scanf("%s",l->data.studentNo);
	 printf("������ѧ��������:");
	 scanf("%s",l->data.studentName);
	 l->next = NULL;//ÿ���´����Ľڵ��next�򶼳�ʼ��ΪNULL
}

void inputStudentNo(char s[],char no[]){
	printf("������Ҫ%s��ѧ��ѧ��:",s);
	scanf("%s",no);
}

/*1 ����ѧ����¼ */
bool addNode(Link head){
	 Link p,q;   //p,q�����ڵ�һǰһ��
	 Link node;  //nodeָ��ָ���´����Ľڵ�
	 node=(Link)malloc(sizeof(Node));
	 inputStudent(node);
	 q = head;
	 p = head->next;  //qָ��head����ĵ�һ����Ч�ڵ�
	 if(head->next==NULL)
		head->next = node;
	 else {
		//ѭ�����������е����нڵ�
		while(p != NULL){
			if (node->data.studentNo < p->data.studentNo){
				//���node�ڵ��ѧ�ű�p�ڵ��ѧ��С�������p��ǰ�棬��ɲ������ǰ�˳��ӳ���
				q->next = node;
				node->next = p;
				return true;
			}
			else{
				//���node�ڵ��ѧ�ű�p�ڵ��ѧ�Ŵ󣬼�������ƶ�ָ�루��Ȼ����pqһǰһ��
				q = p;
				p = p->next;

			}
		}
		//���û����ǰ�˳�ѭ������˵��֮ǰû�в��룬��ô��ǰnode�ڵ��ѧ�������ֵ����ʱ��������������
		q->next = node;
	}
	 return true;
}

/*2 ɾ��ѧ����¼*/
int deleteNode(Link head){
    char no[NO_LENGTH];
    Link p,q;
    q = head;
    p = head->next;
	inputStudentNo("�޸�",no);
    if(head == NULL ||head->next ==NULL)
        return false;
    while(p)
    {
        if(strcmp(p->data.studentNo,no)==0)
        {
            q->next = p->next;
            free(p);
            printf("ɾ���ɹ���");
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

/*3 ����ѧ����¼*/
int queryNode(Link head){
	char no[NO_LENGTH];
	inputStudentNo("����",no);
    Link p = head->next;
    while(p)
    {
        if(strcmp(p->data.studentNo,no)==0)
        {
            printf("���ҳɹ�\n");
            printf("ѧ��Ϊ��%s\n",no);
            printf("����Ϊ��%s\n",p->data.studentName);
            return true;
        }
        else
            p = p->next;
    }
    printf("���޴��ˣ�");
	return false;
}

/*4 �޸�ѧ����¼*/
bool modifyNode(Link head)
{
    if (head == NULL || head->next == NULL)
    {
        printf("����ѧ��¼�룡\n");
    }
    //����Ҫ�����ѧ��
    char no[NO_LENGTH];
    inputStudentNo("�޸�", no);
    for (Link p = head->next; p != NULL; p = p->next)
    {
        if (strcmp(p->data.studentNo, no) == 0)
        {
            printf("��Ҫ�޸ĵ�ѧ����Ϣ���� ��ȷ��\n");
            printf("ѧ��:%s\n", p->data.studentNo);
            printf("����:%s\n", p->data.studentName);

            printf("�޸�ѡ��(ѧ��:1 ����:2)\n");
            int y = 0;
            scanf("%d", &y);
            switch (y)
            {
            case 1:
                printf("������Ҫ�޸ĵ�ѧ��:\n");
                scanf("%s", p->data.studentNo);
                break;
            case 2:
                printf("������Ҫ�޸ĵ�����:\n");
                scanf("%s", p->data.studentName);
                break;
            }
            return true;
        }
    }
    return false;
}

/*5 ͳ��ѧ������*/
int countNode(Link head)
{
	Link p;
	int count = 0;
    for(p=head->next;p!=NULL;p=p->next)
    {
        count++;
    }
    printf("����¼ѧ��%d��\n",count);
}
/*6 ��ʾѧ����¼*/
void displayNode(Link head){
    Link p = head->next;
    if(head==NULL || head->next == NULL)
        printf("δ¼��ѧ����¼��");
    while(p)
    {
        printf("ѧ����ϢΪ��\n");
        printf("ѧ�ţ�%s\n",p->data.studentNo);
        printf("������%s\n",p->data.studentName);
        p = p->next;
    }
}
/*7 �˳�ϵͳ*/
void clearLink(Link head)
{
	Link q,p;
    if(head == NULL || head->next == NULL)
        printf("����Ϊ�գ��޷�ִ�У�");    
    p = head->next;
    q = p->next;
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }    
    free(head);
    printf("�����ɣ��˳�ϵͳ��");
}

int main() {
	int select,count;
	Link head;  // ��������
	head = (Link)malloc(sizeof(Node));
	head->next = NULL;
	while(1)
	{
		myMenu();
		printf("\n���������ѡ��(0-7):");  //��ʾ��ʾ��Ϣ
		scanf("%d",&select);
		switch(select)
		{
		case 1:
			//����ѧ����¼
			if(addNode(head))
				printf("�ɹ�����һ��ѧ����¼��\n\n");
			break;
		case 2:
			//ɾ��ѧ����¼
			if(deleteNode(head))
				printf("�ɹ�ɾ��һ��ѧ����¼��\n\n");
			else
				printf("û���ҵ�Ҫɾ����ѧ���ڵ㡣\n\n");
			break;
		case 3:
			//��ѯѧ����¼
			if(queryNode(head))
				printf("�ɹ��ҵ�ѧ����¼��\n\n");
			else
				printf("û���ҵ�Ҫ��ѯ��ѧ���ڵ㡣\n\n");
			break;
		case 4:
			//�޸�ѧ����¼
			if(modifyNode(head))
				printf("�ɹ��޸�һ��ѧ����¼��\n\n");
			else
				printf("û���ҵ�Ҫ�޸ĵ�ѧ���ڵ㡣\n\n");
			break;
		case 5:
			//ͳ��ѧ������
			count = countNode(head);
			break;
		case 6:
			//��ʾѧ����¼
			displayNode(head);
			break;
		case 7:
			//�˳�ǰ��������е����н��
            clearLink(head);
			return 0;
		default:
			printf("���벻��ȷ��Ӧ������0-7֮�������\n\n");
			break;
		}
	}
	return 0;
}
