#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, p;
		scanf("%d %d", &n, &p);
		char s[n + 1];
		bool a[n];
		memset(a, 0, sizeof(a));
		int b = 0;
		int maxb = 0;
		scanf("%s", s);
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == '1')
			{
				a[i] = true;
			}
			else if (s[i] == '2')
			{
				for (int j = max(0, i - p); j < i; ++j)
				{
					if (a[j])
					{
						b += 2;
						a[j] = false;
						break;
					}
				}
			}
			int _b = 0;
			for (int j = max(0, i - p + 1); j <= i; ++j)
			{
				if (a[j])
				{
					_b++;
				}
			}
			if (maxb < b + _b)
			{
				maxb = b + _b;
			}
		}
		printf("%d\n", maxb);
	}
	return 0;
}
