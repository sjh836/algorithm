#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int T;
	int test_case;
	FILE *fp;
	fp = fopen("C:\\lgcns\\output.txt", "w");

	scanf("%d", &T); // 첫 번째 줄에 테스트케이스의 개수 T가 주어진다.
	for (test_case = 0; test_case < T; test_case++) // 로직
	{
		unsigned long long int x, y,n,step,k;
		int i, j, count = 0;
		unsigned long long int *S;

		scanf("%lld", &x);
		scanf("%lld", &y);

		k = x;
		step = y - x+1;

		S = (unsigned long long int *)malloc(sizeof(unsigned long long int)*step);

		for (i = 0; i < step; i++, k++)
			S[i] = k;

		for (j = 0; j < step-1; j++)
		{
			short binary[64] = { 0 };

			n = S[j] ^ S[j + 1];

			for (i = 63; i > 0 && n>0; i--)
			{
				binary[i] = n % 2;
				n = n / 2;
			}
			for (i = 0; i < 64; i++)
			{
				if (binary[i] == 1)
					count++;
			}
		}
		fprintf(fp, "%d\n", count);
	}
	fclose(fp);
	printf("완료\n");

	return 0;
}