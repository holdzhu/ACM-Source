#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
bool a[101][101][101];
int main()
{
	for (int i = 1; i <= 100; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			for (int k = 0; k <= j; ++k)
			{
				if (i == 1 && j == 0 && k == 0)
				{
					a[i][j][k] = 0;
				}
				else
				{
					bool flag = true;
					for (int c = 1; c < i && flag; ++c)
					{
						int _i = c;
						int _j = min(c, j);
						int _k = min(c, k);
						flag = a[_i][_j][_k];
					}
					for (int c = 0; c < j && flag; ++c)
					{
						int _i = i;
						int _j = c;
						int _k = min(c, k);
						flag = a[_i][_j][_k];
					}
					for (int c = 0; c < k && flag; ++c)
					{
						int _i = i;
						int _j = j;
						int _k = c;
						flag = a[_i][_j][_k];
					}
					a[i][j][k] = !flag;
				}
			}
		}
	}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int K, p, q, r;
		scanf("%d%d%d%d", &K, &p, &q, &r);
		if (a[p][q][r])
		{
			bool flag = true;
			for (int c = 1; c < p && flag; ++c)
			{
				int _i = c;
				int _j = min(c, q);
				int _k = min(c, r);
				flag = a[_i][_j][_k];
				if (!flag)
				{
					printf("%d W %d 1\n", K, c + 1);
				}
			}
			for (int c = 0; c < q && flag; ++c)
			{
				int _i = p;
				int _j = c;
				int _k = min(c, r);
				flag = a[_i][_j][_k];
				if (!flag)
				{
					printf("%d W %d 2\n", K, c + 1);
				}
			}
			for (int c = 0; c < r && flag; ++c)
			{
				int _i = p;
				int _j = q;
				int _k = c;
				flag = a[_i][_j][_k];
				if (!flag)
				{
					printf("%d W %d 3\n", K, c + 1);
				}
			}
		}
		else
		{
			printf("%d L\n", K);
		}
	}
	return 0;
}
