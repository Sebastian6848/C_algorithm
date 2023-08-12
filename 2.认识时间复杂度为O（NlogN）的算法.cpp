#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

/*���ַ�����������arr[L����R]�е����ֵ*/
int process1(int* arr, int L, int R)
{
	if (L == R)
		return arr[L];
	int mid = L + ((R - L) >> 1);//���е㣬����д���ɷ����
	int leftMax = process1(arr, L, mid);
	int rightMax = process1(arr, mid + 1, R);
	return leftMax > rightMax ? leftMax : rightMax;
}


int getMax(int* arr, int len)
{
	return process1(arr, 0, len - 1);
}

/*��·�鲢����*/
void merge(int* arr, int L, int M, int R)//��������������ְ���С���븨������help
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
void process(int* arr, int L, int R)//�ݹ�ʹmid������������
{
	if (L == R)
		return;
	int mid = L + ((R - L) >> 1);
	//����������еݹ���
	process(arr, L, mid);
	process(arr, mid + 1, R);
	//�ٽ�arr�е����������ֺϲ�Ϊ����ģ�L��midΪ��ಿ�֣�mid+1��R���Ҳ�
	merge(arr, L, mid, R);//ÿ�εݹ�����н�С����ϲ������ջ�õ�������������������ϳɵ���������
}
void mergeSort(int* arr, int len)
{
	if (arr == NULL || len < 2)
		return;
	process(arr, 0, len - 1);
	for (int k = 0; k < len; k++)
		printf("%d ", arr[k]);
}

/*С������*/
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
	//������������С�͵�����+�Ҳ����������С�͵�����+�����Ҳ�ϲ�ʱ����С�͵�����
}

int smallSum(int* arr,int len)
{
	if (arr == NULL || len < 2)
		return 0;
	return sortProcess(arr, 0, len - 1);
}

/*��������2.0*/
void quickSort(int* arr, int L, int R)
{
	if (L >= R)
		return;
	int i, j, base, temp;
	i = L;
	j = R;
	base = arr[L];//ȡ��������Ϊ��׼��
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
	arr[L] = arr[i];//��׼����λ
	arr[i] = base;
	quickSort(arr, L, i - 1);//�ݹ���ࣨС��base��
	quickSort(arr, i + 1, R);//�ݹ��Ҳࣨ����base��
}

int main()
{
	int arr[] = {1,3,4,2,5};
	int len = sizeof(arr) / sizeof(arr[0]); 
	quickSort(arr, 0, len - 1);
	for (int k = 0; k < len; k++)
		printf("%d ", arr[k]);
}

