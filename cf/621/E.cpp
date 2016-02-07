#include <cstdio>

const int mod = 1e9 + 7;

int x;
int cnt[10];
int a[100][100];
int s[100][100];
int tmp[100][100];

void mul(int a[100][100], int b[100][100])
{
	for (int i = 0; i < x; ++i)
		for (int j = 0; j < x; ++j)
		{
			tmp[i][j] = 0;
			for (int k = 0; k < x; ++k)
				tmp[i][j] = (tmp[i][j] + 1ll * a[i][k] * b[k][j]) % mod;
		}
	for (int i = 0; i < x; ++i)
		for (int j = 0; j < x; ++j)
			a[i][j] = tmp[i][j];
}

int main()
{
	int n, b, k;
	scanf("%d %d %d %d", &n, &b, &k, &x);
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		cnt[t]++;
	}
	for (int i = 0; i < x; ++i)
		for (int j = 0; j < x; ++j)
			s[i][j] = i == j;
	for (int i = 0; i < x; ++i)
		for (int j = 1; j <= 9; ++j)
			a[i][(i * 10 + j) % x] += cnt[j];
	while (b)
	{
		if (b & 1)
			mul(s, a);
		mul(a, a);
		b >>= 1;
	}
	printf("%d\n", s[0][k]);
	return 0;
}
