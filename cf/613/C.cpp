#include <cstdio>

int a[26];

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int n;
	scanf("%d", &n);
	int sum = 0;
	int odd = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		if (a[i] % 2 == 1)
		{
			odd++;
		}
		sum += a[i];
	}
	if (odd == 1)
	{
		int idx = -1;
		for (int i = 0; i < n; ++i)
		{
			if (a[i] % 2 == 1)
			{
				idx = i;
				break;
			}
		}
		int g = 0;
		for (int i = 0; i < n; ++i)
		{
			if (i != idx)
			{
				g = gcd(g, a[i] / 2);
			}
			else
			{
				g = gcd(g, a[i]);
			}
		}
		printf("%d\n", g);
		for (int i = 0; i < g; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (j != idx)
				{
					for (int k = 0; k < a[j] / (g * 2); ++k)
					{
						putchar(j + 'a');
					}
				}
				else
				{
					for (int k = 0; k < (a[j] / g - 1) / 2; ++k)
					{
						putchar(j + 'a');
					}
				}
			}
			putchar(idx + 'a');
			for (int j = n - 1; j >= 0; --j)
			{
				if (j != idx)
				{
					for (int k = 0; k < a[j] / (g * 2); ++k)
					{
						putchar(j + 'a');
					}
				}
				else
				{
					for (int k = 0; k < (a[j] / g - 1) / 2; ++k)
					{
						putchar(j + 'a');
					}
				}
			}
		}
		puts("");
	}
	else if (odd > 1)
	{
		printf("0\n");
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < a[i]; ++j)
			{
				putchar(i + 'a');
			}
		}
		puts("");
	}
	else
	{
		int g = 0;
		for (int i = 0; i < n; ++i)
		{
			g = gcd(g, a[i]);
		}
		printf("%d\n", g);
		for (int i = 0; i < g / 2; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				for (int k = 0; k < a[j] / g; ++k)
					putchar('a' + j);
			}
			for (int j = n - 1; j >= 0; --j)
			{
				for (int k = 0; k < a[j] / g; ++k)
					putchar('a' + j);
			}
		}
		puts("");
	}
	return 0;
}
