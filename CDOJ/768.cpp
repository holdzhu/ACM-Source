#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	int a[40];
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i < 40; ++i)
	{
		a[i] = a[i - 2] + a[i - 1];
	}
	while (T--)
	{
		int N;
		scanf("%d", &N);
		printf("%d\n", a[N]);
	}
	return 0;
}
