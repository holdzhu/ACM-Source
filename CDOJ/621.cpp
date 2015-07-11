#include <cstdio>
#include <cstring>

int phi[1000001];
long long S[1000001], f[1000001];
void phi_table(int n)
{
	memset(phi, 0, sizeof phi);
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

int main()
{
	phi_table(1000000);
	memset(f, 0, sizeof f);
	for (int i = 1; i <= 1000000; ++i)
	{
		for (int j = i * 2; j <= 1000000; j += i)
		{
			f[j] += i * phi[j / i];
		}
	}
	S[0] = S[1] = 0;
	for (int i = 2; i <= 1000000; ++i)
	{
		S[i] = S[i - 1] + f[i];
	}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		printf("%lld\n", S[N]);
	}
	return 0;
}
