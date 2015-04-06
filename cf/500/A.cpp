#include <cstdio>

int main()
{
	int n, t;
	scanf("%d %d", &n, &t);
	int s = 1;
	bool su = (s == t);
	for (int i = 0; i < n - 1; ++i)
	{
		int _t = 0;
		scanf("%d", &_t);
		if (s == i + 1)
		{
			s += _t;
			if (s == t)
			{
				su = true;
			}
		}
	}
	if (su)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}
