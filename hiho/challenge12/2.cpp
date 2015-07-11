#include <cstdio>
#include <cstring>

bool b[10000001];

int main()
{
	long long n;
	scanf("%lld", &n);
	long long l, r;
	scanf("%lld %lld", &l, &r);
	int cnt = 0;
	memset(b, 0, sizeof b);
	for (int i = 0; i <= r; ++i)
	{
		long long res = i ^ (i * n);
		if (res >= l && res <= r && !b[res])
		{
			b[res] = true;
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
