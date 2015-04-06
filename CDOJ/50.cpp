#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		int a[N], b[N - 1];
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < N - 1; ++i)
		{
			scanf("%d", &b[i]);
		}
		float minl = a[0] + b[0], maxl = a[0] + b[0] + a[1];
		long long t = a[0] + b[0] + a[1];
		bool B = true;
		for (int i = 2; i < N; ++i)
		{
			t += b[i - 1];
			if (t > maxl * i)
			{
				B = false;
				break;
			}
			if (t > minl * i)
			{
				minl = t * 1.0 / i;
			}
			t += a[i];
			if (t < minl * i)
			{
				B = false;
				break;
			}
			if (t < maxl * i)
			{
				maxl = t * 1.0 / i;
			}
		}
		if (B)
		{
			printf("%.2f\n", minl);
		}
		else
		{
			printf("impossible\n");
		}
	}
	return 0;
}
