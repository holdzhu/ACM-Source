#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 5e5;

int n, m;
int a[maxn];
int mx[19][maxn];
int Log[maxn + 1];
int dpl[19][maxn + 2];
int dpr[19][maxn + 2];
int lenl[19][maxn + 2];
int lenr[19][maxn + 2];
int maxk;
vector<int> pos[maxn];

inline void initDiscrete()
{
	vector<int> vals;
	for (int i = 0; i < n; ++i)
		vals.push_back(a[i]);
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	for (int i = 0; i < n; ++i)
		a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
}

inline void initRMQ()
{
	Log[0] = -1;
	for (int i = 1; i <= n; ++i)
		Log[i] = Log[i >> 1] + 1;
	for (int i = 0; i < n; ++i)
		mx[0][i] = a[i];
	for (int i = 1; (1 << i) <= n; maxk = i, ++i)
		for (int j = 0; j + (1 << i) <= n; ++j)
			mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
}

inline int RMQ(int l, int r)
{
	int i = Log[r - l + 1];
	return max(mx[i][l], mx[i][r - (1 << i) + 1]);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	initDiscrete();
	initRMQ();
	for (int i = 0; i < n; ++i)
		pos[a[i]].push_back(i);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < pos[i].size(); ++j)
		{
			int L = 0;
			int R = j;
			while (L < R)
			{
				int M = (L + R) >> 1;
				if (RMQ(pos[i][M], pos[i][j]) <= i)
					R = M;
				else
					L = M + 1;
			}
			dpl[0][pos[i][j] + 1] = pos[i][L];
			lenl[0][pos[i][j] + 1] = pos[i][j] - pos[i][L];
			L = j;
			R = pos[i].size() - 1;
			while (L < R)
			{
				int M = (L + R + 1) >> 1;
				if (RMQ(pos[i][j], pos[i][M]) <= i)
					L = M;
				else
					R = M - 1;
			}
			dpr[0][pos[i][j] + 1] = pos[i][L] + 2;
			lenr[0][pos[i][j] + 1] = pos[i][L] - pos[i][j];
		}
	for (int i = 1; (1 << i) <= n; ++i)
	{
		dpr[i - 1][n + 1] = n + 1;
		for (int j = 1; j <= n; ++j)
		{
			dpl[i][j] = dpl[i - 1][dpl[i - 1][j]];
			lenl[i][j] = max(lenl[i - 1][j], lenl[i - 1][dpl[i - 1][j]]);
			dpr[i][j] = dpr[i - 1][dpr[i - 1][j]];
			lenr[i][j] = max(lenr[i - 1][j], lenr[i - 1][dpr[i - 1][j]]);
		}
	}
	while (m--)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		int posl = l;
		int mxl = 0;
		for (int i = maxk; i >= 0; --i)
			if (dpr[i][posl] <= r + 1)
			{
				mxl = max(mxl, lenr[i][posl]);
				posl = dpr[i][posl];
			}
		int posr = r;
		int mxr = 0;
		for (int i = maxk; i >= 0; --i)
			if (dpl[i][posr] >= l - 1)
			{
				mxr = max(mxr, lenl[i][posr]);
				posr = dpl[i][posr];
			}
		int ans = max(mxl, mxr);
		if (posl <= posr && a[posl - 1] == a[posr - 1]
			&& RMQ(posl - 1, posr - 1) <= a[posl - 1])
			ans = max(ans, posr - posl);
		printf("%d\n", ans);
	}
	return 0;
}
