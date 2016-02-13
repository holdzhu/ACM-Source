#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, s;
		scanf("%d %d", &n, &s);
		if (n == 1 && s == 0)
		{
			puts("0 0");
		}
		else if (s > n * 9 || s == 0)
		{
			puts("-1 -1");
		}
		else
		{
			int _s = s;
			for (int i = 0; i < n; ++i)
			{
				int m = max(s - (n - i - 1) * 9, int(i == 0));
				putchar(m + '0');
				s -= m;
			}
			putchar(' ');
			s = _s;
			for (int i = 0; i < n; ++i)
			{
				int m = min(s, 9);
				putchar(m + '0');
				s -= m;
			}
			putchar('\n');
		}
	}
	return 0;
}
