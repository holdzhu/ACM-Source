#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[10][100];
int b[10][100];
int c[10][100];

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%*s");
		for (int j = 0; j < m; ++j)
			scanf("%d %d %d", &a[i][j], &b[i][j], &c[i][j]);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
				continue;
			vector<pair<int, int> > v;
			int sum = 0;
			int cnt = 0;
			for (int l = 0; l < m; ++l)
				if (a[i][l] < b[j][l])
					v.push_back(make_pair(a[i][l] - b[j][l], c[i][l]));
			sort(v.begin(), v.end());
			for (int l = 0; l < v.size(); ++l)
			{
				if (cnt + v[l].second >= k)
				{
					sum += (k - cnt) * -v[l].first;
					break;
				}
				sum += v[l].second * -v[l].first;
				cnt += v[l].second;
			}
			ans = max(ans, sum);
		}
	}
	printf("%d\n", ans);
	return 0;
}
