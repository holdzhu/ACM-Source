#include <cstdio>
#include <algorithm>

using namespace std;

char s[100001];

int main()
{
	int n, k;
	scanf("%d %d %s", &n, &k, s);
	int rem = 0;
	for (int i = 0; i < n; ++i)
		rem += max(s[i] - 'a', 'z' - s[i]);
	if (rem < k)
		puts("-1");
	else
	{
		for (int i = 0; i < n; ++i)
		{
			rem -= max(s[i] - 'a', 'z' - s[i]);
			for (char j = 'a'; j <= 'z'; ++j)
				if (k - abs(j - s[i]) >= 0 && k - abs(j - s[i]) <= rem)
				{
					k -= abs(j - s[i]);
					putchar(j);
					break;
				}
		}
		puts("");
	}
	return 0;
}
