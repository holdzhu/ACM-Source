#include <cstdio>
#include <cstring>

const int mod = 1e9 + 7;
const int inv2 = (mod + 1) / 2;

enum
{
	B, R, W, Y
};

long long mat[17][17];

long long tmp[17][17];
void mul(long long A[17][17], long long B[17][17])
{
	for (int i = 0; i < 17; ++i)
		for (int j = 0; j < 17; ++j)
		{
			tmp[i][j] = 0;
			for (int k = 0; k < 17; ++k)
				tmp[i][j] = (tmp[i][j] + A[i][k] * B[k][j]) % mod;
		}
	for (int i = 0; i < 17; ++i)
		for (int j = 0; j < 17; ++j)
			A[i][j] = tmp[i][j];
}

long long a[17][17];
long long s[17][17];

long long solve(int x)
{
	if (x == 0)
		return 0;
	if (x == 1)
		return 4;
	x--;
	memcpy(a, mat, sizeof a);
	for (int i = 0; i < 17; ++i)
		for (int j = 0; j < 17; ++j)
			s[i][j] = i == j;
	while (x)
	{
		if (x & 1)
			mul(s, a);
		mul(a, a);
		x >>= 1;
	}
	long long ret = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			if ((i == W && j == Y)||
				(i == Y && j == W)||
				(i == B && j == R)||
				(i == R && j == B) ||
				i == j)
			{
				// nope
			}
			else
			{
				ret = (ret + s[i * 4 + j][16]) % mod;
			}
		}
	return (ret + 4) % mod;
}

int main()
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 4; ++k)
			{
				if ((i == W && j == Y) || (j == W && k == Y) ||
					(i == Y && j == W) || (j == Y && k == W) ||
					(i == B && j == R) || (j == B && k == R) ||
					(i == R && j == B) || (j == R && k == B) ||
					i == j || j == k ||
					(i == B && j == W && k == R) ||
					(i == R && j == W && k == B))
				{
					// nope
				}
				else
				{
					mat[i * 4 + j][j * 4 + k] = 1;
				}
			}
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			if ((i == W && j == Y)||
				(i == Y && j == W)||
				(i == B && j == R)||
				(i == R && j == B) ||
				i == j)
			{
				// nope
			}
			else
			{
				mat[i * 4 + j][16] = 1;
			}
		}
	mat[16][16] = 1;
	int l, r;
	scanf("%d %d", &l, &r);
	long long sl = (solve(l - 1) + solve(l / 2)) % mod * inv2 % mod;
	long long sr = (solve(r) + solve((r + 1) / 2)) % mod * inv2 % mod;
	printf("%I64d\n", (sr - sl + mod) % mod);
	return 0;
}
