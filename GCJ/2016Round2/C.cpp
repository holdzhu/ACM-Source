#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> p[100];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int R, C;
		scanf("%d %d", &R, &C);
		for (int i = 0; i < R + C; ++i)
		{
			scanf("%d %d", &p[i].first, &p[i].second);
			--p[i].first;
			--p[i].second;
			if (p[i].first > p[i].second)
				swap(p[i].first, p[i].second);
		}
		printf("Case #%d:\n", kase);
		bool flag = true;
		for (int i = 0; i < R + C; ++i)
			for (int j = i + 1; j < R + C; ++j)
			{
				bool b1 = p[j].first > p[i].first && p[j].first < p[i].second;
				bool b2 = p[j].second > p[i].first && p[j].second < p[i].second;
				if (b1 ^ b2)
					flag = false;
			}
		if (!flag)
		{
			puts("IMPOSSIBLE");
			continue;
		}
	}
	return 0;
}
