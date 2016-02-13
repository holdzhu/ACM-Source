#include <cstdio>
#include <unordered_set>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

unordered_set<ull> vis;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

ull s, t;

ull read()
{
	ull ret = 0;
	for (int i = 0; i < 4; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		ret |= 1ll << (x * 8 + y - 9);
	}
	return ret;
}

bool isvalid(int x, int y)
{
	return x >= 0 && y >= 0 && x < 8 && y < 8;
}

int get(int x, int y)
{
	return x * 8 + y;
}

bool solve(int step = 0, ull status = s)
{
	if (status == t)
		return true;
	printf("%d\n", step);
	if (step > 4 && __builtin_popcount(status & t) > 8 - step)
		return false;
	int x[4], y[4];
	for (int i = 0, j = 0; i < 64; ++i)
		if (status >> i & 1)
		{
			x[j] = i / 8;
			y[j] = i % 8;
			j++;
		}
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			int nx = x[i] + dx[j];
			int ny = y[i] + dy[j];
			if (isvalid(nx, ny))
			{
				if (!(status >> get(nx, ny) & 1))
				{
					if (solve(step + 1, status ^ (1ull << get(x[i], y[i])) ^ (1ull << get(nx, ny))))
						return true;
				}
				else if (isvalid(nx += dx[j], ny += dy[j]) && !(status >> get(nx, ny) & 1))
				{
					if (solve(step + 1, status ^ (1ull << get(x[i], y[i])) ^ (1ull << get(nx, ny))))
						return true;
				}
			}
		}
	return false;
}

int main()
{
	s = read();
	t = read();
	puts(solve() ? "YES" : "NO");
	return 0;
}
