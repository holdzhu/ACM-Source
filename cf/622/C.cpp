#include <cstdio>

int nxt[200001];
int a[200001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	a[n] = -1;
	for (int i = n - 1; i >= 0; --i)
		nxt[i] = a[i] == a[i + 1] ? nxt[i + 1] : i;
	while (m--)
	{
		int l, r, x;
		scanf("%d %d %d", &l, &r, &x);
		if (a[l - 1] != x)
			printf("%d\n", l);
		else if (nxt[l - 1] + 1 < r)
			printf("%d\n", nxt[l - 1] + 2);
		else
			printf("-1\n");
	}
	return 0;
}
