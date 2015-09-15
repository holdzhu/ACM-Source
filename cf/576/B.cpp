#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > perm;
int p[100001];

bool cmp(const vector<int>& A, const vector<int>& B)
{
	return A.size() < B.size();
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &p[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (p[i] > 0)
		{
			vector<int> pt;
			int t = i;
			while (p[t] > 0)
			{
				pt.push_back(t);
				int tt = p[t];
				p[t] = 0;
				t = tt;
			}
			perm.push_back(pt);
		}
	}
	sort(perm.begin(), perm.end(), cmp);
	if (perm[0].size() > 2)
	{
		puts("NO");
		return 0;
	}
	for (int i = 1; i < perm.size(); ++i)
	{
		if (perm[i].size() % perm[0].size() != 0)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	if (perm[0].size() == 2)
	{
		printf("%d %d\n", perm[0][0], perm[0][1]);
	}
	for (int i = 1; i < perm.size(); ++i)
	{
		for (int j = 0; j < perm[i].size(); ++j)
		{
			printf("%d %d\n", perm[0][j % perm[0].size()], perm[i][j]);
		}
	}
	return 0;
}
