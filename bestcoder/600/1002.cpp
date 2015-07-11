#include <cstdio>
#include <deque>
#include <map>

using namespace std;

int a[10000];
int p[10000];
deque<int> dqmin;
deque<int> dqmax;
map<int, int> ma;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		if (ma.count(a[i]))
		{
			p[i] = ma[a[i]];
		}
		else
		{
			p[i] = -1000000;
		}
		ma[a[i]] = i;
	}
	printf("Case #1:\n");
	for (int i = 0; i < m; ++i)
	{
		int k;
		scanf("%d", &k);
		int l = 0;
		int ans = 0;
		dqmin.clear();
		dqmax.clear();
		for (int j = 0; j < n; ++j)
		{
			if (j - p[j] < k)
			{
				l = j;
				dqmin.clear();
				dqmax.clear();
			}
			if (j - l == k)
			{
				if (!dqmin.empty() && dqmin.front() == l)
				{
					dqmin.pop_front();
				}
				if (!dqmax.empty() && dqmax.front() == l)
				{
					dqmax.pop_front();
				}
				l++;
			}
			while (!dqmin.empty() && a[dqmin.back()] >= a[j])
			{
				dqmin.pop_back();
			}
			while (!dqmax.empty() && a[dqmax.back()] <= a[j])
			{
				dqmax.pop_back();
			}
			dqmax.push_back(j);
			dqmin.push_back(j);
			if (j - l == k - 1)
			{
				if (a[dqmax.front()] - a[dqmin.front()] == k - 1)
				{
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
