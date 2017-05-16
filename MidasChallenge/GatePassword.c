#include <stdio.h>

/*
현관 비밀번호 문제 (GatePassword)

마이다스아이티 개발자 길동이는 현관 비밀번호를 특이한 방법으로 만든다고 합니다. 비밀번호는 서로 다른 N개의 숫자들로 구성되고, 최소 한 개의 홀수와 짝수를 포함하고 있으며, 비밀번호 숫자의 순서는 오름차순으로 이루어져 있습니다. 비밀번호로 사용했을 가능성이 있는 M개의 숫자가 주어지는 경우, 가능성 있는 모든 비밀번호를 구하는 프로그램을 작성하십시오. 단, 숫자 0은 짝수라고 가정합니다.

예를 들어 비밀번호는 5개의 숫자로 구성되고 “1 0 9 5 7 3” 6개의 숫자가 주어지는 경우, 비밀번호가 될 수 있는 숫자 배열은 “01357”, “01359”, “01379”, “01579”, “03579” 5가지입니다.

입력

입력은 표준 입력(stdin)으로 주어지며
첫째 줄에 두 자연수 N, M이 주어집니다. (3<=N<=M<=10)
둘째 줄에는 M개의 0이상의 한자리 숫자가 공백으로 구분되어 주어지며, 주어지는 숫자는 중복되지 않습니다. 즉, 1 1 혹은 2 2 처럼 같은 숫자가 주어지지는 않는다고 가정합니다.

출력

출력은 표준 출력(stdout)으로 이루어집니다.
첫째 줄에 가능성 있는 비밀번호의 개수를 출력합니다.
*/

int combination(int n, int r);

int main()
{
	int N=0, M=0;
	int i;
	int input[10] = { 0 };
	int odd = 0, even = 0; //홀짝
	int result = 0;
	
	scanf("%d", &N); //서로 다른 N개의 숫자들로 구성
	scanf("%d", &M); //첫째 줄, 3<=N<=M<=10, 비밀번호로 사용했을 가능성이 있는 M개의 숫자

	for (i = 0; i < M; i++)
	{
		scanf("%d", &input[i]); //둘째 줄, M개의 0이상의 한자리 숫자

		if (input[i] % 2 == 0) //홀짝 판별
			even++;
		else
			odd++;
	}
	
	for (i = 1; i < N; i++)
	{
		if (even < i || odd < i)
			break;
		result+=combination(even, i) + combination(odd, N - i);
	}

	printf("%d\n", result); //정답 출력
	
	return 0;
}
int combination(int n, int r)
{
	int i, result=1, size=n-r;

	if (n == r)
		return 0;

	for (i = 0; i < size; i++,n--)
	{
		result *= n;
	}

	return result;
}