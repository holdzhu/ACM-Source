#include <cstdio>
#include <cstring>

int a[100000];
int tmp[100000];
long long inverse[16][16];
int N, K;
long long ans;

struct Colors
{
	int c[16];
};

Colors solve(int L, int R)
{
	if (L == R)
	{
		Colors colors;
		memset(colors.c, 0, sizeof colors.c);
		colors.c[a[L]] = 1;
		return colors;
	}
	int M = (L + R) >> 1;
	Colors colors1 = solve(L, M);
	Colors colors2 = solve(M + 1, R);
	for (int i = 0; i < K; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			inverse[i][j] += colors1.c[i] * colors2.c[j];
		}
	}
	int pos1 = L;
	int pos2 = M + 1;
	while (pos1 <= M && pos2 <= R)
	{
		if (a[pos1] < a[pos2])
		{
			tmp[pos1 - L + pos2 - M - 1] = a[pos1];
			pos1++;
		}
		else
		{
			tmp[pos1 - L + pos2 - M - 1] = a[pos2];
			pos2++;
		}
	}
	if (pos1 <= M)
	{
		for ( ; pos1 <= M; ++pos1)
		{
			tmp[pos1 - L + R - M] = a[pos1];
		}
	}
	else
	{
		for ( ; pos2 <= R; ++pos2)
		{
			tmp[pos2 - L] = a[pos2];
		}
	}
	memcpy(a + L, tmp, (R - L + 1) * sizeof(int));
	for (int i = 0; i < K; ++i)
	{
		colors1.c[i] += colors2.c[i];
	}
	return colors1;
}

int ansd[16];
bool vis[16];
long long curans;

void dfs(int de)
{
	if (curans >= ans)
	{
		return;
	}
	if (de == K)
	{
		if (ans > curans)
		{
			ans = curans;
		}
		return;
	}
	for (int i = 0; i < K; ++i)
	{
		if (!vis[i])
		{
			vis[i] = true;
			long long sum = 0;
			for (int j = 0; j < de; ++j)
			{
				sum += inverse[i][ansd[j]];
			}
			ansd[de] = i;
			curans += sum;
			dfs(de + 1);
			curans -= sum;
			vis[i] = false;
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; ++kase)
	{
		scanf("%d %d", &N, &K);
		memset(inverse, 0, sizeof inverse);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &a[i]);
			a[i]--;
		}
		solve(0, N - 1);
		memset(vis, 0, sizeof vis);
		curans = 0;
		ans = 100000000000000;
		dfs(0);
		printf("Case #%d: %lld\n", kase + 1, ans);
	}
	return 0;
}
