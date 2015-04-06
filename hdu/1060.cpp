#include <cstdio>
#include <cmath>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		double t = N * log10(N);
		printf("%d\n", (int)pow(10, t - floor(t)));
	}
	return 0;
}
