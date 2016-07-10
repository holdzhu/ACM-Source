#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 1e6;

long long read()
{
	long long ans = 0;
	char last = ' ', ch = getchar();
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ans = ans * 10 + ch - '0', ch = getchar();
	if (last == '-')
		ans = -ans;
	return ans;
}

long long a[maxn + 1];
int f[maxn + 1];
int last[maxn + 1];
int p[maxn + 1];
bool no[maxn + 1];
int cnt;
vector<pair<int, int> > v[maxn + 1];
long long ans;

void dfs(int x, int i = 0, int d = 1)
{
	if (i == v[x].size())
	{
		ans += f[x / d] * a[d];
		return;
	}
	for (int j = 0; j <= v[x][i].second; ++j)
	{
		dfs(x, i + 1, d);
		d *= v[x][i].first;
	}
}

int main()
{
	int n = read();
	int q = read();
	for (int i = 1; i <= n; ++i)
		f[i] = last[i] = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (!no[i])
		{
			p[cnt++] = i;
			last[i] = 2;
			v[i].emplace_back(i, 1);
		}
		for (int j = 0; j < cnt && p[j] * i <= n; ++j)
		{
			no[i * p[j]] = true;
			v[i * p[j]] = v[i];
			if (i % p[j] == 0)
			{
				f[i * p[j]] = f[i];
				last[i * p[j]] = last[i] + 1;
				++v[i * p[j]].back().second;
				break; 
			}
			f[i * p[j]] = f[i] * last[i];
			last[i * p[j]] = 2;
			v[i * p[j]].emplace_back(p[j], 1);
		}
	}
	for (int i = 1; i <= n; ++i)
		f[i] *= last[i];
	while (q--)
	{
		int t = read();
		int x = read();
		if (t == 1)
		{
			int y = read();
			a[x] += y;
		}
		else
		{
			ans = 0;
			dfs(x);
			printf("%lld\n", ans);
		}
	}
	return 0;
}
