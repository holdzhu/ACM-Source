#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Point
{
	double x, y;
	int id;
	Point(double x = 0, double y = 0): x(x), y(y) {}
	bool operator < (const Point& rhs) const
	{
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}
};

Point tmp[100];
Point tmp2[100];
Point tmp3[100];

int pos;
int N, M, G, P;
Point tower[100];
Point city[100];
int ans;

Point operator - (Point A, Point B)
{
    return Point(A.x - B.x, A.y - B.y);
}

double Cross(Point A, Point B)
{
    return A.x * B.y - A.y * B.x;
}

int ConvexHull(Point* p, int n, Point* ch)
{
	sort(p, p + n);
	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) < 0)
		{
			m--;
		}
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; --i)
	{
		while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) < 0)
		{
			m--;
		}
		ch[m++] = p[i];
	}
	if (n > 1)
	{
		m--;
	}
	return m;
}

int isPointInPolygon(Point p, Point* poly, int n)
{
	int wn = 0;
	for (int i = 0; i < n; ++i)
	{
		int k = Cross(poly[(i + 1) % n] - poly[i], p - poly[i]);
		int d1 = poly[i].y - p.y;
		int d2 = poly[(i + 1) % n].y - p.y;
		if (k > 0 && d1 <= 0 && d2 > 0)
		{
			wn++;
		}
		if (k < 0 && d2 <= 0 && d1 > 0)
		{
			wn--;
		}
	}
	if (wn != 0)
	{
		return 1;
	}
	return 0;
}

void dfs(int de)
{
	if (de == N)
	{
		for (int i = 0; i < pos; ++i)
		{
			tmp2[i] = tmp[i];
		}
		int m = ConvexHull(tmp2, pos, tmp3);
		int cityprotected = 0;
		for (int i = 0; i < M; ++i)
		{
			if (isPointInPolygon(city[i], tmp3, m))
			{
				cityprotected++;
			}
		}
		ans = min(ans, pos * P + (M - cityprotected) * G);
	}
	else
	{
		tmp[pos++] = tower[de];
		dfs(de + 1);
		pos--;
		dfs(de + 1);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		scanf("%d %d %d %d", &N, &M, &G, &P);
		for (int i = 0; i < N; ++i)
		{
			scanf("%lf %lf", &tower[i].x, &tower[i].y);
		}
		for (int i = 0; i < M; ++i)
		{
			scanf("%lf %lf", &city[i].x, &city[i].y);
		}
		pos = 0;
		ans = 1000000000;
		dfs(0);
		printf("Case #%d: %d\n", kase, ans);
	}
	return 0;
}
