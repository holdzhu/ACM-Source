#include <cstdio>
#include <queue>
#include <queue>

using namespace std;

char s[2000][2001];
int dis[2000];
bool vis[2000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", s[i]);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			dis[j] = n;
		dis[i] = 0;

	}
	return 0;
}
