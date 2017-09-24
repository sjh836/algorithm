#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	return *(int *)b - *(int *)a; //크면 음수, 작으면 양수 리턴
}

int main(void)
{
	int n; // 카드 수
	int i; // 카운트 변수 
	int *card;
	int negative_cnt = 0; // 음수 카운트 변수
	int max_2, max_3;
	int max_negative_2 = -1000, max_positive_2;
	int max_negative_3, max_positive_3;
	
	scanf("%d", &n); // 카드 수 입력
	card = (int *)malloc(sizeof(int)*n);
	 
	for (i=0; i<n; i++) { // 카드값 입력 
		scanf("%d", &card[i]);
		if (card[i] < 0) {
			negative_cnt++;
		}
	}
	
	qsort((void *)card, n, sizeof(int), compare); //퀵정렬, 낮은인덱스에 큰수 할당 
	
	//2개 뽑을떄
	if (negative_cnt >= 2) {
		max_negative_2 = card[n-1] * card[n-2];
	}
	max_positive_2 = card[0] * card[1];
	
	if (max_positive_2 > max_negative_2) {
		max_2 = max_positive_2;
	} else {
		max_2 = max_negative_2;
	}

	//3개 뽑을때
	if (negative_cnt >= 2) {
		max_negative_3 = max_negative_2 * card[0];
	}
	max_positive_3 = card[0] * card[1] * card[2];
	
	if (max_positive_3 > max_negative_3) {
		max_3 = max_positive_3;
	} else {
		max_3 = max_negative_3;
	}
	
	// 정답 출력
	if (max_3 > max_2) {
		printf("%d\n", max_3); 
	} else {
		printf("%d\n", max_2); 
	}

	free(card); // 메모리 반납

	return 0;
}