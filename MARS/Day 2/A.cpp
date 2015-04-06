#include <cstdio>
#include <algorithm>

using namespace std;

struct Road
{
	int x, y;
	int l;
};

bool cmp(const Road a, const Road b)
{
	return a.l < b.l;
}

int p[100];

int find(int x)
{
	return p[x] == x ? x : p[x] = find(p[x]);
}

int main()
{
	int N;
	while(scanf("%d", &N)==1)
	{
		Road a[N * N];
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				scanf("%d", &a[i * N + j].l);
				a[i * N + j].x = i;
				a[i * N + j].y = j;
			}
		}
		sort(a, a + N * N, cmp);
		for (int i = 0; i < N; ++i)
		{
			p[i] = i;
		}
		int ans = 0;
		for (int i = 0; i < N * N; ++i)
		{
			int x = find(a[i].x);
			int y = find(a[i].y);
			if (x != y)
			{
				ans += a[i].l;
				p[x] = y;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
