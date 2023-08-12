#include<stdio.h>
#include<stdlib.h>

/*显示盘子移动轨迹*/
void move(char c1,char c2)
{
	printf("%c -> %c\n",c1,c2);
}

/*递归调用hanio函数*/
void hanio(int n,char A,char B,char C)
{
	if(n==1)
	    move(A,C);//递归终点
	else
	{
		hanio(n-1,A,C,B);
		move(A,C);
		hanio(n-1,B,A,C);
	}	 
} 

int main()
{
	int n;//有n个碟子
	printf("请输入碟子数量n：");
	scanf("%d",&n);
	hanio(n,'A','B','C');
	return 0; 
}
