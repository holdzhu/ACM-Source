#include <cstdio>
#include <set>

using namespace std;

int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}

struct Fraction
{
	int numerator, denominator;
	bool operator < (const Fraction& rhs) const
	{
		return numerator * rhs.denominator < denominator * rhs.numerator;
	}
	void print()
	{
		printf("%d/%d\n", numerator, denominator);
	}
	void simplify()
	{
		int g = gcd(numerator, denominator);
		numerator /= g;
		denominator /= g;
	}
};

set<Fraction> ans;

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i <= N; ++i)
	{
		for (int j = i + 1; j <= N; ++j)
		{
			Fraction t = (Fraction){i, j};
			t.simplify();
			ans.insert(t);
		}
	}
	for (Fraction f : ans)
	{
		f.print();
	}
	printf("1/1\n");
	return 0;
}
