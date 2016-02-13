#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps = 1e-10;
const double pi = acos(-1);
pair<double, double> deg[2000];
double tmp[4];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		tmp[0] = atan2(y1, x1);
		tmp[1] = atan2(y1, x2) - pi * 2;
		while (fabs(tmp[1] - tmp[0]) > pi) tmp[1] += pi * 2;
		tmp[2] = atan2(y2, x1) - pi * 2;
		while (fabs(tmp[2] - tmp[0]) > pi) tmp[2] += pi * 2;
		tmp[3] = atan2(y2, x2) - pi * 2;
		while (fabs(tmp[3] - tmp[0]) > pi) tmp[3] += pi * 2;
		sort(tmp, tmp + 4);
		deg[i].first = tmp[0] - pi * 2;
		deg[i].second = tmp[3] - pi * 2;
		while (deg[i].first < 0) deg[i].first += pi * 2;
		while (deg[i].second < deg[i].first) deg[i].second += pi * 2;
	}
	sort(deg, deg + N);
	int ans = N;
	for (int i = 0; i < N; ++i)
	{
		int cnt = 0;
		double last = -1e9;
		for (int j = i; j < i + N && cnt < ans; ++j)
		{
			if (deg[j % N].first + j / N * 2 * pi > last + eps)
			{
				cnt++;
				last = deg[j % N].second + j / N * 2 * pi;
			}
			else if (deg[j % N].second + j / N * 2 * pi < last)
				last = deg[j % N].second + j / N * 2 * pi;
		}
		ans = min(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}