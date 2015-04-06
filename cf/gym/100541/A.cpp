#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N, W;
		scanf("%d %d", &N, &W);
		int a[N];
		int maxp = 0;
		int l = 1001;
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &a[i]);
			if (a[i] < l)
			{
				l = a[i];
			}
			else if (W / l * (a[i] - l) > maxp)
			{
				maxp = W / l * (a[i] - l);
			}
		}
		printf("%d\n", maxp);
	}
	return 0;
}
