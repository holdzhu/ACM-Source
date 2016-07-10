#include <iostream>
#include <cstdio>
#include "BigN.cpp"

using namespace std;

int N, J;
bigN ans[11];

const bigN ONE(1);
const bigN ZERO(0);

bigN gcd(bigN a, bigN b)
{
	bigN remiander;
	while (b != ZERO)
	{
		remiander = divmod(a, b).second;
		a = b;
		b = remiander;
	}
	return a;
}

void g(const bigN &n, bigN &x)
{
	x *= x;
	x += 1;
	x %= n;
}

bool check(int base, const bigN &bn)
{
	bigN x = 2, y = 2, d = 1;
	// printf("start!\n");
	while (d == ONE)
	{
		g(bn, x);
		g(bn, y);
		g(bn, y);
		d = gcd((x - y).abs(), bn);
		// cout << x << ' ' << y << ' ' << d << ' ' << (x - y).abs() << endl;
	}
	// printf("end!\n");
	// cout << d << endl;
	if (d == bn)
		return false;
	ans[base] = d;
	return true;
}

bigN n;

bool check(long long x)
{
	// printf("!!! %lld\n", x);
	for (int base = 2; base <= 10; ++base)
	{
		n = 0;
		for (int i = N - 1; i >= 0; --i)
		{
			n *= base;
			n += x >> i & 1;
		}
		// cout << n << endl;
		if (!check(base, n))
			return false;
	}
	return true;
}

int main()
{
	int T;
	scanf("%d", &T);
	T = 1;
	for (int kase = 1; kase <= T; ++kase)
	{
		scanf("%d %d", &N, &J);
		// N = 16;
		// J = 50;
		printf("Case #%d:\n", kase);
		long long x = (1ll << (N - 1)) + 1;
		// x = 57;
		long long top = 1ll << N;
		int cnt = 0;
		while (x < top && cnt < J)
		{
			if (check(x))
			{
				cout << n;
				for (int base = 2; base <= 10; ++base)
				{
					cout << ' ' << ans[base];
				}
				cout << '\n';
				cnt++;
			}
			// scanf("%*d");
			x += 2;
		}
	}
	return 0;
}
