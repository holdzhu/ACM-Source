#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	int first1 = -1;
	int firsts = 0;
	int last1 = -1;
	int lasts = 0;
	int s = 0;
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			last1 = i;
			lasts = s;
			if (first1 == -1)
			{
				first1 = i;
				firsts = s;
			}
		}
		s += t;
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int t;
		scanf("%d", &t);
		if (t <= lasts + 1 || t <= s - firsts)
		{
			printf("Yes\n");
		}
		else if (((t - lasts - 1) % 2 == 0 || (t - s + firsts) % 2 == 0) && t <= s)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
