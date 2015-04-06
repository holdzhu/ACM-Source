#include <cstdio>
#include <cstring>

int N;
int a[100000];
int tmp[100000];
long long ans = 0;

void solve(int L, int R)
{
	if (L == R)
	{
		return;
	}
	int M = (L + R) >> 1;
	solve(L, M);
	solve(M + 1, R);
	int pos1 = L;
	int pos2 = M + 1;
	while (pos1 <= M && pos2 <= R)
	{
		if (a[pos1] > a[pos2])
		{
			ans += R - pos2 + 1;
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
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &a[i]);
	}
	solve(0, N - 1);
	printf("%lld\n", ans);
	return 0;
}
