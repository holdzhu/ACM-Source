#include <cstdio>
#include <vector>

using namespace std;

vector<int> factor(int x)
{
	vector<int> ret;
	for (int i = 1; i * i <= x; ++i)
	{
		if (x % i == 0)
		{
			ret.push_back(i);
			if (i * i < x)
				ret.push_back(x / i);
		}
	}
	return ret;
}

bool solve(int a, int b, int c)
{
	vector<int> A = factor(a);
	vector<int> C = factor(c);
	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = 0; j < C.size(); ++j)
		{
			int p = A[i];
			int q = a / p;
			int k = C[j];
			int m = c / k;
			if (1ll * q * k + 1ll * m * p == b)
				return true;
		}
	}
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		puts(solve(a, b, c) ? "YES" : "NO");
	}
	return 0;
}
