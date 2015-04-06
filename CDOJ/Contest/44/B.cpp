#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		char s[n + 1];
		scanf("%s", s);
		int s1 = 0;
		int s2 = 1;
		for (int i = n - 1; i >= 0; --i)
		{
			if (s[i] == 'W')
			{
				s1 *= 2;
			}
			else
			{
				s1 *= 2;
				s1 += 1;
			}
			s2 *= 2;
		}
		int t = s2 - s1 - 1;
		int r = 0;
		while (t)
		{
			r += t;
			t /= 2;
		}
		printf("%d\n", r);
	}
	return 0;
}
