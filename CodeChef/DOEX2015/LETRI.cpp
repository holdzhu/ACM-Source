#include <cstdio>

const int maxn = 1000020;

long long phi[maxn];

void phi_table(int n)
{
	for (int i = 2; i <= n; ++i)
	{
		phi[i] = 0;
	}
	phi[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (!phi[i])
		{
			for (int j = i; j <= n; j += i)
			{
				if (!phi[j])
				{
					phi[j] = j;
				}
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}

int pow9(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}
	if (b == 1)
	{
		return a % 9;
	}
	int s = pow9(a, b / 2);
	s = (s * s) % 9;
	if (b % 2 == 1)
	{
		s = (s * a) % 9;
	}
	return s;
}

int main()
{
	phi_table(maxn - 1);
	for (int i = 1; i < maxn; ++i)
	{
		phi[i] += phi[i - 1];
	}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int A, B, C, P;
		scanf("%d %d %d %d", &A, &B, &C, &P);
		P += (pow9(A % 9, B % 9) + 8) % 9 + 1;
		printf("%lld\n", phi[P / C]);
	}
	return 0;
}
