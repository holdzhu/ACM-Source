#include <cstdio>

char s[500][501];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s[i]);
	}
	int sx, sy, ex, ey;
	scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
	sx--;
	sy--;
	ex--;
	ey--;
	
	return 0;
}
