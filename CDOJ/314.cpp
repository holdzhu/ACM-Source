#include <cstdio>

int p[100000];

int find(int x)
{
	return p[x] == x ? x : p[x] = find(p[x]);
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	bool B = true;
	for (int i = 0; i < n; ++i)
	{
		p[i] = i;
	}
	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
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
	if (B)
	{
		int t = find(0);
		for (int i = 1; i < n; ++i)
		{
			if (find(i) != t)
			{
				B = false;
			}
		}
	}
	if (B)
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
	return 0;
}
