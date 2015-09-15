#include <cstdio>
#include <cstring>

int d[50001];
int w[50001];

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		memset(d, 0, sizeof d);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &w[i]);
		}
		for (int i = 0; i < m; ++i)
		{
			int l, r;
			scanf("%d %d", &l, &r);
			d[l - 1]++;
			d[r]--;
		}
		unsigned long long p = 0;
		for (int i = 0; i < n; ++i)
		{
			d[i + 1] += d[i];
			p += d[i] * (d[i] - 1) * (d[i] - 2) / 6 * w[i];
		}
		unsigned long long q = m * (m - 1) * (m - 2) / 6;
		if (q == 0)
		{
			printf("0\n");
		}
		else
		{
			unsigned long long g = gcd(p, q);
			p /= g;
			q /= g;
			if (q == 1)
			{
				printf("%I64u\n", p);
			}
			else
			{
				printf("%I64u/%I64u\n", p, q);
			}
		}
	}
	return 0;
}
