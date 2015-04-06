#include <cstdio>
#include <cstring>

char stra[100001];
char strb[100001];
int next[100001];
int ns[100001];

int main()
{
	int k;
	next[0] = -1;
	while (scanf("%s %s %d", stra, strb, &k) == 3)
	{
		int l;
		for (l = 0; strb[l]; ++l)
		{
			int q = next[l];
			while (q >= 0 && strb[q] != stra[l])
			{
				q = next[q];
			}
			next[l + 1] = q + 1;
		}
		int q = 0;
		int t = 0;
		int ans = 0;
		memset(ns, 0, sizeof(ns));
		int p = 0;
		for (int i = 0; stra[i]; ++i)
		{
			if (strb[q] != stra[i])
			{
				t++;
				ns[p++] = i;
			}
			while (q >= 0 && t > k)
			{
				q = next[q];
				for (int j = 0; j < k; ++j)
				{
					if (ns[p - j - 1] <= i - q)
					{
						t -= k - j;
						break;
					}
				}
			}
			printf("%d %d %d\n", i, q, t);
			q++;
			if (q == l)
			{
				ans++;
				q--;
				for (int j = 0; j < k; ++j)
				{
					if (ns[p - j - 1] <= i - q)
					{
						t -= k - j;
						break;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
