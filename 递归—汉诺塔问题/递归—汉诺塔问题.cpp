#include<stdio.h>
#include<stdlib.h>

/*��ʾ�����ƶ��켣*/
void move(char c1,char c2)
{
	printf("%c -> %c\n",c1,c2);
}

/*�ݹ����hanio����*/
void hanio(int n,char A,char B,char C)
{
	if(n==1)
	    move(A,C);//�ݹ��յ�
	else
	{
		hanio(n-1,A,C,B);
		move(A,C);
		hanio(n-1,B,A,C);
	}	 
} 

int main()
{
	int n;//��n������
	printf("�������������n��");
	scanf("%d",&n);
	hanio(n,'A','B','C');
	return 0; 
}
