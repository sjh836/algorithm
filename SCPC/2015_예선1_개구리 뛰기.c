#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);
	
	int T;
	int test_case;

	scanf("%d", &T); // 첫번째줄 T

	for (test_case = 1; test_case <= T; test_case++)
	{
		int *line;
		int rock, i, K,frog=0, count=0;

		scanf("%d", &rock); // 케이스의 1번째줄 돌의 갯수

		line = (int *)malloc(sizeof(int)*rock); // 케이스의 2두번째줄 돌있는 위치

		for (i = 0; i < rock; i++)
		{
			scanf("%d", &line[i]);
		}

		scanf("%d", &K); // 케이스의 3번째 줄 한번에 뛸수있는 거리 K

		for (i = 0; i < rock; i++)
		{
			if (line[i] - frog == K) //뛸수있어 딱. 무조건 뛰어야함, 바로 [i]로 점프해라
			{
				frog = line[i];
				count++;
			}
			else if (line[i] - frog > K) //뛸수없어, [--i]로 점프해라
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