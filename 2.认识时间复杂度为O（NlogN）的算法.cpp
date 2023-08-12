#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

/*二分法求无序数组arr[L……R]中的最大值*/
int process1(int* arr, int L, int R)
{
	if (L == R)
		return arr[L];
	int mid = L + ((R - L) >> 1);//求中点，这种写法可防溢出
	int leftMax = process1(arr, L, mid);
	int rightMax = process1(arr, mid + 1, R);
	return leftMax > rightMax ? leftMax : rightMax;
}


int getMax(int* arr, int len)
{
	return process1(arr, 0, len - 1);
}

/*二路归并排序*/
void merge(int* arr, int L, int M, int R)//将左右两侧的数字按大小并入辅助数组help
{
	int* help = (int*)malloc(sizeof(int) * (R - L + 1));
	int i = 0;
	int p1 = L, p2 = M + 1;
	while (p1 <= M && p2 <= R)
		help[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
	while (p1 <= M)
		help[i++] = arr[p1++];
	while (p2 <= R)
		help[i++] = arr[p2++];
	for (int k = 0; k < i; k++)
		arr[L + k] = help[k];
}
void process(int* arr, int L, int R)//递归使mid左右两侧有序
{
	if (L == R)
		return;
	int mid = L + ((R - L) >> 1);
	//左右两侧进行递归拆分
	process(arr, L, mid);
	process(arr, mid + 1, R);
	//再将arr中的左右两部分合并为有序的，L到mid为左侧部分，mid+1到R是右侧
	merge(arr, L, mid, R);//每次递归过程中将小数组合并，最终会得到由两个有序子数组组合成的有序数组
}
void mergeSort(int* arr, int len)
{
	if (arr == NULL || len < 2)
		return;
	process(arr, 0, len - 1);
	for (int k = 0; k < len; k++)
		printf("%d ", arr[k]);
}

/*小和问题*/
int sortMerge(int* arr, int L, int mid, int R)
{
	int* help = (int*)malloc(sizeof(int) * (R - L + 1));
	int i = 0, p1 = L, p2 = mid + 1;
	int res = 0;
	while (p1 <= mid && p2 <= R)
	{
		res += arr[p1] < arr[p2] ? (R - p2 + 1) * arr[p1] : 0;
		help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
	}
	while (p1 <= mid)
		help[i++] = arr[p1++];
	while (p2 <= R)
		help[i++] = arr[p2++];
	for (int k = 0; k < i; k++)
	{
		arr[L + k] = help[k];
	}
	return res;
}

int sortProcess(int* arr, int L, int R)
{
	if (L == R)
		return 0;
	int mid = L + ((R - L) >> 1);
	return sortProcess(arr, L, mid) + sortProcess(arr, mid + 1, R) + sortMerge(arr, L, mid, R);
	//左侧排序并且求出小和的数量+右侧排序并且求出小和的数量+将左右侧合并时产生小和的数量
}

int smallSum(int* arr,int len)
{
	if (arr == NULL || len < 2)
		return 0;
	return sortProcess(arr, 0, len - 1);
}

/*快速排序2.0*/
void quickSort(int* arr, int L, int R)
{
	if (L >= R)
		return;
	int i, j, base, temp;
	i = L;
	j = R;
	base = arr[L];//取最左侧的数为基准数
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	arr[L] = arr[i];//基准数归位
	arr[i] = base;
	quickSort(arr, L, i - 1);//递归左侧（小于base）
	quickSort(arr, i + 1, R);//递归右侧（大于base）
}

int main()
{
	int arr[] = {1,3,4,2,5};
	int len = sizeof(arr) / sizeof(arr[0]); 
	quickSort(arr, 0, len - 1);
	for (int k = 0; k < len; k++)
		printf("%d ", arr[k]);
}

