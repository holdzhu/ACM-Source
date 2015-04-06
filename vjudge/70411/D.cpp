#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
pair<int, int> a[100];
pair<int, int> b[100];

int test(int u, int v)
{
	int al = 1000000000;
	int ar = -1000000000;
	int bl = 1000000000;
	int br = -1000000000;
	for (int ai = 0; ai < n; ++ai)
	{
		int t = a[ai].first * v + a[ai].second * u;
		if (t < al)
		{
			al = t;
		}
		if (t > ar)
		{
			ar = t;
		}
	}
	for (int ai = 0; ai < m; ++ai)
	{
		int t = b[ai].first * v + b[ai].second * u;
		if (t < bl)
		{
			bl = t;
		}
		if (t > br)
		{
			br = t;
		}
	}
	if (ar < bl || al > br)
	{
		return 1;
	}
	else if (ar == bl || al == br)
	{
		return 0;
	}
	return -1;
}

int main()
{
	while (scanf("%d %d", &n, &m) == 2 && n && m)
	{
		for (int i = 0; i < n; ++i)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			a[i].first = x;
			a[i].second = y;
		}
		for (int i = 0; i < m; ++i)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			b[i].first = x;
			b[i].second = y;
		}
		bool flag = false;
		if (n == 1 && m == 1)
		{
			flag = true;
		}
		else
		{
			for (int i = 0; i < n && !flag; ++i)
			{
				for (int j = i + 1; j < n && !flag; ++j)
				{
					int u = a[i].first - a[j].first;
					int v = - a[i].second + a[j].second;
					if (test(u, v) == 1)
					{
						flag = true;
						break;
					}
					if (test(v, -u) == 1)
					{
						flag = true;
						break;
					}
				}
			}
			for (int i = 0; i < m && !flag; ++i)
			{
				for (int j = i + 1; j < m && !flag; ++j)
				{
					int u = b[i].first - b[j].first;
					int v = - b[i].second + b[j].second;
					if (test(u, v) == 1)
					{
						flag = true;
						break;
					}
					if (test(v, -u) == 1)
					{
						flag = true;
						break;
					}
				}
			}
		}
		if (flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
