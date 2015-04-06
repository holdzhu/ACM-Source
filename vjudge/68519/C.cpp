#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int a[1000000];
int p[1000000];

bool cmp(const int x, const int y)
{
	return a[x] < a[y] || (a[x] == a[y] && x < y);
}

int main()
{
	int n, k1, k2, C = 1;
	while (scanf("%d %d %d", &n, &k1, &k2) == 3 && n)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			p[i] = i;
		}
		sort(p, p + n, cmp);
		printf("Case %d\n", C++);
		set<int> low;
		for (int i = 0; i < k1; ++i)
		{
			low.insert(p[i] + 1);
		}
		bool first = true;
		for (set<int>::iterator i = low.begin(); i != low.end(); ++i)
		{
			if (first)
			{
				first = false;
			}
			else
			{
				printf(" ");
			}
			printf("%d", *i);
		}
		printf("\n");
		set<int> high;
		for (int i = 0; i < k2; ++i)
		{
			high.insert(- p[n - i - 1] - 1);
		}
		first = true;
		for (set<int>::iterator i = high.begin(); i != high.end(); ++i)
		{
			if (first)
			{
				first = false;
			}
			else
			{
				printf(" ");
			}
			printf("%d", -*i);
		}
		printf("\n");
	}
	return 0;
}
