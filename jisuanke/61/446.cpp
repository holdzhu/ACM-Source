#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long Ew, Ex, Ey, Ez, w, x, y, z;
		scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &Ew, &Ex, &Ey, &Ez, &w, &x, &y, &z);
		long long ans = 1000000000000000000LL;
		for (int i = 0; i <= Ey; ++i)
		{
			long long A = Ew * w + i * y;
			long long B = Ex * x + (Ey - i) * y;
			int l = 0;
			int r = Ez;
			while (l < r)
			{
				int m = (l + r + 1) >> 1;
				if (A + m * z < B + (Ez - m) * z)
				{
					l = m;
				}
				else
				{
					r = m - 1;
				}
			}
			ans = min(ans, max(A + l * z, B + (Ez - l) * z));
			if (l < Ez)
			{
				ans = min(ans, max(A + (l + 1) * z, B + (Ez - l - 1) * z));
			}
			if (l > 0)
			{
				ans = min(ans, max(A + (l - 1) * z, B + (Ez - l + 1) * z));
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
