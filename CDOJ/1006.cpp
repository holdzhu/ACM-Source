#include <cstdio>
#include <algorithm>

#define INF 1000000000

using namespace std;

int p[1000];
int f[1000];
int d[1000];
int a[1000];

void print(int x)
{
	if (f[x] >= 0)
	{
		print(f[x]);
	}
	printf("%d ", a[x]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			d[i] = INF;
		}
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < N; ++i)
		{
			int u;
			d[u = lower_bound(d, d + i, a[i]) - d] = a[i];
			p[u] = i;
			f[i] = u ? p[u - 1] : -1;
		}
		int ans = lower_bound(d, d + N, INF) - d;
		printf("%d ", ans);
		print(p[ans - 1]);
		printf("\n");
	}
	return 0;
}
