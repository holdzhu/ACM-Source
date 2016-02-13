#include <cstdio>

const int maxn = 1e6 + 10;
int sum[maxn][3];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int v, c;
		scanf("%d %d", &v, &c);
		sum[v + 1][c]++;
	}
	for (int i = 1; i < maxn; ++i)
		for (int j = 0; j < 3; ++j)
			sum[i][j] += sum[i - 1][j];
	int ansA = 0, ansB = 0, ans = 0;
	int mx = -1e9, A;
	for (int i = 1; i < maxn; ++i)
	{
		if (sum[i][0] - sum[i][1] > mx)
			mx = sum[i][0] - sum[i][1], A = i;
		int tmp = mx + sum[i][1] + sum[maxn - 1][2] - sum[i][2];
		if (tmp > ans || (tmp == ans && A + i <= ansA + ansB))
			ans = tmp, ansA = A, ansB = i;
	}
	printf("%d %d\n", ansA - 1, ansB - 1);
	return 0;
}
