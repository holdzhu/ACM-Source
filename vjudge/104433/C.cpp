#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int mat[500][500];
int sum[501][501];

int main()
{
	scanf("%d %d", &n, &m);
	int ans = -1e9;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &mat[i][j]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			sum[i + 1][j + 1] = mat[i + 1][j + 1] + sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			int sum1 = 0, sum2 = 0;
			for (int k = 1; i >= k && j >= k && i + k < n && j + k < m; k += 2)
			{
				sum1 += sum[]
			}
		}
	printf("%d\n", ans);
	return 0;
}
