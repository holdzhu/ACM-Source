#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> dp[2001][26];
int q[2000];
pair<int, int> ans[2001][2001];
int nxt[2001][26];

inline pair<int, int> jump(pair<int, int> p, char c)
{
	if (p.first < m)
	{
		p.second = dp[q[p.first]][c - 'a'][p.second];
		if (p.second == -1)
		{
			p.first = nxt[p.first + 1][c - 'a'];
			if (p.first < m)
				p.second = dp[q[p.first]][c - 'a'][0];
		}
	}
	return p;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < 26; ++j)
		{
			dp[i][j].resize(s.size() + 1);
			dp[i][j][s.size()] = -1;
			for (int k = s.size() - 1; k >= 0; --k)
				dp[i][j][k] = s[k] == j + 'a' ? k + 1 : dp[i][j][k + 1];
		}
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
		cin >> q[i], q[i]--;
	for (int i = 0; i < 26; ++i)
	{
		nxt[m][i] = m;
		for (int j = m - 1; j >= 0; --j)
			nxt[j][i] = dp[q[j]][i][0] == -1 ? nxt[j + 1][i] : j;
	}
	string s;
	cin >> s;
	for (int i = 0; i <= s.size(); ++i)
		for (int j = 0; j <= s.size(); ++j)
			ans[i][j] = make_pair(1e9, 1e9);
	ans[0][0] = make_pair(0, 0);
	for (int i = 1; i <= s.size(); ++i)
		for (int j = 0; j <= i; ++j)
		{
			ans[i][j] = min(ans[i][j], ans[i - 1][j]);
			if (j)
				ans[i][j] = min(ans[i][j], jump(ans[i - 1][j - 1], s[i - 1]));
		}
	for (int i = s.size(); i >= 0; --i)
		if (ans[s.size()][i].first < m)
		{
			cout << i << '\n';
			break;
		}
	return 0;
}
