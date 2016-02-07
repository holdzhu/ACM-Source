#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	if (b > a)
	{
		printf("-1\n");
	}
	else if (a == b)
	{
		printf("%d\n", a);
	}
	else
	{
		double t1 = (a + b) / 2.0;
		double t2 = (a - b) / 2.0;
		double ans = 1e23;
		ans = min(ans, t1 / floor(t1 / b));
		if (t2 >= b)
		{
			ans = min(ans, t2 / floor(t2 / b));
		}
		printf("%.10f\n", ans);
	}
	return 0;
}
