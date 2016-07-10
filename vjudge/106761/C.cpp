#include <iostream>
#include <algorithm>

using namespace std;

string s[15];
int nxt[500002][15];
int dp[1 << 15][106];

inline void update(int &data, int val)
{
	if (data > val)
		data = val;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	int m;
	cin >> m;
	int ans = 0;
	int idx;
	for (int i = 0; i < m; ++i)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j)
		{
			string t;
			cin >> t;
			for (int l = 0; l < n; ++l)
				nxt[j][l] = t == s[l];
		}
		for (int j = 0; j < n; ++j)
			nxt[k][j] = nxt[k + 1][j] = k;
		for (int j = k - 1; j >= 0; --j)
			for (int l = 0; l < n; ++l)
				nxt[j][l] = nxt[j][l] ? j : nxt[j + 1][l];
		for (int j = 0; j < (1 << n); ++j)
			for (int l = 0, _ = __builtin_popcount(j); l <= _ * (_ - 1) / 2; ++l)
				dp[j][l] = k;
		dp[0][0] = -1;
		for (int j = 0; j < (1 << n); ++j)
			for (int l = 0, _ = __builtin_popcount(j); l <= _ * (_ - 1) / 2; ++l)
				for (int p = 0; p < n; ++p)
					if (!(j >> p & 1))
						update(dp[j | (1 << p)][l + __builtin_popcount(j >> p)], nxt[dp[j][l] + 1][p]);	
		for (int j = 0; j <= n * (n - 1) / 2; ++j)
			if (dp[(1 << n) - 1][j] < k)
				if (ans < n * (n - 1) / 2 - j + 1)
				{
					ans = n * (n - 1) / 2 - j + 1;
					idx = i + 1;
				}
	}
	if (ans)
	{
		cout << idx << "\n[:";
		while (ans--)
			cout << '|';
		cout << ":]\n";
	}
	else
		cout << "Brand new problem!\n";
	return 0;
}
