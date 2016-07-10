#include <cstdio>

int timc[5001], timr[5001];
int colc[5001], colr[5001];

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= k; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1)
		{
			timr[b - 1] = i;
			colr[b - 1] = c;
		}
		else
		{
			timc[b - 1] = i;
			colc[b - 1] = c;
		}
	}
	for (int i = 0; i < n; ++i, puts(""))
		for (int j = 0; j < m; ++j)
			printf("%d ", timr[i] < timc[j] ? colc[j] : colr[i]);
	return 0;
}
