#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int p[100];
long double np[100];
int c[100];
long double pw[100];
priority_queue<pair<long double, int> > pq;

int main()
{
	n = 100;
	// scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		p[i] = 1;
	long double ans = 0;
	long double last = 0;
	for (int i = 0; i < n; ++i)
	{
		pw[i] = 1;
		np[i] = 1 - p[i] * 0.01;
		pq.push({1e233, i});
	}
	for (int it = 1; it < 1e6; ++it)
	{
		int id = pq.top().second;
		pq.pop();
		long double P = 1;
		c[id]++;
		pw[id] *= np[id];
		pq.push({(1 - pw[id] * np[id]) / (1 - pw[id]), id});
		for (int i = 0; i < n; ++i)
			P *= 1 - pw[i];
		ans += it * (P - last);
		last = P;
	}
	printf("%.10f\n", (double)ans);
	return 0;
}
