#include <cstdio>
#include <cmath>
#include <cstring>

const int mod = 1000000007;

long long powmod(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}
	if (b == 1)
	{
		return a % mod;
	}
	long long s = powmod(a, b / 2);
	s = (s * s) % mod;
	if (b % 2 == 1)
	{
		s = (s * a) % mod;
	}
	return s;
}

long long solve(int x, int y, int z)
{
	int t[1000];
	memset(t, 0, sizeof(t));
	for (int j = x + 1; j <= x + y + z; ++j)
	{
		int s = j;
		for (int i = 2; i <= s; ++i)
		{
			while (s % i == 0)
			{
				t[i]++;
				s /= i;
			}
		}
	}
	for (int j = 2; j <= y; ++j)
	{
		int _y = j;
		for (int i = 2; i <= _y; ++i)
		{
			while (_y % i == 0)
			{
				t[i]--;
				_y /= i;
			}
		}
	}
	for (int j = 2; j <= z; ++j)
	{
		int _z = j;
		for (int i = 2; i <= _z; ++i)
		{
			while (_z % i == 0)
			{
				t[i]--;
				_z /= i;
			}
		}
	}
	long long rnt = 1;
	for (int i = 0; i < 1000; ++i)
	{
		if (t[i] != 0)
		{
			rnt *= powmod(i, t[i]);
			rnt %= mod;
		}
	}
	return rnt;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int bx, by, bz, bx1, by1, bz1, bx2, by2, bz2;
		scanf("%d %d %d %d %d %d %d %d %d", &bx, &by, &bz, &bx1, &by1, &bz1, &bx2, &by2, &bz2);
		long long s = solve(bx, by, bz) - (solve(bx1, by1, bz1) * solve(bx - bx1, by - by1, bz - bz1)) % mod - (solve(bx2, by2, bz2) * solve(bx - bx2, by - by2, bz - bz2)) % mod;
		while (s < 0)
		{
			s += mod;
		}
		s %= mod;
		if (bx1 >= bx2 && by1 >= by2 && bz1 >= bz2)
		{
			s += ((solve(bx2, by2, bz2) * solve(bx1 - bx2, by1 - by2, bz1 - bz2)) % mod * solve(bx - bx1, by - by1, bz - bz1)) % mod;
			s %= mod;
		}
		else if (bx2 >= bx1 && by2 >= by1 && bz2 >= bz1)
		{
			s += ((solve(bx1, by1, bz1) * solve(bx2 - bx1, by2 - by1, bz2 - bz1)) % mod * solve(bx - bx2, by - by2, bz - bz2)) % mod;
			s %= mod;
		}
		printf("%lld\n", s % mod);
	}
	return 0;
}
