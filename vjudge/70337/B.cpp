#include <cstdio>
#include <cstring>

using namespace std;

bool ok[1024][101];

int main()
{
	int n;
	int kase = 1;
	bool num[10];
	memset(ok, 0, sizeof(0));
	for (int i = 0; i < 1 << 10; ++i)
	{
		int _i = i;
		for (int j = 0; j < 10; ++j)
		{
			num[j] = _i % 2;
			_i >>= 1;
			if (num[j])
			{
				ok[i][j] = true;
			}
		}
		for (int s1 = 0; s1 < 10; ++s1)
		{
			for (int s2 = s1 + 1; s2 < 10; ++s2)
			{
				if (num[s1] && num[s2])
				{
					ok[i][s1 + s2] = true;
				}
			}
		}
		for (int s1 = 1; s1 < 10; ++s1)
		{
			for (int s2 = 0; s2 < 10; ++s2)
			{
				if (s1 != s2 && num[s1] && num[s2])
				{
					ok[i][s1 * 10 + s2] = true;
				}
			}
		}
		for (int s1 = 1; s1 < 10; ++s1)
		{
			if (num[s1]) for (int s2 = 0; s2 < 10; ++s2)
			{
				if (num[s2] && s1 != s2) for (int s3 = s2 + 1; s3 < 10; ++s3)
				{
					if (num[s3] && s1 != s3)
					{
						if (s1 * 10 + s2 + s3 <= 100) ok[i][s1 * 10 + s2 + s3] = true;
					}
				}
			}
		}
		for (int s1 = 1; s1 < 10; ++s1)
		{
			if (num[s1]) for (int s2 = 0; s2 < 10; ++s2)
			{
				if (num[s2] && s1 != s2) for (int s3 = s1 + 1; s3 < 10; ++s3)
				{
					if (num[s3] && s2 != s3) for (int s4 = s2 + 1; s4 < 10; ++s4)
					{
						if (num[s4] && s1 != s4 && s3 != s4)
						{
							if (s1 * 10 + s2 + s3 * 10 + s4 <= 100) ok[i][s1 * 10 + s2 + s3 * 10 + s4] = true;
						}
					}
				}
			}
		}
	}
	while (scanf("%d", &n) == 1 && n)
	{
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		long long m = 9876543210LL;
		for (int i = 0; i < 1024; ++i)
		{
			bool flag = true;
			for (int j = 0; j < n; ++j)
			{
				if (!ok[i][a[j]])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				long long t = 0;
				int _i = i;
				for (int j = 0; j < 10; ++j)
				{
					num[j] = _i % 2;
					_i >>= 1;
				}
				for (int j = 9; j >= 0; --j)
				{
					if (num[j])
					{
						t *= 10;
						t += j;
					}
				}
				if (t < m)
				{
					m = t;
				}
			}
		}
		printf("Case %d: %lld\n", kase++, m);
	}
	return 0;
}
