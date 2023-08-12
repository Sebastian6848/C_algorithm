#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//建立结点数据结构 
typedef struct node
{
	int data;
	struct node *next;
}Node,*Link;

int main()
{
	int n,m,count,i;
	//定义头结点head 
	Link head,tail,p,q;
	head = (Link)malloc(sizeof(Node));
	head->next = NULL;
	
	while(1)
	{
		scanf("%d %d",&n,&m);
		if(n==0&&m==0)//结束条件 
		{
			free(head);
			break;
		}
		else
		{
			tail = head;
			for(i=0;i<n;i++)//尾插法生成循环链表 
			{
				p = (Link)malloc(sizeof(Node));
				p->data = i+1;
				tail->next = p;
				p->next = head->next;
				tail = p;
			}
			p = head->next;//p指向第一个结点 
			q = tail;//q指向最后一个结点

            i = 1;
			while(p!=q)//出列 
			{
				if(i==m)
				{
					q->next = p->next;
					free(p);
					p = q->next;
					i = 1;//第二趟报数 
				}
				else//q指针在p指针之前，如果两个指针重合，说明只剩下一个结点 
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
