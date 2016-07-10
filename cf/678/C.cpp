#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	int n, a, b, p, q;
	scanf("%d %d %d %d %d", &n, &a, &b, &p, &q);
	int ca = n / a;
	int cb = n / b;
	long long g = __gcd(a, b);
	long long lcm = 1ll * a * b / g;
	int cc = n / lcm;
	printf("%I64d\n", max(1ll * ca * p + 1ll * (cb - cc) * q,
						  1ll * (ca - cc) * p + 1ll * cb * q));
	return 0;
}
