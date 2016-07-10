#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1 << 17;

long long tree[maxn << 1];

int main()
{
	int N, Q;
	scanf("%d %d", &N, &Q);
	while (Q--)
	{
		int t, u, v;
		scanf("%d %d %d", &t, &u, &v);
		if (t == 1)
		{
			tree[u += maxn] += v;
			while (u >>= 1)
				tree[u] = max(tree[u << 1], tree[u << 1 | 1]);
		}
		else
		{
			long long ans = 0;
			u += maxn - 1;
			v += maxn + 1;
			for (u /= ~u & -~u, v /= v & -v; u ^ v ^ 1; )
			{
				if (u > v)
				{
					ans = max(ans, tree[u ^= 1]);
					u /= ~u & -~u;
				}
				else
				{
					ans = max(ans, tree[v ^= 1]);
					v /= v & -v;
				}
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
