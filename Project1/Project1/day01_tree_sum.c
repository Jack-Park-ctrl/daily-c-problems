#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	while (1) {
		int N;
		printf("�Է�(1<=N<=99) : ");
		scanf("%d", &N);

		if (N < 1 || N > 99) {
			printf("�Է� ����\n");
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

		printf("���� �밢�� ��: 1\n");
		printf("������ �밢�� �� : %d\n", sum);
		printf("����: %d\n", sum - 1);
		printf("\n");
	}

	return 0;
}