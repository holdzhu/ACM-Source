#include <cstdio>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		char s[101];
		double maxc = 0;
		int maxv = 0;
		while (n--)
		{
			char t[101];
			int p, v;
			scanf("%s %d %d", t, &p, &v);
			if (v >= 1200)
			{
				v = 1199;
			}
			else if (v < 200)
			{
				continue;
			}
			if ((v / 200) * 1.0 / p > maxc || ((v / 200) * 1.0 / p == maxc && v > maxv))
			{
				maxc = (v / 200) * 1.0 / p;
				maxv = v;
				strcpy(s, t);
			}
		}
		printf("%s\n", s);
	}
	return 0;
}
