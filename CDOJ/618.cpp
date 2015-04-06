#include <cstdio>
#include <set>
using namespace std;

int main()
{
	int T;
	set<long long> s;
	for (long long i = 2; i < 1e3; ++i)
	{
		long long sq = i * i;
		printf("%lld\n", sq);
		if (!s.count(sq))
		{
			for (long long j = sq * sq; j < 1e12; j += sq)
			{
				s.insert(j);
			}
		}
	}
	scanf("%d", &T);
	while (T--)
	{
		long long n;
		scanf("%lld", &n);
		printf("%lld\n", n - distance(s.begin(), s.lower_bound(n)));
	}
	return 0;
}
