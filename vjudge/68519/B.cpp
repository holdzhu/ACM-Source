#include <cstdio>
#include <cstring>

char s[300001];

int main()
{
	while (scanf("%s", s) == 1)
	{
		int l = strlen(s);
		char t = s[0];
		for (int i = 0; i < l - 1; ++i)
		{
			s[i] = (s[i + 1] - s[i] + 8) % 8;
		}
		s[l - 1] = (t - s[l - 1] + 8) % 8;
		int f = 0;
		int r = 1;
		while (f < l && r < l)
		{
			if (s[f] < s[r])
			{
				r++;
			}
			else if (s[f] > s[r])
			{
				f = r;
				r++;
			}
			else
			{
				int k = 1;
				while (k < l && s[(f + k) % l] == s[(r + k) % l])
				{
					k++;
				}
				if (k == l)
				{
					break;
				}
				if (s[(f + k) % l] < s[(r + k) % l])
				{
					r += k + 1;
				}
				else
				{
					f = r;
					r += k + 1;
				}
			}
		}
		for (int i = f; i < l; ++i)
		{
			putchar('0' + s[i]);
		}
		for (int i = 0; i < f; ++i)
		{
			putchar('0' + s[i]);
		}
		putchar('\n');
	}
	return 0;
}
