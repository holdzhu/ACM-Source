#include <cstdio>

int main()
{
	int A, B, n;
	while (scanf("%d %d %d", &A, &B, &n) == 3 && (A || B || n))
	{
		int f[50];
		f[0] = 8;
		for (int i = 1; i < 50; ++i)
		{
			f[i] = (B * (f[i - 1] / 7) + A * (f[i - 1] % 7)) % 7 + (f[i - 1] % 7) * 7;
		}
		if (n <= 50)
		{
			printf("%d\n", f[n - 1] / 7);
		}
		else
		{
			int ans = -1;
			for (int i = 0; i < 49 && ans == -1; ++i)
			{
				for (int j = i + 1; j < 50 && ans == -1; ++j)
				{
					if (f[i] == f[j])
					{
						ans = f[(n - 1 - i) % (j - i) + i] / 7;
					}
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
