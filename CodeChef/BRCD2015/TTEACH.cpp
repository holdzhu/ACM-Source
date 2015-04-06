#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N, S;
		scanf("%d%d", &N, &S);
		int a[N];
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a + N);
		int L = 1;
		int R = (a[N - 1] - a[0]) / (S - 1);
		while (R - L > 1)
		{
			int M = (L + R) >> 1;
			int c = 1;
			int l = a[0];
			for (int i = 1; i < N; ++i)
			{
				if (a[i] - l >= M)
				{
					c++;
					l = a[i];
				}
			}
			if (c >= S)
			{
				L = M;
			}
			else
			{
				R = M;
			}
		}
		int c = 1;
		int l = a[0];
		for (int i = 1; i < N; ++i)
		{
			if (a[i] - l >= R)
			{
				c++;
				l = a[i];
			}
		}
		if (c >= S)
		{
			printf("%d\n", R);
		}
		else
		{
			printf("%d\n", L);
		}
	}
	return 0;
}
