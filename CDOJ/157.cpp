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
		n = (int)sqrt(n);
		n *= n;
		printf("%d\n", n);
	}
	return 0;
}
