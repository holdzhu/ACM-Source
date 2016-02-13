#include <cstdio>
#include <cmath>

const double eps = 1e-10;
const double pi = acos(-1);
double a[100000];
bool win[100000];

int main()
{
	freopen("race.in", "r", stdin);
	freopen("race.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lf", &a[i]);
	double mi = 1e9;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > pi / 2 && mi + eps > a[i] - pi / 2)
			win[i] = 1;
		mi = fmin(mi, fabs(a[i] - pi / 2));
	}
	mi = 1e9;
	for (int i = n - 1; i >= 0; --i)
	{
		if (a[i] < pi / 2 && mi + eps > pi / 2 - a[i])
			win[i] = 1;
		mi = fmin(mi, fabs(a[i] - pi / 2));
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		cnt += win[i];
	printf("%d\n", cnt);
	for (int i = 0; i < n && cnt; ++i)
	{
		if (win[i])
		{
			printf("%d", i + 1);
			if (--cnt)
				putchar(' ');
		}
	}
	puts("");
	return 0;
}