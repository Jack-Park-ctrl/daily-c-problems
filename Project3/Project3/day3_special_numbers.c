#include <stdio.h>

void print_valid_numbers(void);
int is_valid(int num);

int main()
{
	print_valid_numbers();

	return 0;
}
void print_valid_numbers(void)
{
	int i;
	for (i = 100; i <= 999; i++) {
		if (is_valid(i))
		{
			printf("%d\n", i);
		}
	}
}
int is_valid(int num)
{
	int a[3], i = 0;
	
	while (num > 0 && i < 3)
	{
		a[i] = num % 10;
		num = num / 10;
		i++;
	}
	return (a[0] != a[1] && a[0] != a[2]&& a[1] != a[2] && a[2] % 2 == 0 && a[0] + a[1] + a[2] == 15 && a[1] < 5);

}