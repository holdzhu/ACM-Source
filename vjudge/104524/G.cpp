#include <cstdio>
#include <algorithm>

using namespace std;

int t[100000];
pair<pair<int, int>, int> m[100000];
int ans[100001];

int main()
{
	int n, k;
	scanf("%d %d %*d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &t[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		m[i] = make_pair(make_pair(t[i], tmp), i + 1);
	}
	sort(m, m + n);
	double L = 0, R = 1e5 + 10;
	for (int it = 0; it < 100; ++it)
	{
		double M = (L + R) / 2;
		int K = k;
		for (int i = n - 1; i >= 0 && K > 0; --i)
		{
			double t = 1.0 * K / m[i].first.second;
			if (t <= M)
				K--;
		}
		if (K == 0)
			R = M;
		else
			L = M;
	}
	int K = k;
	for (int i = n - 1; i >= 0 && K > 0; --i)
	{
		double t = 1.0 * K / m[i].first.second;
		if (t <= R)
			ans[--K] = m[i].second;
	}
	for (int i = 0; i < k; ++i)
	{
		printf("%d%s", ans[i], i == k - 1 ? "\n" : " ");
	}
	return 0;
}
