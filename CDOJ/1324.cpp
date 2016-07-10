#include <cstdio>
#include <algorithm>

using namespace std;

const int len = 300;
const int maxn = 1e5;
long long a[maxn + 1];
long long mx[(maxn + 1 + len + 1) / len];

int main()
{
	int N, Q;
	scanf("%d %d", &N, &Q);
	while (Q--)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			int p, x;
			scanf("%d %d", &p, &x);
			a[p] += x;
			mx[p / len] = max(mx[p / len], a[p]);
		}
		else
		{
			int L, R;
			scanf("%d %d", &L, &R);
			long long ans = 0;
			if (R - L <= len)
				for (int i = L; i <= R; ++i)
					ans = max(ans, a[i]);
			else
			{
				int Lid = L / len;
				int Rid = R / len;
				for (int i = Lid + 1; i < Rid; ++i)
					ans = max(ans, mx[i]);
				for (int i = (Lid + 1) * len - 1; i >= L; --i)
					ans = max(ans, a[i]);
				for (int i = Rid * len; i <= R; ++i)
					ans = max(ans, a[i]);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
