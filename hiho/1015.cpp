#include <cstdio>

char par[10001];
char ori[1000001];
int next[10001];

int main()
{
	int N;
	scanf("%d", &N);
	next[0] = -1;
	while (N--)
	{
		scanf("%s %s", par, ori);
		int l;
		for (l = 0; par[l]; ++l)
		{
			int q = next[l];
			while (q >= 0 && par[q] != par[l])
			{
				q = next[q];
			}
			next[l + 1] = q + 1;
		}
		int q = 0;
		int ans = 0;
		for (int i = 0; ori[i]; ++i)
		{
			while (q >= 0 && par[q] != ori[i])
			{
				q = next[q];
			}
			q++;
			if (q == l)
			{
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
