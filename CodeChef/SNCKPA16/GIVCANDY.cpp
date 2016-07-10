#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long A, B, C, D;
		scanf("%lld %lld %lld %lld", &A, &B, &C, &D);
		long long g = __gcd(C, D);
		long long delta = abs(A - B);
		printf("%lld\n", min(delta % g, g - delta % g));
	}
	return 0;
}
