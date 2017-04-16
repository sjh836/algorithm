// ���� ���� ������! https://www.acmicpc.net/problem/11504

#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int T;
	int test_case;

	scanf("%d", &T); // ù ��° �ٿ� �׽�Ʈ���̽��� ���� T�� �־�����.

	for (test_case = 1; test_case <= T; test_case++)
	{
		int N, M;
		int i, j,count=0; //count����
		int *plate, *X, *Y, *Z;
		int Xvalue=0, Yvalue=0, Zvalue=0;

		scanf("%d", &N); // �������� N����� ����
		scanf("%d", &M); // X, Y�� ���� M
		X = (int *)malloc(sizeof(int)*M); // X�� ũ��(�����迭)
		Y = (int *)malloc(sizeof(int)*M); // Y�� ũ��(�����迭)
		Z = (int *)malloc(sizeof(int)*M); // Z�� ũ��(�����迭)
		plate = (int *)malloc(sizeof(int)*N); // �������� ũ��(�����迭)

		for (i = 0; i < M;i++)
			scanf("%d", &X[i]); // X�� �� �ڸ���
		for (i = 0; i < M; i++)
			scanf("%d", &Y[i]); // X�� �� �ڸ���
		for (i = 0; i < N; i++)
			scanf("%d", &plate[i]); // �����ǿ� �� ����

		for (i = 0; i < M; i++) //X,Y���������� ��ȯ
		{
			Xvalue += X[i] * (int)pow(10, M - i-1);
			Yvalue += Y[i] * (int)pow(10, M - i-1);
		}

		for (i = 0; i < N; i++) //����� �� ����� ���� �ݺ���
		{
			for (j = 0; j < M; j++)
			{
				if (j + i<N)
					Z[j] = plate[j + i];
				else
					Z[j] = plate[N - 2 - i + j];
				Zvalue += Z[j] * (int)pow(10, M - j - 1); //Z���������� ��ȯ
			}
			if ((Xvalue <= Zvalue) && (Zvalue<=Yvalue))
			{
				count++;
			}
			Zvalue = 0;
		}
		printf("%d\n", count);
		
		free(X); //�޸� �ݳ�
		free(Y);
		free(Z);
		free(plate);
	}

	return 0;
}