#include <cstdio>
#include <cstring>

int main()
{
	int h1[21], h2[21];
	int n, m;
	while (scanf("%d %d", &n, &m) == 2 && n && m)
	{
		memset(h1, 0, sizeof(h1));
		memset(h2, 0, sizeof(h2));
		while (n--)
		{
			int t;
			scanf("%d", &t);
			h1[t]++;
		}
		while (m--)
		{
			int t;
			scanf("%d", &t);
			h2[t]++;
		}
		int s = 0;
		for (int i = 1; i <= 20; ++i)
		{
			if (h1[i] > h2[i])
			{
				s += h1[i] * i;
			}
			else
			{
				s += h2[i] * i;
			}
		}
		printf("%d\n", s);
	}
	return 0;
}
