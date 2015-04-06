#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a + b == 9 && c == 9 || a + b != 9 && c != a + b)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
