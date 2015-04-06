#include <cstdio>

int pow10(int x, int n)
{
	if (n == 1)
	{
		return x;
	}
	int h = pow10(x, n / 2);
	h *= h;
	if (n % 2)
	{
		h *= x;
	}
	return h % 10;
}

int main()
{
	int T;
	scanf("%d", &T);
	int N;
	while (T--)
	{
		scanf("%d", &N);
		printf("%d\n", pow10(N % 10, N));
	}
	return 0;
}
