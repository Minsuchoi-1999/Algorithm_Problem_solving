#include <stdio.h>

int main()
{
	int var1, var2;
	scanf("%d", &var1);
	scanf("%d", &var2);

	int c = var2 % 10;
	int b = (var2 % 100 - c) / 10;
	int a = var2 / 100;

	printf("%d\n%d\n%d\n%d", var1 * c, var1 * b, var1 * a, var1 * var2);
}

