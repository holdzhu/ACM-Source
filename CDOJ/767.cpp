#include <cstdio>
#include <cstring>

int main()
{
	int N;
	scanf("%d", &N);
	int a[10000];
	memset(a, 0, sizeof(a));
	while (N--)
	{
		int t;
		scanf("%d", &t);
		a[t]++;
	}
	for (int i = 0; i < 10000; ++i)
	{
		if (a[i] == 1)
		{
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
