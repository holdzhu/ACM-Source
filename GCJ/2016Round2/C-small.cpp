#include <algorithm>
#include <cstdio>

using namespace std;

int R, C;
pair<int, int> p[100];
int ds[101 * 101];

int findset(int x) { return x == ds[x] ? x : ds[x] = findset(ds[x]); }

inline int idx(int x, int y) { return x * (C + 1) + y; }

void unionset(int x1, int y1, int x2, int y2)
{
	int u = idx(x1, y1);
	int v = idx(x2, y2);
	u = findset(u);
	v = findset(v);
	ds[u] = v;
}

pair<int, int> get(int x)
{
	if (x < C)
	{
		return {x, x + 1};
	}
	else if (x < R + C)
	{
		x -= C;
		return {x * (C + 1) + C, (x + 1) * (C + 1) + C};
	}
	else if (x < R + C + C)
	{
		x -= R + C;
		return {R * (C + 1) + (C - x), R * (C + 1) + (C - x) - 1};
	}
	else
	{
		x -= R + C + C;
		return {(x + 1) * (C + 1), x * (C + 1)};
	}
}

bool issame(int x, int y) { return findset(x) == findset(y); }

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		scanf("%d %d", &R, &C);
		for (int i = 0; i < R + C; ++i)
		{
			scanf("%d %d", &p[i].first, &p[i].second);
			--p[i].first;
			--p[i].second;
		}
		printf("Case #%d:\n", kase);
		bool flag;
		for (int i = 0; i < 1 << (R * C); ++i)
		{
			for (int i = 0; i < (R + 1) * (C + 1); ++i)
				ds[i] = i;
			for (int j = 0; j < R; ++j)
				for (int k = 0; k < C; ++k)
					if (i >> (j * C + k) & 1)
						unionset(j, k, j + 1, k + 1);
					else
						unionset(j + 1, k, j, k + 1);
			flag = true;
			for (int j = 0; j < R + C; ++j)
			{
				pair<int, int> p1 = get(p[j].first);
				pair<int, int> p2 = get(p[j].second);
				if (!issame(p1.first, p2.second) ||
					!issame(p1.second, p2.first))
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				for (int j = 0; j < R; ++j, puts(""))
					for (int k = 0; k < C; ++k)
						putchar((i >> (j * C + k) & 1) ? '\\' : '/');
				break;
			}
		}
		if (!flag)
			puts("IMPOSSIBLE");
	}
	return 0;
}
