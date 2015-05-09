#include <cstdio>
#include <cstring>
#include <cstring>

int c[13];
const char v[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
const int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int ans[15];
bool zero;

void multiply(int x)
{
	if (x <= 0)
	{
		zero = true;
		return;
	}
	for (int i = 0; i < 15 && x > 1; ++i)
	{
		while (x % prime[i] == 0)
		{
			ans[i]++;
			x /= prime[i];
		}
	}
}

void divide(int x)
{
	if (x <= 0)
	{
		zero = true;
		return;
	}
	for (int i = 0; i < 15 && x > 1; ++i)
	{
		while (x % prime[i] == 0)
		{
			ans[i]--;
			x /= prime[i];
		}
	}
}

unsigned long long solve()
{
	if (zero)
	{
		return 0;
	}
	unsigned long long t = 1;
	for (int i = 0; i < 15; ++i)
	{
		while (ans[i] > 0)
		{
			ans[i]--;
			t *= prime[i];
		}
	}
	return t;
}

void init()
{
	zero = false;
	memset(ans, 0, sizeof ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; ++kase)
	{
		int N;
		scanf("%d", &N);
		char s[3];
		memset(c, 0, sizeof c);
		for (int i = 0; i < N; ++i)
		{
			scanf("%s", s);
			for (int i = 0; i < 13; ++i)
			{
				if (v[i] == s[0])
				{
					c[i]++;
					break;
				}
			}
		}
		init();
		for (int i = 0; i < N; ++i)
		{
			multiply(i + 1);
		}
		for (int i = 0; i < 13; ++i)
		{
			if (c[i] == 2)
			{
				multiply(N - 3);
				divide(N - 1);
			}
			else if (c[i] == 3)
			{
				multiply(N - 5);
				multiply(N - 6);
				divide(N - 2);
				divide(N - 3);
			}
			else if (c[i] == 4)
			{
				multiply(N - 7);
				multiply(N - 8);
				multiply(N - 9);
				divide(N - 3);
				divide(N - 4);
				divide(N - 5);
			}
		}
		printf("%llu\n", solve());
	}
	return 0;
}
