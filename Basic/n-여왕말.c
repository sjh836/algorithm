#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning (disable:4996)

void queens(int i);
int promising(int i);
int n;
int *col;

void main()
{
	printf("n���� �Է��Ͻÿ�: "); //n���� ����ڿ��� �Է¹���
	scanf("%d", &n);
	printf("============================================\n");
	col = (int *)malloc(sizeof(int)*(n + 1)); //�����迭 �����
	queens(0);
}

void queens(int i)
{
	int j, index;
	if (promising(i))
	{
		if (i == n) //�� Ž������ ��� �׵��� ã�� ���� �ش䰪 ���
		{
			printf("*�ش䰪: ");
			for (index = 0; index < n; index++)
			{
				printf("col[%d]=%d\t", index + 1, col[index + 1]);
			}
			printf("\n");
		}
		else
		{
			printf("\nqueens(%d) : �Լ�(���) ȣ��\n", i);
			for (j = 1; j <= n; j++)
			{
				printf("col[%d]=%d : %d���� %d�� ���ո� ���� �� ", i + 1, j, i + 1, j);
				col[i + 1] = j;
				queens(i + 1);
			}
		}
	}
}
int promising(int i)
{
	int k = 1;
	int Switch = 1;

	while (k < i&&Switch)
	{
		if (col[i] == col[k] || abs(col[i] - col[k]) == (i - k)) //������ �˻�, �밢�� �˻�
			Switch = 0;
		k++;
	}
	if (Switch == 1)
		printf("queens(%d)�� �����ϴ�\n", i);
	else
		printf("queens(%d)�� �������� �ʴ�\n", i);
	return Switch;
}