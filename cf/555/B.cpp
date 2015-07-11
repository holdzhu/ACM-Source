#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Query
{
	int type;
	int ID;
	long long tim;
	long long add;
	bool operator < (const Query& rhs) const
	{
		return tim < rhs.tim || (tim == rhs.tim && type < rhs.type);
	}
};

Query q[400000];
int cnt = 0;
int ans[200000];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	long long ll, lr;
	scanf("%I64d %I64d", &ll, &lr);
	for (int i = 0; i < n - 1; ++i)
	{
		long long l, r;
		scanf("%I64d %I64d", &l, &r);
		q[cnt++] = (Query){0, i, l - lr, r - ll};
		ll = l;
		lr = r;
	}
	for (int i = 0; i < m; ++i)
	{
		long long t;
		scanf("%I64d", &t);
		q[cnt++] = (Query){1, i, t};
	}
	sort(q, q + cnt);
	priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > r;
	int c = 0;
	for (int i = 0; i < cnt; ++i)
	{
		while (r.size() > 0 && r.top().first < q[i].tim)
		{
			r.pop();
		}
		if (q[i].type == 0)
		{
			r.push(make_pair(q[i].add, q[i].ID));
		}
		else
		{
			if (r.size() > 0)
			{
				ans[r.top().second] = q[i].ID;
				r.pop();
				c++;
			}
		}
	}
	if (c == n - 1)
	{
		printf("Yes\n");
		for (int i = 0; i < n - 1; ++i)
		{
			if (i)
			{
				printf(" ");
			}
			printf("%d", ans[i] + 1);
		}
		printf("\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}
