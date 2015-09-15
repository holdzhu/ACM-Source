#include <cstdio>
#include <algorithm>

using namespace std;

int h[100000];
int left[100000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &h[i]);
	}
	int mi = 0;
	for (int i = 0; i < n; ++i)
	{
		mi++;
		mi = min(mi, h[i]);
		left[i] = mi;
	}
	mi = 0;
	int ans = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		mi++;
		mi = min(mi, h[i]);
		ans = max(ans, min(left[i], mi));
	}
	printf("%d\n", ans);
	return 0;
}
