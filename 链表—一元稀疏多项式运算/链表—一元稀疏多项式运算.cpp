#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct polynomial
{
    int coef;//系数
    int exp;//指数
    struct polynomial *next;
}*Link,Node;

void inputPoly(Link head);//用于从控制台读入链表的函数
void print(Link head);//打印链表用的函数
bool insert(Link head,int coef,int exp);//向链表插入一个元素的函数
void combin2List(Link heada,Link headb,Link headab);//合并两个链表

int main()
{
    Link headA,headB;//两个多项式的头指针
    Link headAB;//合并后的多项式的头指针

    /*链表的初始化*/
    headA=(Link)malloc(sizeof(Node));
    headA->next=NULL;
    headB=(Link)malloc(sizeof(Node));
    headB->next=NULL;
    headAB=(Link)malloc(sizeof(Node));
    headAB->next=NULL;

    printf("请输入第一个多项式的系数和指数，以(0 0)结束：\n");
    inputPoly(headA);
    printf("第一个");
    print(headA);
    printf("请输入第二个多项式的系数和指数，以(0 0)结束：\n");
    inputPoly(headB);
    printf("第二个");
    print(headB);

    combin2List(headA,headB,headAB);
    printf("合并后");
    print(headAB);
    return 0;
}

/**输入二项式数据的函数*/
/*这个函数用来输入二项式，给用户合适的提示，读入用户输入的系数和指数。
调用函数insert，将用户输入的二项式的一项插入到链表中去。*/
void inputPoly(Link head)
{
    int coef,exp;//系数和指数
    printf("请输入系数和指数(如：\"2 3\"表示2x^3)：");
    scanf("%d %d",&coef,&exp);
    while(coef!=0||exp!=0)//连续输入多个系数和指数
    {
        insert(head,coef,exp);//调函数输入多项式
        printf("请输入系数和指数：");
        scanf("%d %d",&coef,&exp);
    }
}

/*向多项式链表中插入元素的函数*/
bool insert(Link head,int coef,int exp)
{
    Link node;  //node指针指向新创建的节点
    Link q,p;  
    q = head;
    p = head->next;
    node = (Link)malloc(sizeof(Node));//创建一个新结点
    if(head->next==NULL)//空表,插第1个
    {
        node->coef = coef;
        node->exp = exp;
        head->next = node;
        node->next = NULL;
    }
    else
    {
        while(p != NULL)//循环访问链表中的所有节点
	    { 
            node->coef = coef;
            node->exp = exp;
            //如果node节点的指数比p节点的指数大，则插在p的前面，完成插入后，提前退出
            if(node->exp > p->exp)
            {
            	node->next = p;
            	q->next = node;
            	return 1;
			}
            //如果node节点的指数和p节点的指数相等，则合并这个多项式节点，提前退出
            else if(node->exp == p->exp)
            {
            	p->coef += node->coef;
            	return 1;
			}
            //如果node节点的指数比p节点的指数小，继续向后移动指针
            else
            {
            	q = p;
            	p = p->next;
			}
	    }
	    //如果退出循环是当前指针p移动到链表结尾，则说明之前没有插入，那么当前node节点的指数值是最大值，此时插在链表的最后面
	    node->exp = exp;
	    node->coef = coef;
	    q->next = node;
	    node->next = NULL;
    }
    return true;
}

