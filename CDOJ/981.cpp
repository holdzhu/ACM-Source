#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char a, b, c;
		scanf(" %c%c%c", &a, &b, &c);
		printf("%.2f\n", (a + b + c) / 3.0);
	}
	return 0;
}
