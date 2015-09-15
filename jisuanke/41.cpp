#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[25];
int b[15][25];
int tmp[25];

int main()
{
	int f;
	scanf("%d", &f);
	for (int i = 0; i < f; ++i)
	{
		scanf("%d", &a[i]);
	}
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		for (int j = 0; j < f; ++j)
		{
			scanf("%d", &b[i][j]);
		}
	}
	int ans = (1 << t) - 1;
	for (int i = 1; i < (1 << t) - 1; ++i)
	{
		if (__builtin_popcount(ans) < __builtin_popcount(i))
		{
			continue;
		}
		memset(tmp, 0, sizeof tmp);
		for (int j = 0; j < t; ++j)
		{
			if (i & (1 << j))
			{
				for (int k = 0; k < f; ++k)
				{
					tmp[k] += b[j][k];
				}
			}
		}
		bool flag = true;
		for (int j = 0; j < f; ++j)
		{
			if (tmp[j] < a[j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			if (__builtin_popcount(ans) == __builtin_popcount(i))
			{
				int p1 = 0;
				int p2 = 0;
				while (1)
				{
					while (!(ans & (1 << p1++)));
					while (!(i & (1 << p2++)));
					if (p1 < p2)
					{
						flag = false;
						break;
					}
					if (p1 > p2)
					{
						break;
					}
				}
				if (flag)
				{
					ans = i;
				}
			}
			else
			{
				ans = i;
			}
		}
	}
	printf("%d", __builtin_popcount(ans));
	for (int i = 0; i < t; ++i)
	{
		if (ans & (1 << i))
		{
			printf(" %d", i + 1);
		}
	}
	puts("");
	return 0;
}
