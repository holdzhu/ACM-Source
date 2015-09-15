#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;
map<int, int> id;
int n, m;
int cnt = 0;
int f[500];
long long d[500][500];
long long s[500][500];
long long tmp[500][500];

int encode(int a1, int a2, int a3, int a4)
{
	return (a1 << (m * 3)) + (a2 << (m * 2)) + (a3 << m) + a4;
}

int expand(int x)
{
	int ret = x;
	for (int i = 0; i < m; ++i)
	{
		if (x & (1 << i))
		{
			if (i)
			{
				ret |= (1 << (i - 1));
			}
			if (i < m - 1)
			{
				ret |= (1 << (i + 1));
			}
		}
	}
	return ret;
}

bool check(int a1, int a2, int a3, int a4)
{
	int e1 = expand(a1);
	int e2 = expand(a2);
	int e3 = expand(a3);
	int e4 = expand(a4);
	if ((e1 & a2) || (e1 & a3) || (e1 & a4))
	{
		return false;
	}
	if ((e2 & a1) || (e2 & a3) || (e2 & a4))
	{
		return false;
	}
	if ((e3 & a1) || (e3 & a2) || (e3 & a4))
	{
		return false;
	}
	if ((e4 & a1) || (e4 & a2) || (e4 & a3))
	{
		return false;
	}
	return true;
}

int x[4], y[4], ex[4], same[4];

bool isvalid(int a, int b)
{
	for (int i = 0; i < 4; ++i)
	{
		x[i] = a & ((1 << m) - 1);
		a >>= m;
		ex[i] = expand(x[i]);
		same[i] = -1;
	}
	for (int i = 0; i < 4; ++i)
	{
		y[i] = b & ((1 << m) - 1);
		b >>= m;
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (x[i] & y[j])
			{
				if (same[i] != -1)
				{
					return false;
				}
				same[i] = j;
			}
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (same[i] == j)
			{
				continue;
			}
			if (ex[i] & y[j])
			{
				return false;
			}
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		int last = -1;
		bool tt = false;
		bool t2 = false;
		for (int j = 0; j < m + 1; ++j)
		{
			if (y[i] & (1 << j))
			{
				last = j;
				if (tt)
				{
					t2 = true;
					break;
				}
			}
			else
			{
				if (last != -1)
				{
					tt = true;
				}
			}
		}
		if (!t2)
		{
			continue;
		}
		for (int j = 0; j < m; ++j)
		{
			if (y[i] & (1 << j))
			{
				bool flag = false;
				if (j)
				{
					flag |= y[i] & (1 << (j - 1));
				}
				if (j < m - 1)
				{
					flag |= y[i] & (1 << (j + 1));
				}
				for (int k = 0; k < 4; ++k)
				{
					flag |= x[k] & (1 << j);
				}
				if (!flag)
				{
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int a1 = 0; a1 < (1 << m); ++a1)
	{
		for (int a2 = a1; a2 < (1 << m); ++a2)
		{
			if (!check(a1, a2, 0, 0))
			{
				continue;
			}
			for (int a3 = a2; a3 < (1 << m); ++a3)
			{
				if (!check(a1, a2, a3, 0))
				{
					continue;
				}
				for (int a4 = a3; a4 < (1 << m); ++a4)
				{
					if (!check(a1, a2, a3, a4))
					{
						continue;
					}
					id[encode(a1, a2, a3, a4)] = 0;
				}
			}
		}
	}
	for (map<int, int>::iterator it = id.begin(); it != id.end(); ++it)
	{
		f[cnt] = it->first;
		it->second = cnt++;
	}
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < cnt; ++j)
		{
			d[i][j] = isvalid(f[i], f[j]);
		}
	}
	for (int i = 0; i < cnt; ++i)
	{
		s[i][i] = 1;
	}
	while (n)
	{
		if (n & 1)
		{
			for (int i = 0; i < cnt; ++i)
			{
				for (int j = 0; j < cnt; ++j)
				{
					tmp[i][j] = 0;
					for (int k = 0; k < cnt; ++k)
					{
						tmp[i][j] = (tmp[i][j] + s[i][k] * d[k][j]) % mod;
					}
				}
			}
			for (int i = 0; i < cnt; ++i)
			{
				for (int j = 0; j < cnt; ++j)
				{
					s[i][j] = tmp[i][j];
				}
			}
		}
		for (int i = 0; i < cnt; ++i)
		{
			for (int j = 0; j < cnt; ++j)
			{
				tmp[i][j] = 0;
				for (int k = 0; k < cnt; ++k)
				{
					tmp[i][j] = (tmp[i][j] + d[i][k] * d[k][j]) % mod;
				}
			}
		}
		for (int i = 0; i < cnt; ++i)
		{
			for (int j = 0; j < cnt; ++j)
			{
				d[i][j] = tmp[i][j];
			}
		}
		n >>= 1;
	}
	long long ans = 0;
	for (int i = 0; i < cnt; ++i)
	{
		ans = (ans + s[0][i]) % mod;
	}
	printf("%I64d\n", ans);
	return 0;
}
