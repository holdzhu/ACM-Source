#include <cstdio>
#include <cstring>
#include <set>
#include <queue>
#include <vector>

#define INF 1000000000

using namespace std;

struct Road
{
	int x, y, s;
	Road(int x = 0, int y = 0, int s = 0) : x(x), y(y), s(s)
	{

	}
};

struct Step
{
	int p, s;
	set<int> roads;
};

Road road[100000];
vector<int> G[100000];
int vis[100000];
int viss[100000];

struct cmp
{
	bool operator() (const Step & a, const Step & b)
	{
		return a.s > b.s || (a.s == b.s && a.roads.size() > b.roads.size());
	}
};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		vis[i] = INF;
		viss[i] = INF;
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d", &road[i].x, &road[i].y, &road[i].s);
		road[i].x--;
		road[i].y--;
		G[road[i].x].push_back(i);
		G[road[i].y].push_back(i);
	}
	priority_queue<Step, vector<Step>, cmp> pq;
	Step firststep;
	firststep.p = 0;
	firststep.s = 0;
	for (int i = 0; i < m; ++i)
	{
		if (road[i].s)
		{
			firststep.roads.insert(i);
		}
	}
	vis[0] = 0;
	viss[0] = 0;
	pq.push(firststep);
	while (!pq.empty())
	{
		Step step = pq.top();
		pq.pop();
		if (step.p == n - 1)
		{
			printf("%u\n", step.roads.size());
			for (set<int>::iterator i = step.roads.begin(); i != step.roads.end(); ++i)
			{
				printf("%d %d %d\n", road[*i].x + 1, road[*i].y + 1, 1 - road[*i].s);
			}
			break;
		}
		for (int i = 0; i < G[step.p].size(); ++i)
		{
			int to = road[G[step.p][i]].x + road[G[step.p][i]].y - step.p;
			if (step.s + 1 <= viss[to])
			{
				Step _step;
				_step.p = to;
				_step.s = step.s + 1;
				_step.roads = step.roads;
				if (road[G[step.p][i]].s)
				{
					_step.roads.erase(G[step.p][i]);
				}
				else
				{
					_step.roads.insert(G[step.p][i]);
				}
				if (step.s + 1 < viss[to] || _step.roads.size() <= vis[to])
				{
					pq.push(_step);
					vis[to] = _step.roads.size();
					viss[to] = step.s + 1;
				}
			}
		}
	}
	return 0;
}
