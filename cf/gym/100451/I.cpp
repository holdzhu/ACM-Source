#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int endcount = 20;
const int trytimes = 20;
const float ratio = 0.9f;

int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}

int solve(vector<int> a, int n)
{
	if (a.size() <= endcount)
	{
		map<int, int> times;
		for (int i = 0; i < a.size(); ++i)
		{
			for (int j = 0; j < a.size(); ++j)
			{
				if (i == j)
				{
					continue;
				}
				int d = (a[i] - a[j] + n) % n;
				if (gcd(d, n) == 1 && ++times[d] == a.size() - 1)
				{
					return d;
				}
			}
		}
		return -1;
	}
	for (int tries = 0; tries < trytimes; ++tries)
	{
		int center = rand() % a.size();
		vector<int> b;
		for (int i = 1; i < a.size(); ++i)
		{
			b.push_back((a[(center + i) % a.size()] - a[center] + n) % n);
		}
		vector<int> c;
		for (int i = 0; i < b.size(); ++i)
		{
			if (!binary_search(b.begin(), b.end(), n - b[i]))
			{
				c.push_back(b[i]);
			}
		}
		if (c.size() > 1 && c.size() <= a.size() * ratio)
		{
			return solve(c, n);
		}
	}
	return -1;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> a;
	vector<int> b;
	int g = n;
	for (int i = 0; i < m; ++i)
	{
		int t;
		scanf("%d", &t);
		a.push_back(t);
		if (i)
		{
			g = gcd(g, t - a[i - 1]);
		}
	}
	if (m == 1)
	{
		printf("%d 1\n", a[0]);
		return 0;
	}
	if (m == n / g)
	{
		printf("%d %d\n", a[0], g);
		return 0;
	}
	for (int i = 0; i < m; ++i)
	{
		b.push_back(a[i] / g);
	}
	int d = solve(b, n / g);
	if (d == -1)
	{
		printf("-1 -1\n");
		return 0;
	}
	d *= g;
	int cnt = 0;
	int last = a[0];
	for (int i = 0; i < m; ++i)
	{
		if (!binary_search(a.begin(), a.end(), (a[i] + d) % n))
		{
			cnt++;
			last = a[i];
		}
	}
	if (cnt <= 1)
	{
		printf("%d %d\n", last, n - d);
	}
	else
	{
		printf("-1 -1\n");
	}
	return 0;
}
