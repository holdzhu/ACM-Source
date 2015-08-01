#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long n, m, p, q;
		scanf("%I64d %I64d %I64d %I64d", &n, &m, &p, &q);
		printf("%I64d\n", min(min(n * p, n / m * q + (n - n / m * m) * p), (n / m + 1) * q));
	}
	return 0;
}
