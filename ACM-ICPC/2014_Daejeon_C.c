// 유레카 이론 https://www.acmicpc.net/problem/10448

#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#define SIZE 46

int eureka(int natural);
int eureka_last(int natural);
int Tn[SIZE] = { 0 }; //삼각수

int main(void)
{
	int T;
	int test_case;
	int *answer; //정답출력용
	int i; //카운트용 변수

	scanf("%d", &T); // 첫 번째 줄에 테스트케이스의 개수 T가 주어진다.
	answer = (int *)malloc(sizeof(int)*T);

	Tn[0] = 1;
	for (i = 1; i < SIZE; i++) //삼각수 초기화
		Tn[i] = i*(i + 1) / 2;

	for (test_case = 0; test_case < T; test_case++) // 로직
	{
		int K[4] = { 0 }; // K[0]은 사용자 입력값, K[1]~K[3]은 삼각수 3개로되는지 체크용
		int K1_index, K2_index, K3_index; // 삼각수 K[1]~K[3]의 인덱스

		scanf("%d", &K[0]); //각 테스트케이스는 한 줄에 자연수 K (3 ≤ K ≤ 1,000)가 하나씩 포함

		//printf("K[0] = %d\n", K[0]); //잘 들어갔나 디버깅용

		for (K1_index = eureka(K[0]); K1_index > 0; K1_index--)
		{
			K[1] = Tn[K1_index];
			//printf("K[1] = %d\n", K[1]); //잘 들어갔나 디버깅용
			if (K[1] <= K[2])
				break;
			for (K2_index = eureka(K[0] - K[1]); K2_index > 0; K2_index--)
			{
				K[2] = Tn[K2_index];
				//printf("K[2] = %d\n", K[2]); //잘 들어갔나 디버깅용
				if (K[2] <= K[3])
					break;
				K3_index = eureka_last(K[0] - K[1] - K[2]);
				K[3] = Tn[K3_index];
				//printf("K[3] = %d\n", K[3]); //잘 들어갔나 디버깅용
				if (K[1] + K[2] + K[3] == K[0])
					break;
			}
			if (K[1] + K[2] + K[3] == K[0])
				break;
		}

		if (K[1] + K[2] + K[3] == K[0]) //출력값 넣어줌
			answer[test_case] = 1;
		else
			answer[test_case] = 0;
	}
	for (test_case = 0; test_case < T; test_case++) // 출력
	{
		printf("%d\n", answer[test_case]);
	}
	free(answer); // 메모리 반납

	return 0;
}
int eureka(int natural)
{
	int i;
	int index;

	for (i = 1; i < SIZE; i++)
	{
		if (natural > Tn[i]) //Tn보다 자연수가 더 크면 계속 반복
			continue;
		else //Tn이 자연수보다크면 break하고 자연수보다 바로 아래 삼각수를 넣어줌
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
		if (natural >= Tn[i]) //Tn보다 자연수가 더 크면 계속 반복
			continue;
		else //Tn이 자연수보다크면 break하고 자연수보다 바로 아래or같은 삼각수를 넣어줌
		{
			index = i - 1;
			break;
		}
	}
	return index;
}