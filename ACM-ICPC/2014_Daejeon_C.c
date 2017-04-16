// ����ī �̷� https://www.acmicpc.net/problem/10448

#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#define SIZE 46

int eureka(int natural);
int eureka_last(int natural);
int Tn[SIZE] = { 0 }; //�ﰢ��

int main(void)
{
	int T;
	int test_case;
	int *answer; //������¿�
	int i; //ī��Ʈ�� ����

	scanf("%d", &T); // ù ��° �ٿ� �׽�Ʈ���̽��� ���� T�� �־�����.
	answer = (int *)malloc(sizeof(int)*T);

	Tn[0] = 1;
	for (i = 1; i < SIZE; i++) //�ﰢ�� �ʱ�ȭ
		Tn[i] = i*(i + 1) / 2;

	for (test_case = 0; test_case < T; test_case++) // ����
	{
		int K[4] = { 0 }; // K[0]�� ����� �Է°�, K[1]~K[3]�� �ﰢ�� 3���εǴ��� üũ��
		int K1_index, K2_index, K3_index; // �ﰢ�� K[1]~K[3]�� �ε���

		scanf("%d", &K[0]); //�� �׽�Ʈ���̽��� �� �ٿ� �ڿ��� K (3 �� K �� 1,000)�� �ϳ��� ����

		//printf("K[0] = %d\n", K[0]); //�� ���� ������

		for (K1_index = eureka(K[0]); K1_index > 0; K1_index--)
		{
			K[1] = Tn[K1_index];
			//printf("K[1] = %d\n", K[1]); //�� ���� ������
			if (K[1] <= K[2])
				break;
			for (K2_index = eureka(K[0] - K[1]); K2_index > 0; K2_index--)
			{
				K[2] = Tn[K2_index];
				//printf("K[2] = %d\n", K[2]); //�� ���� ������
				if (K[2] <= K[3])
					break;
				K3_index = eureka_last(K[0] - K[1] - K[2]);
				K[3] = Tn[K3_index];
				//printf("K[3] = %d\n", K[3]); //�� ���� ������
				if (K[1] + K[2] + K[3] == K[0])
					break;
			}
			if (K[1] + K[2] + K[3] == K[0])
				break;
		}

		if (K[1] + K[2] + K[3] == K[0]) //��°� �־���
			answer[test_case] = 1;
		else
			answer[test_case] = 0;
	}
	for (test_case = 0; test_case < T; test_case++) // ���
	{
		printf("%d\n", answer[test_case]);
	}
	free(answer); // �޸� �ݳ�

	return 0;
}
int eureka(int natural)
{
	int i;
	int index;

	for (i = 1; i < SIZE; i++)
	{
		if (natural > Tn[i]) //Tn���� �ڿ����� �� ũ�� ��� �ݺ�
			continue;
		else //Tn�� �ڿ�������ũ�� break�ϰ� �ڿ������� �ٷ� �Ʒ� �ﰢ���� �־���
		{
			index = i - 1;
			break;
		}
	}
	return index;
}
int eureka_last(int natural)
{
	int i;
	int index;

	for (i = 1; i < SIZE; i++)
	{
		if (natural >= Tn[i]) //Tn���� �ڿ����� �� ũ�� ��� �ݺ�
			continue;
		else //Tn�� �ڿ�������ũ�� break�ϰ� �ڿ������� �ٷ� �Ʒ�or���� �ﰢ���� �־���
		{
			index = i - 1;
			break;
		}
	}
	return index;
}