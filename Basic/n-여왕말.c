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
	printf("n값을 입력하시오: "); //n값을 사용자에게 입력받음
	scanf("%d", &n);
	printf("============================================\n");
	col = (int *)malloc(sizeof(int)*(n + 1)); //동적배열 만들기
	queens(0);
}

void queens(int i)
{
	int j, index;
	if (promising(i))
	{
		if (i == n) //다 탐색했을 경우 그동안 찾은 것중 해답값 출력
		{
			printf("*해답값: ");
			for (index = 0; index < n; index++)
			{
				printf("col[%d]=%d\t", index + 1, col[index + 1]);
			}
			printf("\n");
		}
		else
		{
			printf("\nqueens(%d) : 함수(노드) 호출\n", i);
			for (j = 1; j <= n; j++)
			{
				printf("col[%d]=%d : %d행의 %d열 여왕말 놓기 → ", i + 1, j, i + 1, j);
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
		if (col[i] == col[k] || abs(col[i] - col[k]) == (i - k)) //같은열 검사, 대각선 검사
			Switch = 0;
		k++;
	}
	if (Switch == 1)
		printf("queens(%d)는 유망하다\n", i);
	else
		printf("queens(%d)는 유망하지 않다\n", i);
	return Switch;
}