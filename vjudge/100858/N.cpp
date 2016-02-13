#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const double eps = 1e-10;
const double pi = acos(-1);
int bx[1000];
int by[1000];
int cx[1000];
int cy[1000];
int cr[1000];
vector<int> G[1000];
pair<pair<double, double>, double> deg[3000];
pair<double, int> pd[1000];
bool vis[1000];

int main()
{
	int N;
	scanf("%d", &N);
	while (N--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
			G[i].clear(), vis[i] = false;
		for (int i = 0; i < n; ++i)
			scanf("%d %d", bx + i, by + i);
		for (int i = 0; i < m; ++i)
			scanf("%d %d %d", cx + i, cy + i, cr + i);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				double beta = atan2(cy[j] - by[i], cx[j] - bx[i]);
				double dis = hypot(cy[j] - by[i], cx[j] - bx[i]);
				double theta = asin(cr[j] / dis);
				deg[j] = make_pair(make_pair(beta - theta, beta + theta), sqrt(dis * dis - cr[j] * cr[j]));
				deg[j + m] = deg[j + 2 * m] = deg[j];
				deg[j + m].first.first += pi * 2;
				deg[j + m].first.second += pi * 2;
				deg[j + 2 * m].first.first -= pi * 2;
				deg[j + 2 * m].first.second -= pi * 2;
			}
			sort(deg, deg + m * 3);
			for (int j = 0; j < n; ++j)
				pd[j - (j > i)] = make_pair(atan2(by[j] - by[i], bx[j] - bx[i]), j);
			sort(pd, pd + n - 1);
			priority_queue<pair<double, double> > pq;
			for (int j = 0, k = 0; j < n - 1; ++j)
			{
				while (k < m * 3 && deg[k].first.first < pd[j].first + eps)
					pq.push(make_pair(-deg[k].second, deg[k].first.second)), k++;
				while (pq.size() && pq.top().second < pd[j].first - eps)
					pq.pop();
				if (pq.empty() || hypot(bx[pd[j].second] - bx[i], by[pd[j].second] - by[i]) < -pq.top().first + eps)
					G[i].push_back(pd[j].second);
			}
		}
		int cnt = -1;
		for (int i = 0; i < n; ++i)
			if (!vis[i])
			{
				cnt++;
				queue<int> q;
				q.push(i);
				while (!q.empty())
				{
					int u = q.front();
					q.pop();
					for (int v: G[u])
						if (!vis[v])
							q.push(v), vis[v] = true;
				}
			}
		printf("%d\n", cnt);
	}
	return 0;
}
