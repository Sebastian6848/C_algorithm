#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//����������ݽṹ 
typedef struct node
{
	int data;
	struct node *next;
}Node,*Link;

int main()
{
	int n,m,count,i;
	//����ͷ���head 
	Link head,tail,p,q;
	head = (Link)malloc(sizeof(Node));
	head->next = NULL;
	
	while(1)
	{
		scanf("%d %d",&n,&m);
		if(n==0&&m==0)//�������� 
		{
			free(head);
			break;
		}
		else
		{
			tail = head;
			for(i=0;i<n;i++)//β�巨����ѭ������ 
			{
				p = (Link)malloc(sizeof(Node));
				p->data = i+1;
				tail->next = p;
				p->next = head->next;
				tail = p;
			}
			p = head->next;//pָ���һ����� 
			q = tail;//qָ�����һ�����

            i = 1;
			while(p!=q)//���� 
			{
				if(i==m)
				{
					q->next = p->next;
					free(p);
					p = q->next;
					i = 1;//�ڶ��˱��� 
				}
				else//qָ����pָ��֮ǰ���������ָ���غϣ�˵��ֻʣ��һ����� 
				{
				    q = p;
					p = p->next;
					i++;	
				} 
			}
			printf("%d\n",p->data);
			free(p); 	 
		}
	}
	return 0;
}
