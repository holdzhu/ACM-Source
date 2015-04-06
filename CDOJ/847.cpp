#include <cstdio>

int main()
{
	int N;
	scanf("%d", &N);
	int a[N], b[N];
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &b[i]);
	}
	int s[N];
	int poss = 0;
	int posb = 0;
	for (int i = 0; i < N; ++i)
	{
		if (a[i] == b[posb])
		{
			posb++;
			while (poss && s[poss - 1] == b[posb])
			{
				poss--;
				posb++;
			}
		}
		else
		{
			s[poss++] = a[i];
		}
	}
	if (posb == N)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}
