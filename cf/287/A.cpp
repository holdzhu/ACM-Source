#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int a[100];
int p[100];

bool cmp(const int x, const int y)
{
	return a[x] < a[y];
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		p[i] = i;
		scanf("%d", &a[i]);
	}
	sort(p, p + n, cmp);
	int s = 0;
	set<int> se;
	for (int i = 0; ; ++i)
	{
		if (s + a[p[i]] <= k)
		{
			se.insert(p[i] + 1);
			s += a[p[i]];
		}
		else
		{
			break;
		}
	}
	printf("%u\n", se.size());
	if (se.size())
	{
		bool first = false;
		for (set<int>::iterator i = se.begin(); i != se.end(); ++i)
		{
			if (first)
			{
				printf(" ");
			}
			else
			{
				first = true;
			}
			printf("%d", *i);
		}
		printf("\n");
	}
	return 0;
}
