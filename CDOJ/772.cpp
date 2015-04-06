#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		int Xp, Yp, Xt, Yt;
		scanf("%d %d %d %d", &Xp, &Yp, &Xt, &Yt);
		int c = Xp + Yp + Xt + Yt;
		char s[10];
		scanf("%s", s);
		if (s[0] == 't')
		{
			c++;
		}
		if (c % 2 || n == 1 || m == 1 || (Xp == Xt && Yp == Yt))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
