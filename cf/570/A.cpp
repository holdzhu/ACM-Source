#include <cstdio>

int cnt[100];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int mx = -1;
		int mxi = 0;
		for (int j = 0; j < n; ++j)
		{
			int t;
			scanf("%d", &t);
			if (t > mx)
			{
				mx = t;
				mxi = j;
			}
		}
		cnt[mxi]++;
	}
	int mx = -1;
	int mxi = 0;
	for (int i = 0; i < n; ++i)
	{
		if (cnt[i] > mx)
		{
			mx = cnt[i];
			mxi = i;
		}
	}
	printf("%d\n", mxi + 1);
	return 0;
}
