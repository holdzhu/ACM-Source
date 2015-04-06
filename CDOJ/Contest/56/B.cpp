#include <cstdio>
#include <algorithm>

using namespace std;

int a[10000];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int n;
		scanf("%d", &n);
		int pos = 0;
		for (int i = 0; i < n; ++i)
		{
			int t;
			scanf("%d", &t);
			if (t > 1)
			{
				a[pos++] = t;
			}
		}
		printf("Case #%d: ", kase);
		if (pos <= 1)
		{
			printf("Good Function\n");
		}
		else
		{
			sort(a, a + pos);
			for (int i = a[pos - 1] + 1; ; ++i)
			{
				
			}
		}
	}
	return 0;
}
