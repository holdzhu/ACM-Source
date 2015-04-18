#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

int m[100001];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int n;
		scanf("%d", &n);
		memset(m, 0, sizeof m);
		int maxn = 0;
		for (int i = 0; i < n; ++i)
		{
			int t;
			scanf("%d", &t);
			if (t > maxn)
			{
				maxn = t;
			}
			int sqr = sqrt(t + 0.5);
			m[t]++;
			for (int i = 2; i <= sqr; ++i)
			{
				if (t % i == 0)
				{
					m[i]++;
					if (i * i != t)
					{
						m[t / i]++;
					}
				}
			}
		}
		int ans = 1;
		for (int i = 2; i <= maxn; ++i)
		{
			if (m[i] >= 2)
			{
				ans = i;
			}
		}
		printf("Case #%d: %d\n", kase, ans);
	}
	return 0;
}
