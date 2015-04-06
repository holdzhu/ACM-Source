#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct Trinum
{
	int a, b, c;
};

Trinum gougu[1892];

int main()
{
	int ca = 0;
	for (int j = 1; j <= 1000; ++j)
	{
		for (int i = j + 1; i <= 1000; ++i)
		{
			int c = (int)(sqrt(i * i + j * j) + 0.5);
			if (c <= 1000 && c * c == i * i + j * j)
			{
				gougu[ca++] = (Trinum) {i, j, c};
			}
		}
	}
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int H, W;
		scanf("%d %d", &H, &W);
		if (H < W)
		{
			swap(H, W);
		}
		long long ans = 0;
		for (int i = 1; i <= min(W / 2, H / 4); ++i)
		{
			for (int j = i; i + j <= H / 2 && j <= W / 2; ++j)
			{
				long long t = (H - (i * 2 + j * 2) + 1) * (W - (j * 2) + 1);
				if (W >= (i * 2 + j * 2))
				{
					t += (W - (i * 2 + j * 2) + 1) * (H - (j * 2) + 1);
				}
				if (i != j)
				{
					t *= 2;
				}
				ans += t;
			}
		}
		for (int i = 0; i < ca; ++i)
		{
			for (int j = 1; j <= gougu[i].c - 1; ++j)
			{
				int dH = max(j, gougu[i].b + gougu[i].c - j) + max(j, gougu[i].c - j - gougu[i].b);
				int dW = max(gougu[i].c - j, gougu[i].a + j) + max(j - gougu[i].a, gougu[i].c - j);
				if (dH < dW)
				{
					swap(dH, dW);
				}
				if (dH <= H && dW <= W)
				{
					ans += (H - dH + 1) * (W - dW + 1) * 2;
					if (dH <= W)
					{
						ans += (W - dH + 1) * (H - dW + 1) * 2;
					}
				}
			}
		}
		printf("Case %d: %lld\n", kase, ans);
	}
	return 0;
}
