#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int m;
	scanf("%d", &m);
	int cnt2 = 0, cnt5 = 0;
	int l = -1, r;
	for (int i = 1; ; ++i)
	{
		int t = i;
		while (t % 2 == 0)
			cnt2++, t /= 2;
		while (t % 5 == 0)
			cnt5++, t /= 5;
		if (l == -1 && min(cnt2, cnt5) >= m)
			l = i;
		if (min(cnt2, cnt5) > m)
		{
			r = i - 1;
			break;
		}
	}
	printf("%d\n", r - l + 1);
	for (int i = l; i <= r; ++i)
		printf("%d ", i);
	return 0;
}
