#include <cstdio>
#include <cstdlib>

int main()
{
	int N, C = 1;
	while (scanf("%d", &N) == 1 && N)
	{
		int a[N];
		bool b;
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 0; i <= 1000; ++i)
		{
			b = true;
			for (int i = 1; i < N; ++i)
			{
				if (a[i] != a[0])
				{
					b = false;
					break;
				}
			}
			if (b)
			{
				printf("Case %d: %d iterations\n", C, i);
				break;
			}
			int t = a[0];
			for (int i = 0; i < N - 1; ++i)
			{
				a[i] = abs(a[i + 1] - a[i]);
			}
			a[N - 1] = abs(a[N - 1] - t);
		}
		if (!b)
		{
			printf("Case %d: not attained\n", C);
		}
		C++;
	}
	return 0;
}
