#include <stdio.h>
#define INF 99
#pragma warning (disable:4996)

void floyd(int D[][6], int P[][6]);
void print_graph(const int Array[][6]);
void print_path(int q, int r);
int P[6][6] = { 0 };
char *city[6] = { "월곡" ,"석계" ,"중화" ,"상계" ,"하계" ,"중계" }; // 배열인덱스와 도시이름을 매칭

void main()
{
	const int W[6][6] = {
		{ 0, 3, INF, INF, INF, INF }, //V0(월곡)에서 Vi로 가는 경우
		{ 3, 0, 4, INF, 2, 3 }, //V1(석계)에서 Vi로 가는 경우
		{ INF, INF, 0, INF, 5, INF }, //V2(중화)에서 Vi로 가는 경우
		{ 14, INF, 9, 0, 2, 4 }, //V3(상계)에서 Vi로 가는 경우
		{ 7, 1, INF, INF, 0, INF }, //V4(하계)에서 Vi로 가는 경우
		{ INF, INF, INF, 3, 2, 0 } //V5(중계)에서 Vi로 가는 경우
	};
	int D[6][6] = { 0 };
	int i, j;

	for (i = 0; i < 6; i++) // D(0) = W
		for (j = 0; j < 6; j++)
			D[i][j] = W[i][j];

	printf("V(0)=월곡, V(1)=석계, V(2)=중화, V(3)=상계, V(4)=하계, V(5)=중계\n");
	printf("\n그래프의 인접행렬 W = D(0) 상태\n");
	print_graph(W);

	floyd(D, P);
	printf("\n=======최단경로 찾기 최적화 실행 후=======\n");
	printf("D(최단경로의 길이) 상태\n");
	print_graph(D);
	printf("\nP(최단경로) 상태\n");
	print_graph(P);

	while (1)
	{
		printf("\n=======V(i)에서 V(j)로 가는 최단경로 출력=======\n");
		printf("V(0)=월곡, V(1)=석계, V(2)=중화, V(3)=상계, V(4)=하계, V(5)=중계\n");
		printf("\t※종료하려면 i=9, j=9를 입력하세요\n");
		printf("i를 입력하시오: ");
		scanf("%d", &i);
		printf("j를 입력하시오: ");
		scanf("%d", &j);
		if (i == 9 && j == 9)
			break;
		else
		{
			printf("V(%d): %s 출발\n", i, city[i]);
			print_path(i, j);
			printf("V(%d): %s 도착\n", j, city[j]);
			printf("최단경로의 길이: %d\n", D[i][j]);
		}
	}
}
void floyd(int D[][6], int P[][6])
{
	int i, j, k;

	for (k = 0; k < 6; k++) // V(k)를 경유할때
		for (i = 0; i < 6; i++) //V(i)에서 
			for (j = 0; j < 6; j++) // V(j)를 가는 최단 경로
				if (D[i][k] + D[k][j] < D[i][j])
				{
					P[i][j] = k; // 최단경로 저장
					D[i][j] = D[i][k] + D[k][j]; // 갱신
				}
}
void print_graph(const int Array[][6])
{
	int i, j;

	for (i = 0; i < 6; i++) // 배열값 출력
	{
		for (j = 0; j < 6; j++)
			printf("%3d ", Array[i][j]);
		printf("\n");
	}
}
void print_path(int q, int r)
{
	if (P[q][r] != 0)
	{
		print_path(q, P[q][r]);
		printf("V(%d): %s 경유\n", P[q][r], city[P[q][r]]);
		print_path(P[q][r], r);
	}
}
