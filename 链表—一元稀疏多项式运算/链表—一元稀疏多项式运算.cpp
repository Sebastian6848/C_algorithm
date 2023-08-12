#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct polynomial
{
    int coef;//ϵ��
    int exp;//ָ��
    struct polynomial *next;
}*Link,Node;

void inputPoly(Link head);//���ڴӿ���̨��������ĺ���
void print(Link head);//��ӡ�����õĺ���
bool insert(Link head,int coef,int exp);//���������һ��Ԫ�صĺ���
void combin2List(Link heada,Link headb,Link headab);//�ϲ���������

int main()
{
    Link headA,headB;//��������ʽ��ͷָ��
    Link headAB;//�ϲ���Ķ���ʽ��ͷָ��

    /*����ĳ�ʼ��*/
    headA=(Link)malloc(sizeof(Node));
    headA->next=NULL;
    headB=(Link)malloc(sizeof(Node));
    headB->next=NULL;
    headAB=(Link)malloc(sizeof(Node));
    headAB->next=NULL;

    printf("�������һ������ʽ��ϵ����ָ������(0 0)������\n");
    inputPoly(headA);
    printf("��һ��");
    print(headA);
    printf("������ڶ�������ʽ��ϵ����ָ������(0 0)������\n");
    inputPoly(headB);
    printf("�ڶ���");
    print(headB);

    combin2List(headA,headB,headAB);
    printf("�ϲ���");
    print(headAB);
    return 0;
}

/**�������ʽ���ݵĺ���*/
/*������������������ʽ�����û����ʵ���ʾ�������û������ϵ����ָ����
���ú���insert�����û�����Ķ���ʽ��һ����뵽������ȥ��*/
void inputPoly(Link head)
{
    int coef,exp;//ϵ����ָ��
    printf("������ϵ����ָ��(�磺\"2 3\"��ʾ2x^3)��");
    scanf("%d %d",&coef,&exp);
    while(coef!=0||exp!=0)//����������ϵ����ָ��
    {
        insert(head,coef,exp);//�������������ʽ
        printf("������ϵ����ָ����");
        scanf("%d %d",&coef,&exp);
    }
}

/*�����ʽ�����в���Ԫ�صĺ���*/
bool insert(Link head,int coef,int exp)
{
    Link node;  //nodeָ��ָ���´����Ľڵ�
    Link q,p;  
    q = head;
    p = head->next;
    node = (Link)malloc(sizeof(Node));//����һ���½��
    if(head->next==NULL)//�ձ�,���1��
    {
        node->coef = coef;
        node->exp = exp;
        head->next = node;
        node->next = NULL;
    }
    else
    {
        while(p != NULL)//ѭ�����������е����нڵ�
	    { 
            node->coef = coef;
            node->exp = exp;
            //���node�ڵ��ָ����p�ڵ��ָ���������p��ǰ�棬��ɲ������ǰ�˳�
            if(node->exp > p->exp)
            {
            	node->next = p;
            	q->next = node;
            	return 1;
			}
            //���node�ڵ��ָ����p�ڵ��ָ����ȣ���ϲ��������ʽ�ڵ㣬��ǰ�˳�
            else if(node->exp == p->exp)
            {
            	p->coef += node->coef;
            	return 1;
			}
            //���node�ڵ��ָ����p�ڵ��ָ��С����������ƶ�ָ��
            else
            {
            	q = p;
            	p = p->next;
			}
	    }
	    //����˳�ѭ���ǵ�ǰָ��p�ƶ��������β����˵��֮ǰû�в��룬��ô��ǰnode�ڵ��ָ��ֵ�����ֵ����ʱ��������������
	    node->exp = exp;
	    node->coef = coef;
	    q->next = node;
	    node->next = NULL;
    }
    return true;
}

