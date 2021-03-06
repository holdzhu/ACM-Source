#include <cstdio>
#include <cstring>
#include <cstdlib>

struct Pair
{
	int first, second;
	bool operator < (const Pair& rhs) const
	{
		return first < rhs.first || (first == rhs.first && (second < rhs.second));
	}
};

int n, m;
int *dp[2000][26];
int q[2000];
Pair ans[2001][2001];
int nxt[2001][26];
int len;
char s[1000001];

inline Pair& min(Pair& A, Pair& B)
{
	return A < B ? A : B;
}

inline Pair& jump(Pair& p, char c)
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

int c;
inline void readNumber(int& x)
{
	while ((c = getchar()) == ' ' || c == '\n');
	x = c - '0';
	while ((c = getchar()) >= '0')
		x *= 10, x += c - '0';
}

inline void readString()
{
	char* t = s;
	while ((*t = getchar()) == '\n');
	while ((*(++t) = getchar()) != '\n');
	len = t - s;
}

int main()
{
	readNumber(n);
	for (int i = 0; i < n; ++i)
	{
		readString();
		for (int j = 0; j < 26; ++j)
		{
			dp[i][j] = (int *)malloc(sizeof(int) * (len + 1));
			dp[i][j][len] = -1;
			for (int k = len - 1; k >= 0; --k)
				dp[i][j][k] = s[k] == j + 'a' ? k + 1 : dp[i][j][k + 1];
		}
	}
	readNumber(m);
	for (int i = 0; i < m; ++i)
		readNumber(q[i]), q[i]--;
	for (int i = 0; i < 26; ++i)
		for (int j = (nxt[m][i] = m) - 1; j >= 0; --j)
			nxt[j][i] = dp[q[j]][i][0] == -1 ? nxt[j + 1][i] : j;
	readString();
	for (int i = 1; i <= len; ++i)
	{
		ans[i - 1][i].first = 1e9;
		for (int j = 1; j <= i; ++j)
			ans[i][j] = min(ans[i - 1][j], jump(ans[i - 1][j - 1], s[i - 1]));
	}
	for (int i = len; i >= 0; --i)
		if (ans[len][i].first < m)
		{
			printf("%d\n", i);
			return 0;
		}
}
