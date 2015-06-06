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

int main()
{
	scanf("%lld %d", &N, &K);
	for (int i = 0; i < K; ++i)
	{
		scanf("%d", &p[i]);
	}
	t = 1;
	dfs();
	printf("%lld\n", ans);
	return 0;
}