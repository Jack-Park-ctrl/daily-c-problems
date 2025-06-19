#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_valid_input(int n);

int main()
{
	while (1) {
		int n;
		printf("입력(1<=n<=5) : ");
		scanf("%d", &n);
		if (!is_valid_input(n)) {  
			printf("잘못된 입력입니다. 다시 입력하세요.\n");
			continue;
		}
		
		int i, j;
		for (i = 1; i <= n; i++)
		{
			for (j = i; j <= n - 1; j++)
			{
				printf(" ");
			}
			for (j = 1; j <= 2 * i - 1; j++)
			{
				printf("*");
			}
			printf("\n");
		}

	}
	return 0;

}
int is_valid_input(int n)
{
	return (n >= 1 && n <= 5);
}