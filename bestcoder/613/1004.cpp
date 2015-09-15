#include <cstdio>
#include <map>

using namespace std;

map<int, long long> m;

int main()
{
	int n, q;
	while (scanf("%d %d %*d", &n, &q) == 3)
	{
		m.clear();
		int ans = 0;
		m[0] = -1e9;
		m[1] = -1e9;
		m[n + 1] = 1e9;
		m[n + 2] = 1e9;
		while (q--)
		{
			int l, r, val;
			scanf("%d %d %d", &l, &r, &val);
			l ^= ans;
			r ^= ans;
			val ^= ans;
			long long tl, tr;
			if (m.count(l))
			{
				tl = m[l];
				long long t1 = (--m.find(l))->second;
				if (t1 > 0 && m[l] >= 0 && m[l] + val < 0)
				{
					ans++;
				}
				if (t1 > 0 && m[l] < 0 && m[l] + val >= 0)
				{
					ans--;
				}
				int t2 = (++m.find(l))->first;
				if (t2 < r + 1)
				{
					if (m[t2] < 0 && m[l] > 0 && m[l] + val <= 0)
					{
						ans--;
					}
					if (m[t2] < 0 && m[l] <= 0 && m[l] + val > 0)
					{
						ans++;
					}
				}
				m[l] += val;
			}
			else
			{
				tl = 0;
				m[l] = val;
				long long t1 = (--m.find(l))->second;
				if (t1 > 0 && val < 0)
				{
					ans++;
				}
				int t2 = (++m.find(l))->first;
				if (t2 < r + 1)
				{
					if (m[t2] < 0 && val > 0)
					{
						ans++;
					}
				}
			}
			if (m.count(r + 1))
			{
				tr = m[r + 1];
				long long t1 = (++m.find(r + 1))->second;
				if (t1 < 0 && m[r + 1] <= 0 && m[r + 1] - val > 0)
				{
					ans++;
				}
				if (t1 < 0 && m[r + 1] > 0 && m[r + 1] - val <= 0)
				{
					ans--;
				}
				int t2 = (--m.find(r + 1))->first;
				if (t2 > l)
				{
					if (m[t2] > 0 && m[r + 1] < 0 && m[r + 1] - val >= 0)
					{
						ans--;
					}
					if (m[t2] > 0 && m[r + 1] >= 0 && m[r + 1] - val < 0)
					{
						ans++;
					}
				}
				m[r + 1] -= val;
			}
			else
			{
				tr = 0;
				m[r + 1] = -val;
				long long t1 = (++m.find(r + 1))->second;
				if (t1 < 0 && val < 0)
				{
					ans++;
				}
				int t2 = (--m.find(r + 1))->first;
				if (t2 > l)
				{
					if (m[t2] > 0 && val > 0)
					{
						ans++;
					}
				}
			}
			if ((++m.find(l))->first == r + 1)
			{
				if ((tl <= 0 || tr >= 0) && m[l] > 0 && m[r + 1] < 0)
				{
					ans++;
				}
				if (tl > 0 && tr < 0 && (m[l] <= 0 || m[r + 1] >= 0))
				{
					ans--;
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
