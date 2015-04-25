#include <cstdio>
#include <algorithm>

using namespace std;

struct Pyramid
{
	int x, y, w;
	bool operator < (const Pyramid& rhs) const
	{
		return x - y < rhs.x - rhs.y || (x - y == rhs.x - rhs.y && x < rhs.x);
	}
};

Pyramid a[1000];
bool tmp[1000];
double ans;
int N;

void dfs(int de)
{
	if (de < N)
	{
		tmp[de] = true;
		dfs(de + 1);
		tmp[de] = false;
		dfs(de + 1);
	}
	else
	{
		int lastx, lasty;
		double sumw = 0;
		lastx = -10000;
		lasty = -10000;
		double sums = 0;
		for (int i = 0; i < N; ++i)
		{
			if (tmp[i])
			{
				sumw += a[i].w;
				if (a[i].x - a[i].y > lastx + lasty)
				{
					sums += a[i].y * a[i].y;
					lastx = a[i].x;
					lasty = a[i].y;
				}
				else if (a[i].x + a[i].y > lastx + lasty)
				{
					sums += a[i].y * a[i].y - 0.25 * (lastx + lasty - a[i].x + a[i].y) * (lastx + lasty - a[i].x + a[i].y);
					lastx = a[i].x;
					lasty = a[i].y;
				}
			}
		}
		ans = max(ans, sumw - sums);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; ++kase)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].w);
		}
		sort(a, a + N);
		ans = 0;
		dfs(0);
		printf("Case #%d: %.2f\n", kase + 1, ans);
	}
	return 0;
}
