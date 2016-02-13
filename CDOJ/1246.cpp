#include <cstdio>
#include <cctype>

const int maxn = 31623;
int cnt = 0;
int prime[maxn + 1];
int prime2[maxn + 1];
bool isnotprime[maxn + 1];
int pre[maxn + 1];
int ans[maxn + 1];

int solve(int n)
{
	if (n <= maxn)
	{
		return ans[n];
	}
	int sum = 0;
	for (int i = 0; prime2[i] <= n; ++i)
	{
		while (n % prime[i] == 0)
		{
			n /= prime[i];
			sum += prime[i];
		}
	}
	if (sum == 0)
	{
		return n;
	}
	if (n > 1)
	{
		sum += n;
	}
	return solve(sum);
}

int main()
{
	int n;
	ans[4] = -1;
	ans[1] = 1;
	for (int i = 2; i <= maxn; ++i)
	{
		if (!isnotprime[i])
		{
			prime[cnt] = i;
			prime2[cnt++] = i * i;
			pre[i] = i;
			ans[i] = i;
		}
		else
		{
			ans[i] = ans[pre[i]];
		}
		for (int j = 0, k; j < cnt && (k = i * prime[j]) <= maxn; ++j)
		{
			isnotprime[k] = true;
			pre[k] = pre[i] + prime[j];
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
	while (1)
	{
		int c;
		while (!isdigit(c = getchar()) && c != EOF);
		if (c == EOF)
		{
			break;
		}
		int n = c - '0';
		while (isdigit(c = getchar()))
		{
			n = n * 10 + c - '0';
		}
		printf("%d\n", solve(n));
	}
	return 0;
}