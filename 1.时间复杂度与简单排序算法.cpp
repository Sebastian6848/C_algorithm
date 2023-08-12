#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

/*������������Ԫ��λ��*/
void swap(int* arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

/*ѡ������*/
void selectsort(int* arr,int len)
{
	if (arr == NULL || len < 2)//�߽��飬������Ϊ�ջ�������ֻ��һ��Ԫ��ʱ��ֱ��������
		return;
	for (int i = 0; i < len - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		swap(arr, i, minIndex);
	}
	for (int k = 0; k < len; k++)
	{
		printf("%d ", arr[k]);
	}
}

/*ѡ�������Ż�*/
void selectsort_plus(int* arr, int len)
{
	if (arr == NULL || len < 2)//�߽��飬������Ϊ�ջ�������ֻ��һ��Ԫ��ʱ��ֱ��������
		return;
	int left = 0, right = len - 1;
	while (left < right)
	{
		int min = left, max = right;
		for (int i = left; i <= right; i++)
		{
			if (arr[i] < arr[min])
				min = i;
			if (arr[i] > arr[max])
				max = i;
		}
		swap(arr, max, right);
		if (min == right)//�����Сֵ��ǰһ�ֽ����ƶ���
			min = max;
		swap(arr, min, left);
		left++, right--;
	}
	for (int k = 0; k < len; k++)
	{
		printf("%d ", arr[k]);
	}
}

/*ʹ��λ���㽻����������Ԫ�ص�λ��*/
void swap1(int* arr, int i, int j)
{
	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

/*ð������*/
void bubblesort(int* arr, int len)
{
	if (arr == NULL || len < 2)//�߽��飬������Ϊ�ջ�������ֻ��һ��Ԫ��ʱ��ֱ��������
		return;
	for (int i = len - 1; i > 0; i--)//ÿ����һ�δ�ѭ����������n������β���´�ѭ������nǰ���������
	{
		for (int j = 0; j < i; j++)//ÿ��Сѭ���Ƚ����ڵ������������ϴ�������
		{
			if (arr[j] > arr[j + 1])
				swap1(arr, j, j + 1);
		}
	}
	for (int k = 0; k < len; k++)
	{
		printf("%d ", arr[k]);
	}
}

/*ð�������Ż�������β������*/
void presort(int* arr, int len,int preindex)//��ǰ��������
{
	for (int i = preindex + 1; i < len; i++)
	{
		if (arr[preindex] > arr[i])//����С�����preindexλ����
			swap1(arr, preindex, i);
	}
}
void backsort(int* arr, int len, int backindex)//�Ӻ���ǰ����
{
	for (int i = backindex - 1; i >= 0; i--)
	{
		if (arr[backindex] < arr[i])//����������backindexλ����
			swap1(arr, backindex, i);
	}
}
void bubblesort_plus(int* arr, int len)
{
	int preindex = 0, backindex = len - 1;
	while (preindex < backindex)
	{
		presort(arr, len, preindex);
		preindex++;
		if (preindex >= backindex)
			break;
		backsort(arr, len, backindex);
		backindex--;
	}
	for (int k = 0; k < len; k++)
	{
		printf("%d ", arr[k]);
	}
}

/*��������*/
void insertionsort(int* arr, int len)
{
	if (arr == NULL || len < 2)//�߽��飬������Ϊ�ջ�������ֻ��һ��Ԫ��ʱ��ֱ��������
		return;
	for (int i = 1; i < len; i++)//0~i��������i~lenΪ����
	{
		for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)//�����������αȽϣ������ݲ��룬�����뵽��ȷλ��ʱֹͣ
		{
			swap(arr, j, j + 1);
		}
	}
	for (int k = 0; k < len; k++)
	{
		printf("%d ", arr[k]);
	}
}
/*���������Ż������۰��������*/
void insertionsort_plus(int* arr, int len)
{
	int low, high, mid;
	int j, temp;
	for (int i = 1; i < len; i++)
	{
		low = 0;
		high = i - 1;
		temp = arr[i];
		while (low <= high)//�۰�Ѱ�Һ��ʵĲ����high+1
		{
			mid = (low + high) / 2;
			if (arr[mid] <= temp)
				low = mid + 1;
			if (arr[mid] > temp)
				high = mid - 1;
		}

		for (j = i - 1; j >= high + 1; j--)//�������high+1�����Ԫ��ȫ������һλ������һ����λ
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;//��i��Ԫ�ط��������Ŀ�λ��(����ǰ������һ��1������Ҫ�ӻ���)
	}
	for (int k = 0; k < len; k++)
	{
		printf("%d ", arr[k]);
	}
}

/*Ѱ�ҳ��������ε���*/
void printOddTimesNum1(int* arr, int len)
{
	int eor = 0;
	for (int i = 0; i < len; i++)
	{
		eor = eor ^ arr[i];//�����������
	}
	printf("%d", eor);
}

/*Ѱ���������������ε���*/
void printOddTimesNum2(int* arr, int len)
{
	int eor = 0;
	for (int i = 0; i < len; i++)
		eor = eor ^ arr[i];
	//eor = a^b

	int rightOne = eor & (~eor + 1);//eor��1���ֵ�λ�ã����Ҳࣩ
	int onlyOne = 0;
	for (int j = 0; j < len; j++)
	{
		if ((arr[j] & rightOne) == rightOne)
		{
			onlyOne ^= arr[j];
		}	
		//onlyOneΪa����b
	}
	printf("%d %d", onlyOne, onlyOne ^ eor);
}

/*����������for test*/


int main()
{
	int arr[] = {101,101,211,211,211,985,985,985,985,612};
	int len = sizeof(arr) / sizeof(arr[0]); 
	printOddTimesNum2(arr,len);
}

