#include <cstdio>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int mx = 0;
	for (int i = 0; i < n; ++i)
	{
		int mi = 1e9;
		for (int j = 0; j < m; ++j)
		{
			int t;
			scanf("%d", &t);
			if (mi > t)
				mi = t;
		}
		if (mx < mi)
			mx = mi;
	}
	printf("%d\n", mx);
	return 0;
}
