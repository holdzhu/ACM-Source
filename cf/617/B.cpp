#include <cstdio>

int main()
{
	long long ans = 1;
	int n;
	scanf("%d", &n);
	int last = -1;
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			if (last != -1)
			{
				ans *= i - last;
			}
			last = i;
		}
	}
	printf("%I64d\n", last == -1 ? 0 : ans);
	return 0;
}
