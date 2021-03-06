#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int s[1000000];
int post[1000001];

queue<long long> q;

int main()
{
	memset(post, -1, sizeof post);
	int la, lb;
	scanf("%d %d", &la, &lb);
	for (int i = 0; i < la; ++i)
	{
		scanf("%d", &s[i]);
	}
	for (int i = 0; i < lb; ++i)
	{
		int t;
		scanf("%d", &t);
		post[t] = i;
	}
	int ans = 0;
	for (int i = 0; i < la * 2; ++i)
	{
		if (post[s[i % la]] == -1)
		{
			while (q.size())
				q.pop();
		}
		else
		{
			long long p = post[s[i % la]];
			if (q.size() && p <= q.back())
			{
				p += (q.back() - p + lb) / lb * lb;
			}
			q.push(p);
			while (p - q.front() >= lb)
				q.pop();
		}
		ans = max(ans, (int)q.size());
	}
	printf("%d\n", ans);
	return 0;
}
