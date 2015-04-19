#include <cstdio>
#include <cctype>
#include <set>

using namespace std;

int H, W;

int p[10000];

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

inline int idx(int x, int y)
{
	return x * (W + 1) + y;
}

inline int getdigit(char c)
{
	int rnt;
	if (isdigit(c))
	{
		rnt = c - '0';
	}
	else
	{
		rnt = c - 'A' + 10;
	}
	return rnt;
}

inline bool up(char c)
{
	return getdigit(c) / 4 > 1;
}

inline bool down(char c)
{
	return getdigit(c) % 4 > 1;
}

inline bool left(char c)
{
	return getdigit(c) % 4 % 2 == 1;
}

inline bool right(char c)
{
	return getdigit(c) / 4 % 2 == 1;
}

void solve()
{
	bool flag = false;
	char s[55];
	for (int i = 0; i < (H + 1) * (W + 1); ++i)
	{
		p[i] = i;
	}
	for (int i = 0; i < H; ++i)
	{
		scanf("%s", s);
		for (int j = 0; j < W; ++j)
		{
			if (i == 0 && up(s[j]))
			{
				int u = find(idx(0, j));
				int v = find(idx(0, j + 1));
				p[v] = u;
			}
			if (j == 0 && left(s[j]))
			{
				int u = find(idx(i, 0));
				int v = find(idx(i + 1, 0));
				p[v] = u;
			}
			if (down(s[j]))
			{
				int u = find(idx(i + 1, j));
				int v = find(idx(i + 1, j + 1));
				if (u == v)
				{
					flag = true;
				}
				p[v] = u;
			}
			if (right(s[j]))
			{
				int u = find(idx(i, j + 1));
				int v = find(idx(i + 1, j + 1));
				if (u == v)
				{
					flag = true;
				}
				p[v] = u;
			}
		}
	}
	set<int> parts;
	for (int i = 0; i < (H + 1) * (W + 1); ++i)
	{
		parts.insert(find(i));
	}
	if (parts.size() == 1)
	{
		printf("NO SOLUTION\n");
		return;
	}
	if (flag)
	{
		printf("UNREACHABLE CELL\n");
		return;
	}
	if (parts.size() == 2)
	{
		printf("MAZE OK\n");
		return;
	}
	printf("MULTIPLE PATHS\n");
}

int main()
{
	while (scanf("%d %d", &H, &W) == 2 && H && W)
	{
		solve();
	}
	return 0;
}
