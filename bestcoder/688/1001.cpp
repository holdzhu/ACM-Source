#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		bool one = false, zero = false;
		for (int i = 0; i < n; ++i)
		{
			int t;
			scanf("%d", &t);
			if (t == 1)
				one = true;
			if (t == 0)
				zero = true;
		}
		puts(one && zero ? "YES" : "NO");
	}
	return 0;
}
