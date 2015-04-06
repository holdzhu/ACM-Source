#include <cstdio>
#include <cstring>

inline int max(int a, int b)
{
	return a > b ? a : b;
}

inline int longest(int d, int p)
{
	if (d == p || d == p - 1)
	{
		return d + p;
	}
	else if (d > p)
	{
		return p * 2;
	}
	else
	{
		return d * 2 + 1;
	}
}

char s[1002][1002];
int tl[1002][1002];
int tr[1002][1002];
int bl[1002][1002];
int br[1002][1002];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int M, N;
		scanf("%d %d", &M, &N);
		memset(s, 0, sizeof(s));
		for (int i = 0; i < M; ++i)
		{
			scanf("%s", s[i + 1] + 1);
		}
		int l = 0;
		for (int i = 0; i < 1002; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (s[i - j][j] == '1')
				{
					l++;
				}
				else
				{
					l = 0;
				}
				bl[i - j][j] = l;
			}
			for (int j = i; j >= 0; --j)
			{
				if (s[i - j][j] == '1')
				{
					l++;
				}
				else
				{
					l = 0;
				}
				tr[i - j][j] = l;
			}
			for (int j = 0; j <= i; ++j)
			{
				if (s[i - j][1001 - j] == '1')
				{
					l++;
				}
				else
				{
					l = 0;
				}
				br[i - j][1001 - j] = l;
			}
			for (int j = i; j >= 0; --j)
			{
				if (s[i - j][1001 - j] == '1')
				{
					l++;
				}
				else
				{
					l = 0;
				}
				tl[i - j][1001 - j] = l;
			}
		}
		for (int i = 0; i < 1001; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (s[1001 - i + j][1001 - j] == '1')
				{
					l++;
				}
				else
				{
					l = 0;
				}
				tr[1001 - i + j][1001 - j] = l;
			}
			for (int j = i; j >= 0; --j)
			{
				if (s[1001 - i + j][1001 - j] == '1')
				{
					l++;
				}
				else
				{
					l = 0;
				}
				bl[1001 - i + j][1001 - j] = l;
			}
			for (int j = 0; j <= i; ++j)
			{
				if (s[1001 - i + j][j] == '1')
				{
					l++;
				}
				else
				{
					l = 0;
				}
				tl[1001 - i + j][j] = l;
			}
			for (int j = i; j >= 0; --j)
			{
				if (s[1001 - i + j][j] == '1')
				{
					l++;
				}
				else
				{
					l = 0;
				}
				br[1001 - i + j][j] = l;
			}
		}
		int ans = 0;
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				if (s[i][j] == '1')
				{
					int t = longest(tl[i - 1][j - 1], tl[i][j - 1]) +
							longest(tr[i - 1][j + 1], tr[i - 1][j]) +
							longest(br[i + 1][j + 1], br[i][j + 1]) +
							longest(bl[i + 1][j - 1], bl[i + 1][j]) + 1;
					if (t > ans)
					{
						ans = t;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
