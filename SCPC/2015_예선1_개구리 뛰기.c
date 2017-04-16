#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);
	
	int T;
	int test_case;

	scanf("%d", &T); // ù��°�� T

	for (test_case = 1; test_case <= T; test_case++)
	{
		int *line;
		int rock, i, K,frog=0, count=0;

		scanf("%d", &rock); // ���̽��� 1��°�� ���� ����

		line = (int *)malloc(sizeof(int)*rock); // ���̽��� 2�ι�°�� ���ִ� ��ġ

		for (i = 0; i < rock; i++)
		{
			scanf("%d", &line[i]);
		}

		scanf("%d", &K); // ���̽��� 3��° �� �ѹ��� �ۼ��ִ� �Ÿ� K

		for (i = 0; i < rock; i++)
		{
			if (line[i] - frog == K) //�ۼ��־� ��. ������ �پ����, �ٷ� [i]�� �����ض�
			{
				frog = line[i];
				count++;
			}
			else if (line[i] - frog > K) //�ۼ�����, [--i]�� �����ض�
			{
				if (line[--i] != frog)
				{
					frog = line[i];
					count++;
				}
				else if (line[i] == frog)
				{
					count = -1;
					break;
				}
			}
		}
		i = rock - 1;
		if (line[i] - frog <= K)
		{
			frog = line[i];
			count++;
		}
		else
			count = -1;
		free(line);

		printf("Case #%d\n", test_case);
		printf("%d\n", count);
	}

	return 0;
}