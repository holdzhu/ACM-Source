#include <algorithm>
#include <cstdio>

using namespace std;

const int mod = 772002 + 233;
const int dep = 20;
const int cnt = 1 << dep;

pair<int, int> tree[cnt << 1];

template <class T>
inline void operator+=(pair<T, T> &lhs, const pair<T, T> &rhs)
{
	lhs.first += rhs.first;
	if (lhs.first >= mod)
		lhs.first -= mod;
	lhs.second += rhs.second;
	if (lhs.second >= mod)
		lhs.second -= mod;
}

int main()
{
	int N, Q;
	scanf("%d %d", &N, &Q);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &tree[i + cnt].second), tree[i + cnt].second %= mod;
	while (Q--)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			int l, y;
			scanf("%d %d", &l, &y);
			int r = min(N, l + y - 1);
			pair<int, int> p{mod - 1, (l + y) % mod};
			for (l += cnt - 1, r += cnt + 1; l ^ r ^ 1; l >>= 1, r >>= 1)
			{
				if (~l & 1)
					tree[l ^ 1] += p;
				if (r & 1)
					tree[r ^ 1] += p;
			}
		}
		else
		{
			int x;
			scanf("%d", &x);
			int _x = x;
			pair<int, int> ret = tree[x += cnt];
			while (x >>= 1)
				ret += tree[x];
			printf("%lld\n", (1ll * ret.first * _x + ret.second) % mod);
		}
	}
	return 0;
}