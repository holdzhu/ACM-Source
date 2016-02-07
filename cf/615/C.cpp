#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <stack>

using namespace std;

const int mod1 = 207;

struct Hash
{
	long long hsh1, l, r;
	Hash(long long hsh1 = 0, int l = 0, int r = 0) : hsh1(hsh1), l(l), r(r)
	{
	}
	bool operator < (const Hash& rhs) const
	{
		return hsh1 < rhs.hsh1;
	}
};

char s[2200], t[2200];
set<Hash> len[2200];
stack<pair<int, int> > ans;
int n, m;

void init()
{
	for (int i = 0; i < n; ++i)
	{
		long long hsh1 = 0;
		for (int j = i; j < n; ++j)
		{
			hsh1 = hsh1 * mod1 + (s[j] - 'a');
			len[j - i + 1].insert(Hash(hsh1, j, i));
		}
	}
	for (int i = n - 1; i >= 0; --i)
	{
		long long hsh1 = 0;
		for (int j = i; j >= 0; --j)
		{
			hsh1 = hsh1 * mod1 + (s[j] - 'a');
			len[i - j + 1].insert(Hash(hsh1, j, i));
		}
	}
}

int dp[2200];
pair<int, int> pre[2200];

int main()
{
	scanf("%s %s", s, t);
	n = strlen(s);
	m = strlen(t);
	init();
	dp[0] = 0;
	for (int i = 1; i <= m; ++i)
	{
		long long hsh1 = 0;
		dp[i] = 1e9;
		for (int j = i - 1; j >= 0; --j)
		{
			hsh1 = hsh1 * mod1 + (t[j] - 'a');
			set<Hash>::iterator it = len[i - j].find(Hash(hsh1));
			if (it != len[i - j].end())
			{
				if (dp[i] > dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
					pre[i] = make_pair(it->l, it->r);
				}
			}
		}
	}
	if (dp[m] == 1e9)
	{
		puts("-1");
	}
	else
	{
		printf("%d\n", dp[m]);
		int t = m;
		for (int i = 0; i < dp[m]; ++i)
		{
			int l = pre[t].first;
			int r = pre[t].second;
			ans.push(pre[t]);
			t -= abs(l - r) + 1;
		}
		for (int i = 0; i < dp[m]; ++i)
		{
			pair<int, int> p = ans.top();
			ans.pop();
			printf("%d %d\n", p.first + 1, p.second + 1);
		}
	}
	return 0;
}
