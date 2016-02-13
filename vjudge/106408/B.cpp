#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	if (!n)
		return puts("0");
	double ans = 1;
	int l = 2, r = 2;
	while (--n)
	{
		ans += l * r;
		if (l < r)
			++l;
		else
			++r;
	}
	printf("%.3f\n", ans);
	return 0;
}
