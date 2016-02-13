#include <cstdio>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;
vector<int> G[50];
long long mat[50][50];
int n, m;

long long pow_mod(long long a, long long k)
{
	long long ret = 1;
	while (k)
	{
		if (k & 1)
		{
			ret = ret * a % mod;
		}
		a = a * a % mod;
		k >>= 1;
	}
	return ret;
}

long long tmp[50][50];
void mul(long long A[50][50], long long B[50][50])
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			tmp[i][j] = 0;
			for (int k = 0; k < n; ++k)
			{
				tmp[i][j] = (tmp[i][j] + A[i][k] * B[k][j] % mod) % mod;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			A[i][j] = tmp[i][j];
		}
	}
}

long long a[50][50];
long long s[50][50];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		G[u - 1].push_back(v - 1);
	}
	for (int i = 0; i < n; ++i)
	{
		long long p = pow_mod(G[i].size(), mod - 2);
		for (int j = 0; j < G[i].size(); ++j)
		{
			mat[i][G[i][j]] += p;
		}
	}
	int Q;
	scanf("%d", &Q);
	while (Q--)
	{
		int u, k;
		scanf("%d %d", &u, &k);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				a[i][j] = mat[i][j];
				s[i][j] = i == j;
			}
		}
		while (k)
		{
			if (k & 1)
			{
				mul(s, a);
			}
			mul(a, a);
			k >>= 1;
		}
		for (int i = 0; i < n; ++i)
		{
			printf("%d ", (int)s[u - 1][i]);
		}
		printf("\n");
	}
	return 0;
}
