#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int mat[300][300];
bool oc[300][300];
pair<int, int> pos[90000];
int p[90000];
int mx[90000];

int findset(int x)
{
	return x == p[x] ? x : p[x] = findset(p[x]);
}

bool valid(int x, int y)
{
	return x >= 0 && y >= 0 && x < N && y < N;
}

void sim()
{
	int id = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			mat[j][i - j] = id;
			pos[id] = {j, i - j};
			id++;
		}
	}
	for (int i = N - 1; i >= 1; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			mat[N - i + j][N - 1 - j] = id;
			pos[id] = {N - i + j, N - 1 - j};
			id++;
		}
	}
}

char s[30000];

vector<int> getlist()
{
	gets(s);
	int pos = 0;
	vector<int> ret;
	while (s[pos])
	{
		int x;
		sscanf(s + pos, "%d", &x);
		ret.push_back(x - 1);
		for (; s[pos] && s[pos] == ' '; ++pos);
		for (; s[pos] && s[pos] != ' '; ++pos);
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		scanf("%d", &N);
		sim();
		for (int i = 0; i < N * N; ++i)
		{
			p[i] = i;
			mx[i] = i;
		}
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				oc[i][j] = false;
		getchar();
		auto voc = getlist();
		auto op = getlist();
		for (int i = 0; i < voc.size(); ++i)
		{
			int x = pos[voc[i]].first;
			int y = pos[voc[i]].second;
			oc[x][y] = true;
		}
		for (int i = 0; i < voc.size(); ++i)
		{
			int x = pos[voc[i]].first;
			int y = pos[voc[i]].second;
			if (x > 0 && x < N - 1 && !oc[x - 1][y] && !oc[x + 1][y])
			{
				int u = findset(mat[x - 1][y]);
				int v = findset(mat[x + 1][y]);
				p[u] = v;
			}
			if (y > 0 && y < N - 1 && !oc[x][y - 1] && !oc[x][y + 1])
			{
				int u = findset(mat[x][y - 1]);
				int v = findset(mat[x][y + 1]);
				p[u] = v;
			}
			if (x > 0 && x < N - 1 && y > 0 && y < N - 1 && !oc[x - 1][y + 1] && !oc[x + 1][y - 1])
			{
				int u = findset(mat[x + 1][y - 1]);
				int v = findset(mat[x - 1][y + 1]);
				p[u] = v;
			}
		}
		for (int i = 0; i < N * N; ++i)
			mx[findset(i)] = max(mx[findset(i)], i);
		if (kase > 1)
			puts("");
		printf("Case #%d:\n", kase);
		for (int i = 0; i < op.size(); ++i)
		{
			int u = op[i];
			int x = pos[u].first;
			int y = pos[u].second;
			int ans = mx[findset(u)];
			if (x > 0 && !oc[x - 1][y])
				ans = max(ans, mat[x - 1][y]);
			if (x < N - 1 && !oc[x + 1][y])
				ans = max(ans, mat[x + 1][y]);
			if (y > 0 && !oc[x][y - 1])
				ans = max(ans, mat[x][y - 1]);
			if (y < N - 1 && !oc[x][y + 1])
				ans = max(ans, mat[x][y + 1]);
			if (x > 0 && y < N - 1 && !oc[x - 1][y + 1])
				ans = max(ans, mat[x - 1][y + 1]);
			if (y > 0 && x < N - 1 && !oc[x + 1][y - 1])
				ans = max(ans, mat[x + 1][y - 1]);
			printf("%d\n", ans + 1);
		}
	}
	return 0;
}
