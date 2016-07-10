#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		bool f1 = false, f2 = false;
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			int u;
			scanf("%d", &u);
			if (u == 2)
				f1 = true;
			if (u == 5)
				f2 = true;
			sum += u;
		}
		if (!f1 && f2 && sum >= 4 * n)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