/*打印多项式链表的函数*/
/*
①　通过指针访问链表
②　多重条件语句嵌套
③　数字转换为字符串函数itoa
④　标志是否为第一个节点的flag的设置
⑤　字符串连接函数strcat
⑥　字符串清空函数memset。memset(item,0,20);清空长20的字符串item
*/
void print(Link head)
{
    Link p; //指向链表要输出的结点
    printf("多项式如下：\n");
    p=head->next;

    if (p == NULL)
    {
        printf("多项式为空\n");
        return;
    }
    // 不是空表
    char item[20]="";//要打印的当前多项式的一项
    char number[7]="";//暂时存放系数转换成的字符串

    bool isFirstItem=true;//标志是否为第一个节点的flag
    //打印节点
    while(p != NULL)
    {
        if(isFirstItem) //如果是第一项，不要打+号
        {
        	isFirstItem = false;
			if(p->coef > 0)
        	{
			    if(p->coef !=1){
			        if(p->exp == 1) printf("%dx",p->coef);
        	        printf("%dx^%d",p->coef,p->exp);}
        	    else{
        	        if(p->exp == 1) printf("x");
        	        printf("x^%d",p->exp);}//如果系数为1，不用打系数
            }
        	else if(p->coef < 0)//如果系数为负数，系数自身带有符号
			{
			    if(p->coef != -1){
			        if(p->exp == 1) printf("%dx",p->coef);
        	        printf("%dx^%d",p->coef,p->exp);}
        	    else{
        	        if(p->exp == 1) printf("-x");
        	        printf("-x^%d",p->exp);}//系数为-1打印负号
            }  
			else
			    printf(""); 
		}
		
		else if(!isFirstItem && p->exp == 0)//如果指数为0，直接打系数不用打x^和指数
		{
			if(p->coef > 0)1
			    printf("+%d",p->coef);
			else if(p->coef <0)
			    printf("%d",p->coef);
		    else
			    printf("");    
		}
		
		else if(!isFirstItem&& p->exp == 1)//如果指数为1，不打指数，否则打指数
        {
        	if(p->coef > 0)
        	{
			    if(p->coef !=1)
        	        printf("+%dx",p->coef);
        	    else
        	        printf("+x");//如果系数为1，不用打系数
            }
        	else if(p->coef < 0)//如果系数为负数，系数自身带有符号
			{
			    if(p->coef != -1)
        	        printf("%dx",p->coef);
        	    else
        	        printf("-x");//系数为-1打印负号
            }  
			else
			    printf("");    
		}
		
        else if(!isFirstItem && p->exp != 0 && p->exp != 1)//如果不是第一项，且系数为正数，要打加号 
        {
        	if(p->coef > 0)
        	{
			    if(p->coef !=1)
        	        printf("+%dx^%d",p->coef,p->exp);
        	    else
        	        printf("+x^%d",p->exp);//如果系数为1，不用打系数
            }
        	else if(p->coef < 0)//如果系数为负数，系数自身带有符号
			{
			    if(p->coef != -1)
        	        printf("%dx^%d",p->coef,p->exp);
        	    else
        	        printf("-x^%d",p->exp);//系数为-1打印负号
            }  
			else
			    printf("");    
		}
		p = p->next;
    }
    printf("\n");
    return;
}

/*合并两个有序链表a，b到链表ab;heada.headb,headab分别为链表a,b,ab的头指针*/
void combin2List(Link heada,Link headb,Link headab)
{
    Link pa,pb,pab;//指向a，b链表和ab的指针
    pa=heada->next;
    pb=headb->next;
    pab=headab->next;

    while(pa!=NULL&&pb!=NULL)//a,b链表都没有没有访问完毕
    {
        //如果指数a>指数b，a节点插入ab链表，a指针后移
        if(pa->exp > pb->exp)
        {
            insert(headab,pa->coef,pa->exp);
            pa = pa->next;
		}
        //如果指数a<指数b，b节点插入ab链表，b指针后移
        else if(pa->exp < pb->exp)
        {
        	insert(headab,pb->coef,pb->exp);
        	pb = pb->next;
		}
        //如果指数a==指数b，a、b系数相加，插入ab链表，a、b指针后移
        else if(pa->exp == pb->exp)
        {
        	pa->coef += pb->coef;
        	insert(headab,pa->coef,pa->exp);
        	pa = pa->next;
        	pb = pb->next;
		}
    }
     //如果a、b链表还有尾巴，将它加到ab链表后面
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



