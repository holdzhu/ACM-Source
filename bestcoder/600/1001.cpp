#include <cstdio>
#include <algorithm>

using namespace std;

long long a[10001];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; ++kase)
	{
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < n; ++i)
		{
			scanf("%I64d", &a[i]);
		}
		sort(a, a + n);
		int p = upper_bound(a, a + n, m) - a - 1;
		printf("Case #%d:\n", kase + 1);
		if (p < 0)
		{
			printf("madan!\n");
		}
		else
		{
			long long c = a[p];
			int t = k;
			bool flag = true;
			for (int i = p; i < n - 1; )
			{
				long long rb = c + t;
				int next = upper_bound(a, a + n, rb) - a - 1;
				if (next <= i)
				{
					flag = false;
					break;
				}
				i = next;
				c = a[i];
				if (t)
				{
					t--;
				}
			}
			if (flag)
			{
				printf("why am I so diao?\n");
			}
			else
			{
				printf("madan!\n");
			}
		}
	}
	return 0;
}
