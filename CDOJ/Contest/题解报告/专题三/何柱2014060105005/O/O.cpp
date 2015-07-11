#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Chest
{
	int x, y, a, b, c;
};

struct Key
{
	int b, c;
	bool operator < (const Key& rhs) const
	{
		return c < rhs.c;
	}
};

Chest chest[15];
Key mask[1 << 15][161];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d %d %d", &chest[i].x, &chest[i].y, &chest[i].a, &chest[i].b, &chest[i].c);
	}
	memset(mask, -1, sizeof mask);
	int t;
	scanf("%d", &t);
	scanf("%d %d", &mask[0][t].b, &mask[0][t].c);
	int ans = t + mask[0][t].b + mask[0][t].c;
	for (int i = 1; i < 1 << n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))
			{
				Key *tmp = mask[i ^ (1 << j)];
				for (int k = 0; k <= (n + 1) * 10; ++k)
				{
					int usec = 0;
					if (k < chest[j].x)
					{
						usec += chest[j].x - k;
					}
					if (tmp[k].b < chest[j].y)
					{
						usec += chest[j].y - tmp[k].b;
					}
					if (usec <= tmp[k].c)
					{
						int a = max(0, k - chest[j].x) + chest[j].a;
						int b = max(0, tmp[k].b - chest[j].y) + chest[j].b;
						int c = tmp[k].c - usec + chest[j].c;
						mask[i][a] = max(mask[i][a], (Key){b, c});
						ans = max(ans, a + b + c);
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
