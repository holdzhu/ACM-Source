#include <cstdio>
#include <cstring>

int a[10][10];
int ans[10][10][1024];

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			scanf("%d", &a[i][j]);
		}
	}
	memset(ans, -1, sizeof ans);
	for (int i = 9; i >= 0; --i)
	{
		for (int j = 9; j >= 0; --j)
		{
			if (i == 9 && j == 9)
			{
				ans[i][j][1 << a[i][j]] = a[i][j];
			}
			else if (i == 9)
			{
				for (int k = 0; k < 1024; ++k)
				{
					if (ans[i][j + 1][k] != -1 && (ans[i][j][k | (1 << a[i][j])] == -1 || ans[i][j][k | (1 << a[i][j])] > a[i][j] + ans[i][j + 1][k]))
					{
						ans[i][j][k | (1 << a[i][j])] = a[i][j] + ans[i][j + 1][k];
					}
				}
			}
			else if (j == 9)
			{
				for (int k = 0; k < 1024; ++k)
				{
					if (ans[i + 1][j][k] != -1 && (ans[i][j][k | (1 << a[i][j])] == -1 || ans[i][j][k | (1 << a[i][j])] > a[i][j] + ans[i + 1][j][k]))
					{
						ans[i][j][k | (1 << a[i][j])] = a[i][j] + ans[i + 1][j][k];
					}
				}
			}
			else
			{
				for (int k = 0; k < 1024; ++k)
				{
					if (ans[i + 1][j][k] != -1 && ans[i][j + 1][k] != -1)
					{
						int min = ans[i + 1][j][k] > ans[i][j + 1][k] ? ans[i][j + 1][k] : ans[i + 1][j][k];
						if (ans[i][j][k | (1 << a[i][j])] == -1 || ans[i][j][k | (1 << a[i][j])] > a[i][j] + min)
						{
							ans[i][j][k | (1 << a[i][j])] = a[i][j] + min;
						}
					}
					else if (ans[i + 1][j][k] != -1)
					{
						if (ans[i][j][k | (1 << a[i][j])] == -1 || ans[i][j][k | (1 << a[i][j])] > a[i][j] + ans[i + 1][j][k])
						{
							ans[i][j][k | (1 << a[i][j])] = a[i][j] + ans[i + 1][j][k];
						}
					}
					else if (ans[i][j + 1][k] != -1)
					{
						if (ans[i][j][k | (1 << a[i][j])] == -1 || ans[i][j][k | (1 << a[i][j])] > a[i][j] + ans[i][j + 1][k])
						{
							ans[i][j][k | (1 << a[i][j])] = a[i][j] + ans[i][j + 1][k];
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans[0][0][1023]);
	return 0;
}
