#include <cstdio>
#include <cstring>

long long f[1000000];

int main()
{
	int start, stop, badness;
	int Test = 1;
	memset(f, 0, sizeof f);
	for (int i = 2; i < 1000000; ++i)
	{
		for (int j = i * 2; j < 1000000; j += i)
		{
			f[j] += i;
		}
	}
	for (int i = 2; i < 1000000; ++i)
	{
		f[i] += 1 - i;
		if (f[i] < 0)
		{
			f[i] = -f[i];
		}
	}
	while (scanf("%d %d %d", &start, &stop, &badness) == 3 && start)
	{
		int ans = 0;
		for (int i = start; i <= stop; ++i)
		{
			if (f[i] <= badness)
			{
				ans++;
			}
		}
		printf("Test %d: %d\n", Test++, ans);
	}
	return 0;
}
