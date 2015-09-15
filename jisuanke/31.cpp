#include <cstdio>
#include <cstring>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

int S[3];

bool vis[21][21];

int main()
{
	for (int i = 0; i < 3; ++i)
	{
		scanf("%d", &S[i]);
	}
	queue<pair<int, pair<int, int> > > q;
	memset(vis, false, sizeof vis);
	q.push(make_pair(0, make_pair(0, S[2])));
	while (!q.empty())
	{
		pair<int, pair<int, int> > p = q.front();
		q.pop();
		int s[3] = {p.first, p.second.first, p.second.second};
		if (vis[s[0]][s[2]])
		{
			continue;
		}
		vis[s[0]][s[2]] = true;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (i == j)
				{
					continue;
				}
				if (s[i] > 0 && s[j] < S[j])
				{
					int d = min(s[i], S[j] - s[j]);
					s[i] -= d;
					s[j] += d;
					q.push(make_pair(s[0], make_pair(s[1], s[2])));
					s[i] += d;
					s[j] -= d;
				}
			}
		}
	}
	bool first = true;
	for (int i = 0; i <= S[2]; ++i)
	{
		if (vis[0][i])
		{
			if (first)
			{
				first = false;
			}
			else
			{
				printf(" ");
			}
			printf("%d", i);
		}
	}
	printf("\n");
	return 0;
}
