#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		double E = 0;
		for (int i = 0; i < N; ++i)
		{
			E += N * 1.0 / (i + 1);
		}
		printf("%.2lf\n", E);
	}
	return 0;
}
