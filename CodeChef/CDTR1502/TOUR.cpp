#include <cstdio>
#include <cstring>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main()
{
	int n, s;
	scanf("%d %d", &s, &n);
	int d[s + 1];
	memset(d, 0, sizeof(d));
	while (n--)
	{
		int v, w;
		scanf("%d %d", &v, &w);
		for (int i = s; i >= v; --i)
		{
			d[i] = max(d[i], d[i - v] + w);
		}
	}
	int a = 0;
	for (int i = 0; i <= s; ++i)
	{
		a = max(a, d[i]);
	}
	printf("%d\n", a);
	return 0;
}
