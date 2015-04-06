#include <cstdio>

void solve(int k)
{
	for (int a = 0; a < 65; ++a)
	{
		int x = 1;
		for ( ; x < 65; ++x)
		{
			int fa = 5;
			for (int i = 0; i < 13; ++i)
			{
				fa *= x;
				fa %= 65;
			}
			int fb = 13;
			for (int i = 0; i < 5; ++i)
			{
				fb *= x;
				fb %= 65;
			}
			if ((fa + fb + k * a * x) % 65)
			{
				break;
			}
		}
		if (x == 65)
		{
			printf("%d\n", a);
			return;
		}
	}
	printf("no\n");
	return;
}

int main()
{
	int k;
	while (scanf("%d", &k) == 1)
	{
		solve(k);
	}
	return 0;
}
