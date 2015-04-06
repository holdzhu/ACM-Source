#include <cstdio>
#include <vector>
using namespace std;

const int maxint = 1e9;

int main()
{
	long long n, m;
	while (scanf("%lld%lld", &n, &m) == 2 && n && m)
	{
		vector<long long> s;
		long long sum = 0;
		s.push_back(1);
		for (int i = 0; i < n; ++i)
		{
			vector<long long> _s;
			_s.push_back(0);
			for (int j = 0; j < s.size(); ++j)
			{
				_s[j] += s[j] * (i * 4 + 2) % maxint;
				if (j < s.size() - 1 || s[j] * (i * 4 + 2) / maxint + _s[j] / maxint)
				{
					_s.push_back(s[j] * (i * 4 + 2) / maxint + _s[j] / maxint);
				}
				_s[j] %= maxint;
			}
			long long t = 0;
			while (s.size() < _s.size())
			{
				s.push_back(0);
			}
			for (int j = _s.size() - 1; j >= 0; --j)
			{
				s[j] = (_s[j] + t * maxint) / (i + 2);
				t = (_s[j] + t * maxint) % (i + 2);
			}
			for (int j = 0; j < s.size() - 1; ++j)
			{
				s[j + 1] += s[j] / maxint;
				s[j] %= maxint;
			}
			while (s.back() >= maxint)
			{
				t = s.back() /= maxint;
				s.back() %= maxint;
				s.push_back(t);
			}
			t = 0;
			for (int j = s.size() - 1; j >= 0; --j)
			{
				t *= maxint;
				t += s[j] % m;
				t %= m;
			}
			sum += t;
			sum %= m;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
