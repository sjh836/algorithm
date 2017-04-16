// 돌려 돌려 돌림판! https://www.acmicpc.net/problem/11504

#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int T;
	int test_case;

	scanf("%d", &T); // 첫 번째 줄에 테스트케이스의 개수 T가 주어진다.

	for (test_case = 1; test_case <= T; test_case++)
	{
		int N, M;
		int i, j,count=0; //count변수
		int *plate, *X, *Y, *Z;
		int Xvalue=0, Yvalue=0, Zvalue=0;

		scanf("%d", &N); // 돌림판을 N등분할 정수
		scanf("%d", &M); // X, Y의 길이 M
		X = (int *)malloc(sizeof(int)*M); // X의 크기(동적배열)
		Y = (int *)malloc(sizeof(int)*M); // Y의 크기(동적배열)
		Z = (int *)malloc(sizeof(int)*M); // Z의 크기(동적배열)
		plate = (int *)malloc(sizeof(int)*N); // 돌림판의 크기(동적배열)

		for (i = 0; i < M;i++)
			scanf("%d", &X[i]); // X의 각 자리수
		for (i = 0; i < M; i++)
			scanf("%d", &Y[i]); // X의 각 자리수
		for (i = 0; i < N; i++)
			scanf("%d", &plate[i]); // 돌림판에 들어갈 숫자

		for (i = 0; i < M; i++) //X,Y정수값으로 변환
		{
			Xvalue += X[i] * (int)pow(10, M - i-1);
			Yvalue += Y[i] * (int)pow(10, M - i-1);
		}

		for (i = 0; i < N; i++) //경우의 수 계산을 위한 반복문
		{
			for (j = 0; j < M; j++)
			{
				if (j + i<N)
					Z[j] = plate[j + i];
				else
					Z[j] = plate[N - 2 - i + j];
				Zvalue += Z[j] * (int)pow(10, M - j - 1); //Z정수값으로 변환
			}
			if ((Xvalue <= Zvalue) && (Zvalue<=Yvalue))
			{
				count++;
			}
			Zvalue = 0;
		}
		printf("%d\n", count);
		
		free(X); //메모리 반납
		free(Y);
		free(Z);
		free(plate);
	}

	return 0;
}