/*��ӡ����ʽ����ĺ���*/
/*
�١�ͨ��ָ���������
�ڡ������������Ƕ��
�ۡ�����ת��Ϊ�ַ�������itoa
�ܡ���־�Ƿ�Ϊ��һ���ڵ��flag������
�ݡ��ַ������Ӻ���strcat
�ޡ��ַ�����պ���memset��memset(item,0,20);��ճ�20���ַ���item
*/
void print(Link head)
{
    Link p; //ָ������Ҫ����Ľ��
    printf("����ʽ���£�\n");
    p=head->next;

    if (p == NULL)
    {
        printf("����ʽΪ��\n");
        return;
    }
    // ���ǿձ�
    char item[20]="";//Ҫ��ӡ�ĵ�ǰ����ʽ��һ��
    char number[7]="";//��ʱ���ϵ��ת���ɵ��ַ���

    bool isFirstItem=true;//��־�Ƿ�Ϊ��һ���ڵ��flag
    //��ӡ�ڵ�
    while(p != NULL)
    {
        if(isFirstItem) //����ǵ�һ���Ҫ��+��
        {
        	isFirstItem = false;
			if(p->coef > 0)
        	{
			    if(p->coef !=1){
			        if(p->exp == 1) printf("%dx",p->coef);
        	        printf("%dx^%d",p->coef,p->exp);}
        	    else{
        	        if(p->exp == 1) printf("x");
        	        printf("x^%d",p->exp);}//���ϵ��Ϊ1�����ô�ϵ��
            }
        	else if(p->coef < 0)//���ϵ��Ϊ������ϵ��������з���
			{
			    if(p->coef != -1){
			        if(p->exp == 1) printf("%dx",p->coef);
        	        printf("%dx^%d",p->coef,p->exp);}
        	    else{
        	        if(p->exp == 1) printf("-x");
        	        printf("-x^%d",p->exp);}//ϵ��Ϊ-1��ӡ����
            }  
			else
			    printf(""); 
		}
		
		else if(!isFirstItem && p->exp == 0)//���ָ��Ϊ0��ֱ�Ӵ�ϵ�����ô�x^��ָ��
		{
			if(p->coef > 0)1
			    printf("+%d",p->coef);
			else if(p->coef <0)
			    printf("%d",p->coef);
		    else
			    printf("");    
		}
		
		else if(!isFirstItem&& p->exp == 1)//���ָ��Ϊ1������ָ���������ָ��
        {
        	if(p->coef > 0)
        	{
			    if(p->coef !=1)
        	        printf("+%dx",p->coef);
        	    else
        	        printf("+x");//���ϵ��Ϊ1�����ô�ϵ��
            }
        	else if(p->coef < 0)//���ϵ��Ϊ������ϵ��������з���
			{
			    if(p->coef != -1)
        	        printf("%dx",p->coef);
        	    else
        	        printf("-x");//ϵ��Ϊ-1��ӡ����
            }  
			else
			    printf("");    
		}
		
        else if(!isFirstItem && p->exp != 0 && p->exp != 1)//������ǵ�һ���ϵ��Ϊ������Ҫ��Ӻ� 
        {
        	if(p->coef > 0)
        	{
			    if(p->coef !=1)
        	        printf("+%dx^%d",p->coef,p->exp);
        	    else
        	        printf("+x^%d",p->exp);//���ϵ��Ϊ1�����ô�ϵ��
            }
        	else if(p->coef < 0)//���ϵ��Ϊ������ϵ��������з���
			{
			    if(p->coef != -1)
        	        printf("%dx^%d",p->coef,p->exp);
        	    else
        	        printf("-x^%d",p->exp);//ϵ��Ϊ-1��ӡ����
            }  
			else
			    printf("");    
		}
		p = p->next;
    }
    printf("\n");
    return;
}

/*�ϲ�������������a��b������ab;heada.headb,headab�ֱ�Ϊ����a,b,ab��ͷָ��*/
void combin2List(Link heada,Link headb,Link headab)
{
    Link pa,pb,pab;//ָ��a��b�����ab��ָ��
    pa=heada->next;
    pb=headb->next;
    pab=headab->next;

    while(pa!=NULL&&pb!=NULL)//a,b����û��û�з������
    {
        //���ָ��a>ָ��b��a�ڵ����ab����aָ�����
        if(pa->exp > pb->exp)
        {
            insert(headab,pa->coef,pa->exp);
            pa = pa->next;
		}
        //���ָ��a<ָ��b��b�ڵ����ab����bָ�����
        else if(pa->exp < pb->exp)
        {
        	insert(headab,pb->coef,pb->exp);
        	pb = pb->next;
		}
        //���ָ��a==ָ��b��a��bϵ����ӣ�����ab����a��bָ�����
        else if(pa->exp == pb->exp)
        {
        	pa->coef += pb->coef;
        	insert(headab,pa->coef,pa->exp);
        	pa = pa->next;
        	pb = pb->next;
		}
    }
     //���a��b������β�ͣ������ӵ�ab�������
    while(pa!=NULL)
    {
        insert(headab,pa->coef,pa->exp);
        pa = pa->next;
    }
    while(pb!=NULL)
    {
        insert(headab,pb->coef,pb->exp);
        pb = pb->next;        
    }
    return;
}



