#include <cstdio>

int n, m;
int a[100000];
int bit[100000];

int lowbit(int x)
{
	x++;
	return x & (-x);
}

void build()
{
	for (int i = 0; i < n; ++i)
	{
		bit[i] = a[i];
		for (int j = i - 1; j > i - lowbit(i); j -= lowbit(j))
		{
			bit[i] += bit[j];
		}
	}
}

void edit(int i, int delta)
{
	for (int j = i; j < n; j += lowbit(j))
	{
		bit[j] += delta;
	}
}

int sum(int k)
{
	int ans = 0;
	for (int i = k; i >= 0; i -= lowbit(i))
	{
		ans += bit[i];
	}
	return ans;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	build();
	int a, b, c;
	while (m--)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a)
		{
			edit(b - 1, c);
		}
		else
		{
			printf("%d\n", sum(c - 1) - sum(b - 2));
		}
	}
	return 0;
}
