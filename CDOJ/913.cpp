#include <cstdio>
#include <algorithm>

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int d[n];
		int s = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &d[i]);
			s += d[i];
		}
		if (s % 2)
		{
			printf("NO\n");
		}
		else
		{
			for (int i = 0; i < n - 1; ++i)
			{
				std::sort(d + i, d + n, cmp);
				for (int j = i + 1; j < n; ++j)
				{
					if (d[i] && d[j])
					{
						d[i]--;
						d[j]--;
						s -= 2;
					}
				}
				if (d[i])
				{
					break;
				}
			}
			if (s)
			{
				printf("NO\n");
			}
			else
			{
				printf("YES\n");
			}	
		}
	}
	return 0;
}
