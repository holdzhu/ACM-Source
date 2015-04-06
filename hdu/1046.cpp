#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; ++kase)
	{
		int m, n;
		scanf("%d %d", &m, &n);
		printf("Scenario #%d:\n", kase + 1);
		if ((m * n) % 2)
		{
			printf("%.2f\n", m * n + 0.41);	
		}	
		else
		{
			printf("%d.00\n", m * n);
		}
		printf("\n");
	}
	return 0;
}
 