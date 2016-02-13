#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<int> G[26];
vector<int> ans;

char s[2][101];
int deg[26];
int p[26];

int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", s[0]);
	bool cur = 0;
	bool flag = true;
	for (int i = 0; i < n - 1; ++i)
	{
		cur ^= 1;
		scanf("%s", s[cur]);
		int j = 0;
		while (s[0][j] == s[1][j])
		{
			j++;
		}
		if (s[cur][j] == 0)
		{
			flag = false;
		}
		else if (s[cur][j] == 0)
		{
			continue;
		}
		G[s[cur ^ 1][j] - 'a'].push_back(s[cur][j] - 'a');
	}
	if (!flag)
	{
		puts("Impossible");
		return 0;
	}
	for (int i = 0; i < 26; ++i)
	{
		for (int v: G[i])
		{
			deg[v]++;
		}
	}
	queue<int> q;
	for (int i = 0; i < 26; ++i)
	{
		if (deg[i] == 0)
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		ans.push_back(u);
		for (int v: G[u])
		{
			if (--deg[v] == 0)
			{
				q.push(v);
			}
		}
	}
	if (ans.size() == 26)
	{
		for (int i = 0; i < 26; ++i)
		{
			printf("%c", ans[i] + 'a');
		}
		printf("\n");
	}
	else
	{
		printf("Impossible\n");
	}
	return 0;
}
