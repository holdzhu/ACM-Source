#include <cstdio>
#include <cmath>

int W, H, N;
int x[500], y[500], p[502];

int findset(int x)
{
	return x == p[x] ? x : p[x] = findset(p[x]);
}

int main()
{
	scanf("%d %d %d", &W, &H, &N);
	for (int i = 0; i < N; ++i)
		scanf("%d %d", &x[i], &y[i]);
	double L = 0;
	double R = 2e9;
	while (R - L > 1e-4)
	{
		double M = (L + R) / 2;
		for (int i = 0; i < N + 2; ++i)
			p[i] = i;
		for (int i = 0; i < N; ++i)
		{
			if (x[i] <= M)
				p[findset(i)] = N;
			if (x[i] >= W - M)
				p[findset(i)] = N + 1;
		}
		for (int i = 0; i < N; ++i)
			for (int j = i + 1; j < N; ++j)
				if (hypot(x[i] - x[j], y[i] - y[j]) <= 2 * M)
					p[findset(i)] = findset(j);
		if (findset(N) == findset(N + 1))
			R = M;
		else
			L = M;
	}
	printf("%.3f\n", (L + R) / 2);
	return 0;
}
