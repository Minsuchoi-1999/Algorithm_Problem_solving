#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

#define COKE_PRICE 1500
#define BURGER_PRICE 2000

int main()
{
	int num1, num2;
	scanf("%d", &num1);
	scanf("%d", &num2);

	if (num1 > 0 && num2 > 0) {
		printf("1");
	}
	else if (num1 < 0 && num2 > 0) {
		printf("2");
	}
	else if (num1 < 0 && num2 < 0) {
		printf("3");
	}
	else {
		printf("4");
	}


}

