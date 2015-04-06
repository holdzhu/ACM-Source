#include <cstdio>
#include <cstring>

char T[50001];
char P[50001];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", T);
		scanf("%s", P);
		int n = strlen(T);
		int m = strlen(P);
		int f[m + 1];
		f[0] = 0;
		f[1] = 0;
		for (int i = 1; i < m; ++i)
		{
			int j = f[i];
			while (j && P[i] != P[j])
			{
				j = f[j];
			}
			f[i + 1] = P[i] == P[j] ? j + 1 : 0;
		}
		int j = 0;
		int ans = 1;
		for (int i = 0; i < n; ++i)
		{
			while (j && P[j] != T[i])
			{
				j = f[j];
			}
			if (P[j] == T[i])
			{
				j++;
			}
			if (i == n - 1)
			{
				while (j)
				{
					j = f[j];
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
