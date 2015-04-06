#include <cstdio>
#include <cstring>

int P[121];

int main()
{
	int N;
	memset(P, 0, sizeof(P));
	P[0] = 1;
	for (int i = 1; i <= 120; ++i)
	{
		for (int j = i; j <= 120; ++j)
		{
			P[j] += P[j - i];
		}
	}
	while (scanf("%d", &N) == 1)
	{
		printf("%d\n", P[N]);
	}
	return 0;
}
