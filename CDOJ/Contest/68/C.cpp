#include <cstdio>
#include <cmath>


int p[100];
long long N;
int K;

long long t;
int cnt = 0;
long long ans = 0;

void dfs(int x = 0)
{
	if (t > N)
	{
		return;
	}
	if (x == K)
	{
		if (cnt % 2 == 1)
		{
			ans -= N / t;
		}
		else
		{
			ans += N / t;
		}
	}
	else
	{
		dfs(x + 1);
		cnt++;
		long long tmp = t;
		t *= p[x];
		dfs(x + 1);
		t = tmp;
		cnt--;
	}
}

double solve()
{
	double a = N;
	for (int i = 0; i < K; ++i)
	{
		a *= (1 - 1.0 / p[i]);
	}
	return a;
}

const int num = 1000000;

int main()
{
	scanf("%lld %d", &N, &K);
	for (int i = 0; i < K; ++i)
	{
		scanf("%d", &p[i]);
	}
	if (K < 100)
	{
		t = 1;
		dfs();
		printf("%lld\n", ans);
	}
	else
	{
		double sum = 0;
		int cnt = 0;
		int n = 0;
		for (int i = 0; i < num && N > 0; ++i)
		{
			n++;
			for (int j = 0; j < K; ++j)
			{
				if (N % p[j] == 0)
				{
					n--;
					break;
				}
			}
			N--;
			cnt++;
			sum += solve() + n;
		}
		printf("%lld\n", (long long)(sum / cnt + 3));
	}
	return 0;
}