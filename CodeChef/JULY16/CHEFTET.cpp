#include <cstdio>

int n;
int a[10000], b[10000];
int mx;

void check(int x)
{
	
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < n; ++i)
			scanf("%d", &b[i]);
		mx = -1;
		check(b[0]);
		check(b[0] + a[0]);
		if (n > 1)
			check(b[0] + a[1]);
		printf("%d\n", mx);
	}
	return 0;
}
