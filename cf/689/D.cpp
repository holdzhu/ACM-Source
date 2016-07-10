#include <cstdio>
#include <algorithm>

using namespace std;

int a[18][200000];
int b[18][200000];
int Log[200001];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[0][i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &b[0][i]);
	for (int i = 1; (1 << i) <= n; ++i)
		for (int j = 0; j + (1 << i) <= n; ++j)
		{
			a[i][j] = max(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
			b[i][j] = min(b[i - 1][j], b[i - 1][j + (1 << (i - 1))]);
		}
	Log[0] = -1;
	for (int i = 1; i <= n; ++i)
		Log[i] = Log[i >> 1] + 1;
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int l = i, r = n;
		while (l < r)
		{
			int m = (l + r) >> 1;
			int L = Log[m - i + 1];
			int mx = max(a[L][i], a[L][m - (1 << L) + 1]);
			int mi = min(b[L][i], b[L][m - (1 << L) + 1]);
			if (mx < mi)
				l = m + 1;
			else
				r = m;
		}
		if (l >= n)
			continue;
		int L = Log[l - i + 1];
		int mx = max(a[L][i], a[L][l - (1 << L) + 1]);
		int mi = min(b[L][i], b[L][l - (1 << L) + 1]);
		if (mx != mi)
			continue;
		int l2 = l, r2 = n;
		while (l2 < r2)
		{
			int m = (l2 + r2) >> 1;
			int L = Log[m - i + 1];
			int mx = max(a[L][i], a[L][m - (1 << L) + 1]);
			int mi = min(b[L][i], b[L][m - (1 << L) + 1]);
			if (mx <= mi)
				l2 = m + 1;
			else
				r2 = m;
		}
		L = Log[4 - i + 1];
		mx = L == 0 ? a[0][i] : max(a[L][i], a[L][4 - (1 << L) + 1]);
		mi = L == 0 ? b[0][i] : min(b[L][i], b[L][4 - (1 << L) + 1]);
		ans += l2 - l;
	}
	printf("%I64d\n", ans);
	return 0;
}
