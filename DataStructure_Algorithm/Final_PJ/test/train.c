#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define Max 100

typedef struct      //设置堆的结点类型
{
	char Name[10];  //排队人姓名
	int ID;   //排队人ID
	int key;  //排队人优先级（1-4）

}Heap;

Heap R[Max];


void sift(Heap R[], int low, int high)   //筛选调整堆
{
	int i = low, j = 2 * i; //R[j]是R[i]的左孩子
	Heap tmp = R[i];
	while (j <= high)
	{
		if (j < high && R[j].key < R[j + 1].key) j++;
		if (tmp.key < R[j].key)
		{
			R[i] = R[j];
			i = j;
			j = 2 * i;
		}
		else break;
	}
	R[i] = tmp;
}

void HeapSort(Heap R[], int n)    //堆排序
{
	int i; Heap tmp;
	for (i = n / 2; i >= 1; i--)
		sift(R, i, n);
	for (i = n; i >= 2; i--)
	{
		tmp = R[1];
		R[1] = R[i];
		R[i] = tmp;
		sift(R, 1, i - 1);
	}
}

void update(Heap R[], int n, int ID, int new)  //更新优先级信息并重新排列
{
	int i = 0, num = 0;  //num表示待更新的人在序列中的序号
	Heap tmp;
	for (i = 1; i <= n; i++)
	{
		if (R[i].ID == ID)
			num = i;
	}
	tmp = R[num];
	for (i = num; i < n; i++)   //该排队者离开
		R[i] = R[i + 1];
	R[n] = tmp;
	HeapSort(R, n);

}

void pop(Heap R[], int n)
{
	Heap tmp;
	tmp = R[1];
	R[1] = R[n];
	R[n] = tmp;
	n = n - 1;
	HeapSort(R, n);
}

void Output(Heap R[], int n)
{
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		printf("%s %d %d\n", R[i].Name, R[i].ID,R[i].key);

	}
}

int main()
{
	int i = 0, j = 0, n = 0;
	int tmpid = 0, tmpkey = 0;
	char s1[10], s2[10];

	for (i = 1;; i++)
	{
		printf("Please input your command:\n");
		scanf("%s", s1, 10);

		if (s1[0] == 'e')       //enqueue
		{
			printf("ee");
			scanf("%s %d %d", s2, &tmpid, &tmpkey);
			strcpy_s(R[i].Name, 10, s2);
			R[i].ID = tmpid;
			R[i].key = tmpkey;
			n += 1;
			HeapSort(R, n);
		}

		if (s1[0] == 'q')     //quit
		{
			scanf("%d", &tmpid);
			Heap tmp; int k=0;
			for (j = 1; j <= n; j++)
			{
				if (R[j].ID == tmpid)
					k = j;
			}
			tmp = R[k];
			for (j = k; i < n; i++)   //该排队者离开
				R[j] = R[j + 1];
			n -= 1;
			HeapSort(R, n);
		}

		if (s1[0] == 'u')
		{
			scanf("%d %d", &tmpid, &tmpkey);
			update(R, n, tmpid, tmpkey);
		}

		if (s1[0] == 'd')
		{
			pop(R, n);
			n = n - 1;
		}

		if (s1[0] == 'p')
		{
			Output(R, n);
			// break;

		}
	}
	return 0;
}