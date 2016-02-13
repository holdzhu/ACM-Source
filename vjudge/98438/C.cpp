#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5;
int num[maxn];
int tree[maxn * 2 + 1];
int id[maxn * 2 + 1];
int pos[maxn + 1];
pair<char, int> q[maxn];
int m;

inline int lowbit(int x)
{
	return x & (-x);
}

void update(int x, int delta)
{
	while (x <= m * 2)
	{
		tree[x] += delta;
		x += lowbit(x);
	}
}

int query(int x)
{
	int ret = 0;
	while (x)
	{
		ret += tree[x];
		x -= lowbit(x);
	}
	return ret;
}

int kth(int k)
{
	int ret = 0, cnt = 0;
	for (int i = 17; i >= 0; --i)
	{
		ret += 1 << i;
		if (ret >= m * 2 || cnt + tree[ret] >= k)
		{
			ret -= 1 << i;
		}
		else
		{
			cnt += tree[ret];
		}
	}
	return ret + 1;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int N, Q;
		scanf("%d %d", &N, &Q);
		m = 1;
		for (int i = 0; i < Q; ++i)
		{
			scanf(" %c%*s %d", &q[i].first, &q[i].second);
			if (q[i].first != 'R')
			{
				num[m++] = q[i].second;
			}
		}
		num[m++] = N;
		sort(num, num + m);
		for (int i = 0; i <= m * 2; ++i)
		{
			tree[i] = 0;
		}
		int top = m;
		for (int i = 1; i <= m; ++i)
		{
			update(top + i, num[i] - num[i - 1]);
			id[top + i] = num[i];
			pos[i] = top + i;
		}
		printf("Case %d:\n", kase);
		for (int i = 0; i < Q; ++i)
		{
			if (q[i].first == 'T')
			{
				int x = lower_bound(num, num + m, q[i].second) - num;
				update(pos[x], -1);
				id[pos[x]]--;
				pos[x] = top--;
				update(pos[x], 1);
				id[pos[x]] = q[i].second;
			}
			else if (q[i].first == 'Q')
			{
				printf("%d\n", query(pos[lower_bound(num, num + m, q[i].second) - num]));
			}
			else
			{
				int p = kth(q[i].second);
				printf("%d\n", id[p] + q[i].second - query(p));
			}
		}
	}
	return 0;
}
