#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	while (1) {
		int N;
		printf("입력(1<=N<=99) : ");
		scanf("%d", &N);

		if (N < 1 || N > 99) {
			printf("입력 오류\n");
			break;
		}

		int i, j;
		int sum = 0;

		for (i = 1; i <= N; i++)
		{
			for (j = 1; j < i; j++)
			{
				printf(" ");
			}
			printf("%d", i);
			sum += i;
			printf("\n");
		}

		printf("왼쪽 대각선 합: 1\n");
		printf("오른쪽 대각선 합 : %d\n", sum);
		printf("차이: %d\n", sum - 1);
		printf("\n");
	}

	return 0;
}