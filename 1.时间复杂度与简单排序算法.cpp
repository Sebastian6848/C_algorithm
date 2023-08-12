#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

/*交换数组中两元素位置*/
void swap(int* arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

/*选择排序*/
void selectsort(int* arr,int len)
{
	if (arr == NULL || len < 2)//边界检查，当数组为空或者数组只有一个元素时，直接输出结果
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

/*选择排序优化*/
void selectsort_plus(int* arr, int len)
{
	if (arr == NULL || len < 2)//边界检查，当数组为空或者数组只有一个元素时，直接输出结果
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
		if (min == right)//如果最小值被前一轮交换移动过
			min = max;
		swap(arr, min, left);
		left++, right--;
	}
	for (int k = 0; k < len; k++)
	{
		printf("%d ", arr[k]);
	}
}

/*使用位运算交换数组中两元素的位置*/
void swap1(int* arr, int i, int j)
{
	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

/*冒泡排序*/
void bubblesort(int* arr, int len)
{
	if (arr == NULL || len < 2)//边界检查，当数组为空或者数组只有一个元素时，直接输出结果
		return;
	for (int i = len - 1; i > 0; i--)//每经历一次大循环，最大的数n沉到队尾，下次循环考虑n前面的所有数
	{
		for (int j = 0; j < i; j++)//每次小循环比较相邻的两个数，将较大数后移
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

/*冒泡排序优化——鸡尾酒排序*/
void presort(int* arr, int len,int preindex)//从前往后排序
{
	for (int i = preindex + 1; i < len; i++)
	{
		if (arr[preindex] > arr[i])//将最小项放在preindex位置上
			swap1(arr, preindex, i);
	}
}
void backsort(int* arr, int len, int backindex)//从后往前排序
{
	for (int i = backindex - 1; i >= 0; i--)
	{
		if (arr[backindex] < arr[i])//将最大项放在backindex位置上
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

/*插入排序*/
void insertionsort(int* arr, int len)
{
	if (arr == NULL || len < 2)//边界检查，当数组为空或者数组只有一个元素时，直接输出结果
		return;
	for (int i = 1; i < len; i++)//0~i做到有序，i~len为无序
	{
		for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)//从右往左，依次比较，将数据插入，当插入到正确位置时停止
		{
			swap(arr, j, j + 1);
		}
	}
	for (int k = 0; k < len; k++)
	{
		printf("%d ", arr[k]);
	}
}
/*插入排序优化——折半插入排序*/
void insertionsort_plus(int* arr, int len)
{
	int low, high, mid;
	int j, temp;
	for (int i = 1; i < len; i++)
	{
		low = 0;
		high = i - 1;
		temp = arr[i];
		while (low <= high)//折半寻找合适的插入点high+1
		{
			mid = (low + high) / 2;
			if (arr[mid] <= temp)
				low = mid + 1;
			if (arr[mid] > temp)
				high = mid - 1;
		}

		for (j = i - 1; j >= high + 1; j--)//将插入点high+1后面的元素全部后移一位，留出一个空位
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;//将i号元素放入留出的空位中(由于前面多减了一个1，这里要加回来)
	}
	for (int k = 0; k < len; k++)
	{
		printf("%d ", arr[k]);
	}
}

/*寻找出现奇数次的数*/
void printOddTimesNum1(int* arr, int len)
{
	int eor = 0;
	for (int i = 0; i < len; i++)
	{
		eor = eor ^ arr[i];//将所有数异或
	}
	printf("%d", eor);
}

/*寻找两个出现奇数次的数*/
void printOddTimesNum2(int* arr, int len)
{
	int eor = 0;
	for (int i = 0; i < len; i++)
		eor = eor ^ arr[i];
	//eor = a^b

	int rightOne = eor & (~eor + 1);//eor中1出现的位置（最右侧）
	int onlyOne = 0;
	for (int j = 0; j < len; j++)
	{
		if ((arr[j] & rightOne) == rightOne)
		{
			onlyOne ^= arr[j];
		}	
		//onlyOne为a或者b
	}
	printf("%d %d", onlyOne, onlyOne ^ eor);
}

/*对数器——for test*/


int main()
{
	int arr[] = {101,101,211,211,211,985,985,985,985,612};
	int len = sizeof(arr) / sizeof(arr[0]); 
	printOddTimesNum2(arr,len);
}

