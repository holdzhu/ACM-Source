#include <cstdio>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		int roll[n];
		memset(roll, 0, sizeof(roll));
		while (m--)
		{
			int l, r, type;
			scanf("%d %d %d", &l, &r, &type);
			for (int j = l - 1; j < r; ++j)
			{
				if (roll[j] == 0)
				{
					roll[j] = type;
				}
				else if (roll[j] <= 3)
				{
					if (type <= 3 && type != roll[j])
					{
						roll[j] += type + 1;
					}
					else if (type <= 6 && type + roll[j] == 7)
					{
						roll[j] = 7;
					}
					else
					{
						roll[j] = type;
					}
				}
				else if (roll[j] <= 6)
				{
					if (type <= 3 && type + roll[j] == 7)
					{
						roll[j] = 7;
					}
					else if (type > 3 && type != roll[j])
					{
						roll[j] = 7;
					}
				}
			}
		}
		printf("Case #%d:", i + 1);
		int c[8];
		memset(c, 0, sizeof(c));
		int mc = 0;
		for (int j = 0; j < n; ++j)
		{
			c[roll[j]]++;
			if (c[roll[j]] > mc && roll[j])
			{
				mc = c[roll[j]];
			}
		}
		for (int i = 1; i < 8; ++i)
		{
			if (c[i] == mc)
			{
				printf(" type%d", i);
			}
		}
		printf("\n");
	}
	return 0;
}
