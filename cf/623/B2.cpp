#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

map<int, long long> ma[2][3];
int A[1000000];

int main()
{
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 0; i < n; ++i)
		scanf("%d", &A[i]);
	ma[0][0][0] = 0;
	auto &x = ma[1];
	auto &y = ma[0];
	for (int i = 0; i < n; ++i)
	{
		swap(x, y);
		y[0].clear();
		y[1].clear();
		y[2].clear();
		for (auto p : x[1])
		{
			auto it = y[1].find(p.first);
			if (it == y[1].end())
				y[1][p.first] = p.second + a;
			else
				it->second = min(it->second, p.second + a);
			it = x[2].find(p.first);
			if (it == x[2].end())
				x[2][p.first] = p.second;
			else
				it->second = min(it->second, p.second);
		}
		for (auto p : x[0])
		{
			auto it = y[1].find(p.first);
			if (it == y[1].end())
				y[1][p.first] = p.second + a;
			else
				it->second = min(it->second, p.second + a);
			int g = gcd(p.first, A[i]);
			if (g > 1)
			{
				it = y[0].find(g);
				if (it == y[0].end())
					y[0][g] = p.second;
				else
					it->second = min(it->second, p.second);
			}
			g = gcd(p.first, A[i] - 1);
			if (g > 1)
			{
				it = y[0].find(g);
				if (it == y[0].end())
					y[0][g] = p.second + b;
				else
					it->second = min(it->second, p.second + b);
			}
			g = gcd(p.first, A[i] + 1);
			if (g > 1)
			{
				it = y[0].find(g);
				if (it == y[0].end())
					y[0][g] = p.second + b;
				else
					it->second = min(it->second, p.second + b);
			}
		}
		for (auto p : x[2])
		{
			map<int, long long>::iterator it;
			int g = gcd(p.first, A[i]);
			if (g > 1)
			{
				it = y[2].find(g);
				if (it == y[2].end())
					y[2][g] = p.second;
				else
					it->second = min(it->second, p.second);
			}
			g = gcd(p.first, A[i] - 1);
			if (g > 1)
			{
				it = y[2].find(g);
				if (it == y[2].end())
					y[2][g] = p.second + b;
				else
					it->second = min(it->second, p.second + b);
			}
			g = gcd(p.first, A[i] + 1);
			if (g > 1)
			{
				it = y[2].find(g);
				if (it == y[2].end())
					y[2][g] = p.second + b;
				else
					it->second = min(it->second, p.second + b);
			}
		}
	}
	long long ans = 1e18;
	for (auto p : y[0])
		ans = min(ans, p.second);
	for (auto p : y[1])
		ans = min(ans, p.second);
	for (auto p : y[2])
		ans = min(ans, p.second);
	printf("%I64d\n", ans);
	return 0;
}
