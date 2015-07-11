#include <cstdio>
#include <cmath>

const double pi = acos(-1);

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; ++kase)
	{
		int n;
		double a, r;
		scanf("%d %lf %lf", &n, &a, &r);
		printf("Case #%d:\n", kase + 1);
		if (r <= a / 2 / tan(pi / n))
		{
			printf("Give me a kiss!\n");
		}
		else
		{
			printf("I want to kiss you!\n");
		}
	}
	return 0;
}
