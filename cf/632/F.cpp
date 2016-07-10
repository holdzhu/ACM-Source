#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[2500][2500];

bool solve()
{
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (a[i][j] != a[j][i])
				return false;
	for (int i = 0; i < n; ++i)
		if (a[i][i])
			return false;
	int mx = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			mx = max(mx, a[i][j]);
	for (int i = 0; i < n; ++i)
	{
		int idx = -1;
		int cnt = 0;
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
				continue;
			if (a[i][j] != mx)
			{
				cnt++;
				idx = j;
			}
		}
		if (cnt > 1)
			return false;
		if (idx != -1)
		{
			for (int j = 0; j < n; ++j)
			{
				if (j == idx || j == i)
					continue;
				if (a[idx][j] != mx)
					return false;
			}
		}
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);
	puts(solve() ? "MAGIC" : "NOT MAGIC");
	return 0;
}
