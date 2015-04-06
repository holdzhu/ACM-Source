#include <cstdio>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		char a[1001], b[1001];
		char s[1001];
		scanf("%s %s", a, b);
		int la = strlen(a) - 1;
		int lb = strlen(b) - 1;
		int l = 0;
		if (kase > 1)
		{
			printf("\n");
		}
		printf("Case %d:\n%s + %s = ", kase, a, b);
		int x, t = 0;
		for (; la >= 0 || lb >= 0; --la, --lb)
		{
			x = t;
			t = 0;
			if (la >= 0)
			{
				x += a[la] - '0';
			}
			if (lb >= 0)
			{
				x += b[lb] - '0';
			}
			t = x / 10;
			s[l++] = x % 10 + '0';
		}
		if (t)
		{
			putchar('1');
		}
		l--;
		for (; l >= 0; --l)
		{
			putchar(s[l]);
		}
		printf("\n");
	}
	return 0;
}
