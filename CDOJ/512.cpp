#include <cstdio>

int main()
{
	const long long mp[] = {3, 7, 31, 127, 8191, 131071, 524287, 2147483647};
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		long long n;
		scanf("%lld", &n);
		printf("Case #%d: ", i + 1);
		int p = 0;
		for ( ; p < 8; ++p)
		{
			if (mp[p] == n)
			{
				break;
			}
		}
		if (p < 8)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
