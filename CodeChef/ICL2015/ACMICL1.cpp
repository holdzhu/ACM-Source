#include <cstdio>

const int t[4] = {0, 2, 2, 3};

int dp(int x)
{
	if (x <= 4)
	{
		return t[x - 1];
	}
	if (x % 3 == 0)
	{
		return dp(x / 3) + 2;
	}
	else
	{
		return dp(x / 3 + 1) + 2;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		printf("%d\n", dp(N));
	}
	return 0;
}
