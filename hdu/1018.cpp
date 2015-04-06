#include <cstdio>
#include <cmath>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", n > 1 ? (int)ceil(log10(2 * acos(-1) * n) / 2 + n * log10(n / exp(1))) : 1);
	}
	return 0;
}
