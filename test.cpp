#include <cstdio>
#include <cstring>

int n = 6;
int m = 4;
char s[6][7] =
{
	"1111",
	"1111",
	"1111",
	"1111",
	"1111",
	"1111"
};

int cnt = 0;
int x[100];
int y[100];
bool r[8];
bool c[8];
bool b[8][8];

int main()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (s[i][j] == '1')
			{
				x[cnt] = i;
				y[cnt++] = j;
			}
		}
	}
	for (int i = 0; i < (1 << cnt); ++i)
	{
		memset(r, 0, sizeof r);
		memset(c, 0, sizeof c);
		memset(b, 0, sizeof b);
		for (int j = 0; j < cnt; ++j)
		{
			if (i & (1 << j))
			{
				r[x[j]] ^= 1;
				c[y[j]] ^= 1;
				b[x[j]][y[j]] = 1;
			}
		}
		int cc = 0;
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				if (s[j][k] == '1')
				{
					if (b[j][k] ^ r[j] ^ c[k])
					{
						cc++;
					}
				}
			}
		}
		if (cc == cnt)
		{
			for (int j = 0; j < n; ++j)
			{
				for (int k = 0; k < m; ++k)
				{
					printf("%d", b[j][k]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
