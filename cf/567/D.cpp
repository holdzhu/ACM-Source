#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int x[200000];

int main()
{
	int n, k, a;
	scanf("%d %d %d", &n, &k, &a);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		int t;
		scanf("%d", &t);
		x[i] = t - 1;
	}
	int L = 0;
	int R = m;
	while (L < R)
	{
		int M = (L + R) >> 1;
		vector<int> t;
		for (int i = 0; i <= M; ++i)
		{
			t.push_back(x[i]);
		}
		sort(t.begin(), t.end());
		int p = 0;
		int tp = 0;
		bool flag = true;
		for (int i = 0; i < k; ++i)
		{
			while (tp < t.size() && p + a > t[tp])
			{
				p = t[tp] + 1;
				tp++;
			}
			if (p + a <= n)
			{
				if (p + a == t[tp])
				{
					tp++;
				}
				p += a + 1;
			}
			else
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			L = M + 1;
		}
		else
		{
			R = M;
		}
	}
	if (L == m)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", L + 1);
	}
	return 0;
}
