#include <cstdio>

int main()
{
	int N;
	while (scanf("%d", &N) == 1 && N)
	{
		int a[2][N];
		int c = 0;
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &a[0][i]);
			c += a[0][i];
		}
		int t = 0;
		while (true)
		{
			if (c % N == 0)
			{
				bool flag = true;
				for (int i = 0; i < N; ++i)
				{
					if (a[t % 2][i] != c / N)
					{
						flag = false;
						break;
					}
				}
				if (flag)
				{
					break;
				}
			}
			for (int i = 0; i < N; ++i)
			{
				a[(t + 1) % 2][i] = a[t % 2][i] / 2 + a[t % 2][(i + 1) % N] / 2;
				if (a[(t + 1) % 2][i] % 2 == 1)
				{
					a[(t + 1) % 2][i]++;
					c++;
				}
			}
			t++;
		}
		printf("%d %d\n", t, c / N);
	}
	return 0;
}
