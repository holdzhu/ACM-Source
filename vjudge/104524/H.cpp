#include <cstdio>
#include <algorithm>

using namespace std;

pair<double, int> event[400010];
double ans[100010];

int main()
{
	int n, l, v1, v2;
	scanf("%d %d %d %d", &n, &l, &v1, &v2);
	double len = 1.0 * l * v2 / (v1 + v2);
	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		event[m++] = make_pair(a - len, 1);
		event[m++] = make_pair(a, -1);
		event[m++] = make_pair(a - len + 2.0 * l, 1);
		event[m++] = make_pair(a + 2.0 * l, -1);
	}
	event[m++] = make_pair(0, 2);
	event[m++] = make_pair(2.0 * l, -2);
	sort(event, event + m);
	double last = -1e9;
	int cnt = 0;
	bool flag = false;
	for (int i = 0; i < m; ++i)
	{
		if (event[i].second == 2)
		{
			flag = true;
		}
		else if (event[i].second == -2)
		{
			ans[cnt] += event[i].first - last;
			break;
		}
		else
		{
			if (flag)
				ans[cnt] += event[i].first - last;
			cnt += event[i].second;
		}
		last = event[i].first;
	}
	for (int i = 0; i <= n; ++i)
	{
		printf("%.12f\n", ans[i] / 2.0 / l);
	}
	return 0;
}
