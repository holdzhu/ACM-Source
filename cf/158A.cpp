#include <cstdio>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int cnt = 0;
	int last;
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		if (t > 0 && (i < k || t == last))
			cnt++;
		else
			break;
		last = t;
	}
	printf("%d\n", cnt);
	return 0;
}
