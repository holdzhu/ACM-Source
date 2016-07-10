#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		a |= t;
	}
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		b |= t;
	}
	printf("%d\n", a + b);
	return 0;
}
