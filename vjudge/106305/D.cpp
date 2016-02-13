#include <cstdio>

int dp[101];
int v[100];
int stk[100];
int top;

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &v[i]);
		if (!v[i])
			i--, N--;
	}
	for (int i = 0; i < N; ++i)
	{
		dp[i + 1] = 1e9;
		top = 0;
		for (int j = i; j >= 0; --j)
		{
			stk[top++] = v[j];
			while (top > 1 && stk[top - 1] == stk[top - 2])
				stk[--top - 1] <<= 1;
			if (top == 1 && dp[i + 1] > dp[j] + 1)
				dp[i + 1] = dp[j] + 1;
		}
	}
	printf("%d\n", dp[N]);
	return 0;
}
