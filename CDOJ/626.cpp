#include <cstdio>

int p[10000];

int find(int x)
{
	return p[x] == x ? x : p[x] = find(p[x]);
}

int main()
{
	int N, M, S;
	while (scanf("%d %d %d", &N, &M, &S) == 3)
	{
		for (int i = 0; i < N; ++i)
		{
			p[i] = i;
		}
		bool B = true;
		while (M--)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			if (a != S && b != S && B)
			{
				a--;
				b--;
				int x = find(a);
				int y = find(b);
				if (x == y)
				{
					B = false;
				}
				else
				{
					p[x] = y;
				}
			}
		}
		if (B)
		{
			printf("I won't let you go\n");
		}
		else
		{
			printf("Don't worry.Be happy\n");
		}
	}
	return 0;
}
