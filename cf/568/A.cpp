#include <cstdio>
#include <cstring>

const int N = 4000000;
bool isprime[N + 1];
int sumprime[N + 1];
int sumrub[N + 1];
int tmp[100];

int main()
{
	memset(isprime, true, sizeof isprime);
	isprime[0] = 0;
	isprime[1] = 0;
	for (int i = 2; i <= N; ++i)
	{
		if (isprime[i] && i < 10000)
		{
			for (int j = i * i; j <= N; j += i)
			{
				isprime[j] = false;
			}
		}
	}
	sumprime[0] = 0;
	for (int i = 1; i <= N; ++i)
	{
		sumprime[i] = sumprime[i - 1] + isprime[i];
	}
	sumrub[0] = 0;
	for (int i = 1; i <= N; ++i)
	{
		int t = i;
		int p = 0;
		while (t)
		{
			tmp[p++] = t % 10;
			t /= 10;
		}
		bool flag = true;
		for (int i = 0; i < p / 2; ++i)
		{
			if (tmp[i] != tmp[p - 1 - i])
			{
				flag = false;
				break;
			}
		}
		sumrub[i] = sumrub[i - 1] + flag;
	}
	long long p, q;
	scanf("%I64d %I64d", &p, &q);
	int ans = -1;
	for (int i = 1; i <= N; ++i)
	{
		if (q * sumprime[i] <= p * sumrub[i])
		{
			ans = i;
		}
	}
	if (ans == -1)
	{
		puts("Palindromic tree is better than splay tree");
	}
	else
	{
		printf("%d\n", ans);
	}
	return 0;
}
