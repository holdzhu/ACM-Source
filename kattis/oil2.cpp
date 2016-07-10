#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int x0[2000], x1[2000], y[2000];

struct Point
{
	int x, y, q;
	Point(int x = 0, int y = 0) : x(x), y(y)
	{
		if (x > 0 && y >= 0)
			q = 0;
		else if (x <= 0 && y > 0)
			q = 1;
		else if (x < 0 && y <= 0)
			q = 2;
		else
			q = 3;
	}
	bool operator<(const Point &rhs) const
	{
		return q < rhs.q ||
			   (q == rhs.q && 1ll * x * rhs.y - 1ll * y * rhs.x > 0);
	}
};

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d %d", &x0[i], &x1[i], &y[i]);
	long long ans = 0;
	for (int i = 0; i < n; ++i)
		for (int rot = 0; rot < 2; ++rot, swap(x0[i], x1[i]))
		{
			for (int j = 0; j < n; ++j)
				if (y[i] != y[j])
				{
					
				}
		}
	return 0;
}
