#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

long long multi_mod(long long a, long long b, long long c)
{
	a %= c;
	b %= c;
	long long rnt = 0;
	while (b)
	{
		if (b & 1)
		{
			rnt += a;
			if (rnt >= c)
			{
				rnt -= c;
			}
		}
		a <<= 1;
		if (a >= c)
		{
			a -= c;
		}
		b >>= 1;
	}
	return rnt;
}

int main()
{
	srand((int)time(0));
	bool flag = true;
	while (flag)
	{
		long long p, q, r, base;
		ofstream fout("5397.in");
		p = 1ll * rand() * rand() * rand() + 1;
		q = 1ll * rand() * rand() * rand() + 1;
		r = 1ll * rand() * rand() * rand() + 1;
		base = 1ll * rand() * rand() * rand() + 1;
		// p = 1ll * rand() * rand() * rand();
		// q = 1ll * rand() * rand() * rand();
		// r = 1ll * rand() * rand() * rand();
		// base = 1ll * rand() * rand() * rand();
		fout << p << " " << q << " " << r << " " << base << endl;;
		fout.close();
		system("5397.exe < 5397.in > 5397.out");
		ifstream ffin("5397.in");
		ffin >> p >> q >> r >> base;
		ffin.close();
		ifstream fin("5397.out");
		string a, b;
		fin >> a >> b;
		assert(a.size() <= 10000 && b.size() <= 10000 && a.size() == b.size() && a != b);
		long long bb = 1;
		long long sum1 = 0;
		long long sum2 = 0;
		for (int i = 0; i < a.size(); ++i)
		{
			assert(multi_mod(p, bb, r) >= 0 && multi_mod(p, bb, r) < r);
			assert(multi_mod(q, bb, r) >= 0 && multi_mod(q, bb, r) < r);
			if (a[i] == '(')
			{
				sum1 = (sum1 + multi_mod(p, bb, r)) % r;
			}
			else
			{
				sum1 = (sum1 + multi_mod(q, bb, r)) % r;
			}
			if (b[i] == '(')
			{
				sum2 = (sum2 + multi_mod(p, bb, r)) % r;
			}
			else
			{
				sum2 = (sum2 + multi_mod(q, bb, r)) % r;
			}
			bb = multi_mod(bb, base, r);
		}
		cout << sum1 << " " << sum2 << endl;
		assert(sum1 == sum2);
	}
	return 0;
}
