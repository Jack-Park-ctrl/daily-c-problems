#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void encrypt(char str[], int n);
void decrypt(char str[], int n);

int main()
{
	while (1)
	{
		char letter[100];
		printf("�Է��� ���ڿ� : ");
		scanf("%s", letter);
		int N;
		printf("ȸ���� �Ÿ� N(1~25): ");
		scanf("%d", &N);
		if (N < 1 || N > 25)   break;

		printf("\n");

		encrypt(letter, N);
		printf("��ȣȭ�� ���ڿ�: %s\n", letter);

		decrypt(letter, N);
		printf("��ȣȭ�� ���ڿ�: %s\n\n", letter);

	}


	return 0;
}
void encrypt(char str[], int n)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			str[i] = 'A' + (str[i] - 'A' + n) % 26;
		}
		else if ('a' <= str[i] && str[i] <= 'z') {
			str[i] = 'a' + (str[i] - 'a' + n) % 26;
		}
	}
}
void decrypt(char str[], int n)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			str[i] = 'A' + (str[i] - 'A' - n + 26) % 26;
		}
		else if ('a' <= str[i] && str[i] <= 'z') {
			str[i] = 'a' + (str[i] - 'a' - n + 26) % 26;
		}
	}
}
