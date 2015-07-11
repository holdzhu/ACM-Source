#include <cstdio>
#include <algorithm>

using namespace std;

double R[100], C[100];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; ++kase)
	{
		int N;
		scanf("%d", &N);
		double V, X;
		scanf("%lf %lf", &V, &X);
		for (int i = 0; i < N; ++i)
		{
			scanf("%lf %lf", &R[i], &C[i]);
		}
		printf("Case #%d: ", kase + 1);
		if (N == 1)
		{
			if (C[0] != X)
			{
				printf("IMPOSSIBLE\n");
			}
			else
			{
				printf("%.8f\n", V / R[0]);
			}
		}
		else if (N == 2)
		{
			if (C[0] == C[1])
			{
				if (C[0] != X)
				{
					printf("IMPOSSIBLE\n");
				}
				else
				{
					printf("%.11f\n", V / (R[0] + R[1]));
				}
			}
			else
			{
				if (X < min(C[0], C[1]) || X > max(C[0], C[1]))
				{
					printf("IMPOSSIBLE\n");
				}
				else if (X == C[0])
				{
					printf("%.11f\n", V / R[0]);
				}
				else if (X == C[1])
				{
					printf("%.11f\n", V / R[1]);
				}
				else
				{
					double t0 = (C[1] - X) / (C[1] - C[0]) * (V / R[0]);
					double t1 = (C[0] - X) / (C[0] - C[1]) * (V / R[1]);
					printf("%.11f\n", max(t0, t1));
				}
			}
		}
	}
	return 0;
}
