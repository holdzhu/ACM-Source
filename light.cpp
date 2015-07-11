#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int n, m, d;
	scanf("%d %d %d", &n, &m, &d);
	int s = n * m;
	bool a[s][s * 2];
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			a[i * m + j][s + i * m + j] = 1;
			a[i * m + j][i * m + j] = 1;
			for (int dx = -1; dx <= 1; dx += 2)
			{
				for (int dy = -1; dy <= 1; dy += 2)
				{	
					for (int k = 0; k <= d; ++k)
					{
						int x = i + dx * k;
						int y = j + dy * (k - d);
						if (x >= 0 && x < n && y >= 0 && y < m)
						{
							a[i * m + j][x * m + y] = 1;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < s; ++i)
	{
		int p;
		for (p = i; p < s; ++p)
		{
			if (a[p][i])
			{
				break;
			}
		}
		if (p < s)
		{
			bool t;
			if (p != i) for (int j = i; j < s * 2; ++j)
			{
				t = a[i][j];
				a[i][j] = a[p][j];
				a[p][j] = t;
			}
			for (int j = i + 1; j < s; ++j)
			{
				if (a[j][i])
				{
					for (int k = i; k < s * 2; ++k)
					{
						a[j][k] ^= a[i][k];
					}
				}
			}
		}
	}
	for (int i = 1; i < s; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (a[j][i])
			{
				for (int k = i; k < s * 2; ++k)
				{
					a[j][k] ^= a[i][k];
				}
			}
		}
	}
	// for (int i = 0; i < s; ++i)
	// {
	// 	for (int j = 0; j < s; ++j)
	// 	{
	// 		printf("%d", a[i][j]);
	// 	}
	// 	printf(" ");
	// 	for (int j = 0; j < s; ++j)
	// 	{
	// 		printf("%d", a[i][j + s]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int x = 0; x < n; ++x)
	// 	{
	// 		for (int j = 0; j < m; ++j)
	// 		{
	// 			for (int y = 0; y < m; ++y)
	// 			{
	// 				printf("%d", a[i * m + j][i * m + j] & a[i * m + j][s + x * m + y]);
	// 			}
	// 			printf(" ");
	// 		}
	// 		printf("\n");
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
	bool c[n][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			c[i][j] = 0;
			for (int x = 0; x < n; ++x)
			{
				for (int y = 0; y < m; ++y)
				{
					c[i][j] ^= (a[i * m + j][i * m + j] & a[i * m + j][s + x * m + y]);
				}
			}
			printf("%c", c[i][j] ? '.' : ' ');
		}
		printf("\n");
	}
	printf("\n");
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < m; ++j)
	// 	{
	// 		bool bb = 0;
	// 		for (int x = 0; x < n; ++x)
	// 		{
	// 			for (int y = 0; y < m; ++y)
	// 			{
	// 				bb ^= (a[i * m + j][i * m + j] & a[i * m + j][s + x * m + y]) & c[x][y];
	// 			}
	// 		}
	// 		printf("%c", bb ? '.' : ' ');
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
	// bool b[s][s];
	// memset(b, 0, sizeof(b));
	// for (int i = 0; i < s; ++i)
	// {
	// 	for (int j = 0; j < s; ++j)
	// 	{
	// 		for (int k = 0; k < s; ++k)
	// 		{
	// 			b[i][j] ^= a[i][s + k] & a[j][s + k];
	// 		}
	// 	}
	// }
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int x = 0; x < n; ++x)
	// 	{
	// 		for (int j = 0; j < m; ++j)
	// 		{
	// 			for (int y = 0; y < m; ++y)
	// 			{
	// 				printf("%d", a[i * m + j][i * m + j] & b[i * m + j][x * m + y]);
	// 			}
	// 			printf(" ");
	// 		}
	// 		printf("\n");
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
	return 0;
}
