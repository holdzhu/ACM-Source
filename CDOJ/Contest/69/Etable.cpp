#include <cstdio>
#include <cstring>

int SG[100];
int pow[100];
int powi;

int dfs(int x)
{
	if (SG[x] == -1)
	{
		bool tmp[100];
		memset(tmp, false, sizeof tmp);
		for (int i = 0; i < powi; ++i)
		{
			if (x >= pow[i])
			{
				tmp[dfs(x - pow[i])] = true;
			}
		}
		for (int i = 0; i < 100; ++i)
		{
			if (!tmp[i])
			{
				SG[x] = i;
				break;
			}
		}
	}
	return SG[x];
}

int main()
{
	for (int n = 1; n <= 40; ++n)
	{
		for (int k = 1; k <= 40; ++k)
		{
			// printf("%d ", ((n - 1) / k + 1) % (k + 1) % 2 == 0);
			memset(SG, -1, sizeof SG);
			SG[0] = 1;
			if (k == 1)
			{
				pow[0] = 1;
				powi = 1;
			}
			else
			{
				int s = k;
				powi = 0;
				for (int i = 0; i < 1000 && s <= n; ++i)
				{
					pow[powi++] = s;
					s *= k;
				}
			}
			if (dfs(n))
			{
				printf("1 ");
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}
	return 0;
}
