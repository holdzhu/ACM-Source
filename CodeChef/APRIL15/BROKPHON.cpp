#include <cstdio>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		bool a[N];
		memset(a, 0, sizeof a);
		int last;
		scanf("%d", &last);
		for (int i = 1; i < N; ++i)
		{
			int t;
			scanf("%d", &t);
			if (t != last)
			{
				a[i - 1] = a[i] = true;
			}
			last = t;
		}
		int c = 0;
		for (int i = 0; i < N; ++i)
		{
			if (a[i])
			{
				c++;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}
