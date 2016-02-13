#include <cstdio>

int a[100];

long long solve(long long n, int k)
{
	if (k == -1)
		return n;
	return solve(n / k, k - 1)
}

int main()
{
	long long n;
	int k;
	scanf("%I64d %d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	return 0;
}
