#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

set<int> s;
int n;
int a[100000];

int main()
{
	for (long long i = 1; i <= 1e9; i *= 2)
	{
		for (long long j = 1; j <= 1e9; j *= 3)
		{
			if (i * j <= 1e9)
			{
				s.insert(i * j);
			}
		}
	}
	scanf("%d", &n);
	int g = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		g = __gcd(g, a[i]);
	}
	bool flag = true;
	for (int i = 0; i < n; ++i)
	{
		if (!s.count(a[i] / g))
		{
			flag = false;
			break;
		}
	}
	puts(flag ? "Yes" : "No");
	return 0;
}
