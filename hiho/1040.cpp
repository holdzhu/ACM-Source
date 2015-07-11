#include <cstdio>

long long dis2(long long dx, long long dy)
{
	return dx * dx + dy * dy;
}

bool solve()
{
	long long line[4][2][2];
	double center[2] = {0, 0};
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				scanf("%lld", &line[i][j][k]);
				center[k] += line[i][j][k];
			}
		}
	}
	center[0] /= 8;
	center[1] /= 8;
	long long diag = dis2(line[0][0][0] - center[0], line[0][0][1] - center[1]);
	for (int i = 0; i < 4; ++i)
	{
		long long diag1 = dis2(line[i][0][0] - center[0], line[i][0][1] - center[1]);
		long long diag2 = dis2(line[i][1][0] - center[0], line[i][1][1] - center[1]);
		if (diag != diag1 || diag != diag2)
		{
			return false;
		}
		if ((line[i][0][0] - center[0]) * (line[i][1][0] - center[0]) != (line[i][0][1] - center[1]) * (line[i][1][1] - center[1]))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		if (solve())
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
