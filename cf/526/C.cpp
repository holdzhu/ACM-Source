#include <cstdio>
#include <set>

using namespace std;

int main()
{
	int C, Hr, Hb, Wr, Wb;
	scanf("%d %d %d %d %d", &C, &Hr, &Hb, &Wr, &Wb);
	if ((long long)Hr * Wb > (long long)Hb * Wr)
	{
		int maxr = C / Wr;
		set<int> s;
		long long ans = 0;
		for (int r = maxr; r >= 0; --r)
		{
			int b = (C - r * Wr) / Wb;
			int sum = r * Wr + b * Wb;
			if (s.count(sum))
			{
				break;
			}
			s.insert(sum);
			if (ans < (long long)r * Hr + (long long)b * Hb)
			{
				ans = (long long)r * Hr + (long long)b * Hb;
			}
		}
		printf("%I64d\n", ans);
	}
	else
	{
		int maxb = C / Wb;
		set<int> s;
		long long ans = 0;
		for (int b = maxb; b >= 0; --b)
		{
			int r = (C - b * Wb) / Wr;
			int sum = r * Wr + b * Wb;
			if (s.count(sum))
			{
				break;
			}
			s.insert(sum);
			if (ans < (long long)r * Hr + (long long)b * Hb)
			{
				ans = (long long)r * Hr + (long long)b * Hb;
			}
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
