#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int M, N;
	while (scanf("%d %d", &M, &N) == 2)
	{
		int hm = (int)sqrt(M - 1);
		int hn = (int)sqrt(N - 1);
		if (hm == hn)
		{
			printf("%d\n", abs(M - N));
		}
		else
		{
			int x1 = (M - hm * hm - 1) / 2;
			int x2 = (N - hn * hn - 1) / 2;
			int y1 = ((hm + 1) * (hm + 1) - M) / 2;
			int y2 = ((hn + 1) * (hn + 1) - N) / 2;
			int ans = 0;
			if (x1 > x2 && y1 < y2)
			{
				ans = min(x1 - x2, y2 - y1);
				x2 += ans;
				y1 += ans;
				ans *= 2;
			}
			else if (x1 < x2 && y1 > y2)
			{
				ans = min(x2 - x1, y1 - y2);
				x1 += ans;
				y2 += ans;
				ans *= 2;
			}
			ans += (abs(x1 - x2) + abs(y1 - y2)) * 2;
			if (hm < hn)
			{
				printf("%d\n", ans + (hm + M) % 2 - (hn + N) % 2);
			}
			else
			{
				printf("%d\n", ans - (hm + M) % 2 + (hn + N) % 2);
			}
		}
	}
	return 0;
}
