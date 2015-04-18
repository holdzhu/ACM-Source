#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		long long x[4], y[4], z[4];
		for (int i = 0; i < 4; ++i)
		{
			scanf("%I64d", &x[i]);
			scanf("%I64d", &y[i]);
			scanf("%I64d", &z[i]);
		}
		long long dx[3], dy[3], dz[3];
		for (int i = 0; i < 3; ++i)
		{
			dx[i] = x[3] - x[i];
			dy[i] = y[3] - y[i];
			dz[i] = z[3] - z[i];
		}
		printf("Case #%d: ", kase);
		if (dx[0] * dy[1] * dz[2] + dx[1] * dy[2] * dz[0] + dx[2] * dy[0] * dz[1] - dx[0] * dy[2] * dz[1] - dx[2] * dy[1] * dz[0] - dx[1] * dy[0] * dz[2] == 0)
		{
			long long d[3];
			for (int i = 0; i < 3; ++i)
			{
				d[i] = dx[i] * dx[i] + dy[i] * dy[i] + dz[i] * dz[i];
			}
			if (d[0] != d[1] && d[1] == d[2])
			{
				swap(d[0], d[2]);
				swap(dx[0], dx[2]);
				swap(dy[0], dy[2]);
				swap(dz[0], dz[2]);
				swap(x[0], x[2]);
				swap(y[0], y[2]);
				swap(z[0], z[2]);
			}
			else if (d[0] != d[1] && d[0] == d[2])
			{
				swap(d[1], d[2]);
				swap(dx[1], dx[2]);
				swap(dy[1], dy[2]);
				swap(dz[1], dz[2]);
				swap(x[1], x[2]);
				swap(y[1], y[2]);
				swap(z[1], z[2]);
			}
			if (d[0] != d[1])
			{
				printf("No\n");
			}
			else
			{
				if (dx[0] * dx[1] + dy[0] * dy[1] + dz[0] * dz[1] != 0)
				{
					printf("No\n");
				}
				else
				{
					int px = x[0] + x[1] - x[3];
					int py = y[0] + y[1] - y[3];
					int pz = z[0] + z[1] - z[3];
					if (px == x[2] && py == y[2] && pz == z[2])
					{
						printf("Yes\n");
					}
					else
					{
						printf("No\n");
					}
				}
			}
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
