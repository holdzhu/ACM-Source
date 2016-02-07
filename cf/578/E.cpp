#include <cstdio>
#include <cstring>

char s[100010];
int p1[100010];
int p2[100010];
int pl, pr;
int cl, cr;
int ansl, ansr;

int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; ++i)
	{
		if (s[i] == 'L')
		{
			cl++;
		}
		else
		{
			cr++;
		}
	}
	if (cl >= cr)
	{
		for (int i = 0; i <= n; ++i)
		{
			p1[i] = i + 1;
		}
		pl = pr = 0;
		while (p1[pl] <= n)
		{
			if (s[pl] == 'L' && s[p1[pl]] == 'L')
			{
				break;
			}
			pl = p1[pl];
		}
		while (p1[pr] <= n)
		{
			if ((s[pr] == 'R' && s[p1[pr]] == 'R') || (s[p1[pr]] == 'R' && s[pr] == 0))
			{
				break;
			}
			pr = p1[pr];
		}
		while (p1[pl] <= n || p1[pr] <= n)
		{
			if (pr < pl)
			{
				int t = p1[p1[pr]];
				p1[p1[pr]] = p1[pl];
				p1[pl] = p1[pr];
				p1[pr] = t;
			}
			else
			{
				int t = p1[p1[pl]];
				p1[p1[pl]] = p1[pr];
				p1[pr] = p1[pl];
				p1[pl] = t;
			}
			while (p1[pl] <= n)
			{
				if (s[pl] == 'L' && s[p1[pl]] == 'L')
				{
					break;
				}
				pl = p1[pl];
			}
			while (p1[pr] <= n)
			{
				if ((s[pr] == 'R' && s[p1[pr]] == 'R') || (s[p1[pr]] == 'R' && s[pr] == 0))
				{
					break;
				}
				pr = p1[pr];
			}
			ansl++;
		}
	}
	else
	{
		ansl = 1e9;
	}
	if (cl <= cr)
	{
		for (int i = 0; i <= n; ++i)
		{
			p2[i] = i + 1;
		}
		pl = pr = 0;
		while (p2[pl] <= n)
		{
			if (s[pl] == 'R' && s[p2[pl]] == 'R')
			{
				break;
			}
			pl = p2[pl];
		}
		while (p2[pr] <= n)
		{
			if ((s[pr] == 'L' && s[p2[pr]] == 'L') || (s[p2[pr]] == 'L' && s[pr] == 0))
			{
				break;
			}
			pr = p2[pr];
		}
		while (p2[pl] <= n || p2[pr] <= n)
		{
			if (pr < pl)
			{
				int t = p2[p2[pr]];
				p2[p2[pr]] = p2[pl];
				p2[pl] = p2[pr];
				p2[pr] = t;
			}
			else
			{
				int t = p2[p2[pl]];
				p2[p2[pl]] = p2[pr];
				p2[pr] = p2[pl];
				p2[pl] = t;
			}
			while (p2[pl] <= n)
			{
				if (s[pl] == 'R' && s[p2[pl]] == 'R')
				{
					break;
				}
				pl = p2[pl];
			}
			while (p2[pr] <= n)
			{
				if ((s[pr] == 'L' && s[p2[pr]] == 'L') || (s[p2[pr]] == 'L' && s[pr] == 0))
				{
					break;
				}
				pr = p2[pr];
			}
			ansr++;
		}
	}
	else
	{
		ansr = 1e9;
	}
	if (ansl < ansr)
	{
		printf("%d\n", ansl);
		int i = p1[0];
		while (i <= n)
		{
			printf("%d ", i);
			i = p1[i];
		}
		printf("\n");
	}
	else
	{
		printf("%d\n", ansr);
		int i = p2[0];
		while (i <= n)
		{
			printf("%d ", i);
			i = p2[i];
		}
		printf("\n");
	}
	return 0;
}
