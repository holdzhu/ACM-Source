#include <cstdio>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	for (int i = 0; i * a <= c; ++i)
	{
		int t = c - i * a;
		if (t % b == 0)
		{
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}
