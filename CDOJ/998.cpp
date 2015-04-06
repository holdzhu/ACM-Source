#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int v0, d;
		double a;
		scanf("%d %lf %d", &v0, &a, &d);
		printf("%.2lf %s\n", v0 / a, (v0 * v0 / a / 2 <= d) ? "Yes" : "No");
	}
	return 0;
}
