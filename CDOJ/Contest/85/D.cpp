#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int l = 1e9;
	int r = -1e9;
	int b = 1e9;
	int t = -1e9;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		l = min(l, x);
		r = max(r, x);
		b = min(b, y);
		t = max(t, y);
	}
	printf("%lld\n", 1ll * max(max(r - l, t - b), 0) * max(max(r - l, t - b), 0));
	return 0;
}
