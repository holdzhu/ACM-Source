#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int mi, mx;
	scanf("%d", &mi);
	mx = mi;
	while (--n)
	{
		int t;
		scanf("%d", &t);
		mi = min(mi, t);
		mx = max(mx, t);
	}
	printf("%d %d\n", mi, mx);
	return 0;
}
