#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double pi = acos(-1);
const double eps = 1e-10;
inline int dcmp(double x)
{
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

struct Point
{
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

typedef Point Vector;

Vector operator - (const Point& A, const Point& B)
{
    return Vector(A.x - B.x, A.y - B.y);
}

inline double Cross(const Vector& A, const Vector& B)
{
    return A.x * B.y - A.y * B.x;
}

inline double Dot(const Vector& A, const Vector& B)
{
    return A.x * B.x + A.y * B.y;
}

bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{
    double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
            c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
    return (dcmp(c1) ^ dcmp(c2)) == -2 && (dcmp(c3) ^ dcmp(c4)) == -2;
}

bool OnSegment(Point p, Point a1, Point a2)
{
    return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}

int n;
double s;
Point p[1000];
double w[1000];
double dp[1000];

bool out(int i, int j)
{
    Vector v1 = p[j] - p[i],
            v2 = p[(i - 1 + n) % n] - p[i],
            v3 = p[(i + 1) % n] - p[i];
    if (s > 0)
    {
        double deg3 = atan2(v3.y, v3.x) + pi * 2;
        double deg2 = atan2(v2.y, v2.x) - pi * 2;
        while (dcmp(deg2 - deg3) < 0)
            deg2 += pi * 2;
        double deg1 = atan2(v1.y, v1.x) - pi * 2;
        while (dcmp(deg1 - deg3) < 0)
            deg1 += pi * 2;
        return dcmp(deg1 - deg2) <= 0;
    }
    else
    {
        double deg3 = atan2(v2.y, v2.x) + pi * 2;
        double deg2 = atan2(v3.y, v3.x) - pi * 2;
        while (dcmp(deg2 - deg3) < 0)
            deg2 += pi * 2;
        double deg1 = atan2(v1.y, v1.x) - pi * 2;
        while (dcmp(deg1 - deg3) < 0)
            deg1 += pi * 2;
        return dcmp(deg1 - deg2) <= 0;
    }
}

bool can(int i, int j)
{
    if (!out(i, j) || !out(j, i))
        return false;
    for (int k = 0; k < n; ++k)
    {
        if (SegmentProperIntersection(p[k], p[(k + 1) % n], p[i], p[j]))
            return false;
    }
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int kase = 1; T--; ++kase)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%lf %lf %lf", &p[i].x, &p[i].y, w + i);
        }
        s = 0;
        for (int i = 0; i < n; ++i)
        {
            s -= Cross(p[i], p[(i + 1) % n]);
        }
        double ans = dp[0] = w[0];
        for (int i = 1; i < n; ++i)
        {
            dp[i] = -1e18;
            for (int j = 0; j < i; ++j)
            {
                if (can(i, j))
                {
                    dp[i] = max(dp[i], dp[j] + w[i]
                                - hypot(p[i].x - p[j].x, p[i].y - p[j].y));
                    ans = max(ans, dp[i]);
                }
            }
        }
        printf("Case #%d: %.10f\n", kase, ans);
    }
    return 0;
}