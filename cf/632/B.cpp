#include <cstdio>
#include <algorithm>

using namespace std;

int p[500000];
char s[500001];
long long sumA[500001];
long long sumB[500001];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &p[i]);
	scanf("%s", s);
	for (int i = n - 1; i >= 0; --i)
	{
		sumA[i] = sumA[i + 1] + (s[i] == 'A') * p[i];
		sumB[i] = sumB[i + 1] + (s[i] == 'B') * p[i];
	}
	long long ans = 0;
	for (int i = 0; i <= n; ++i)
		ans = max(ans, sumB[0] - sumB[i] + sumA[i]),
		ans = max(ans, sumA[0] - sumA[i] + sumB[i]);
	printf("%I64d\n", ans);
	return 0;
}
