#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int H1 = 203;
const int H2 = 207;

vector<pair<long long, char> > read(int n)
{
	vector<pair<long long, char> > ret;
	for (int i = 0; i < n; ++i)
	{
		int l;
		char c;
		scanf("%d-%c", &l, &c);
		if (ret.size() && ret.back().second == c)
			ret.back().first += l;
		else
			ret.push_back({l, c});
	}
	return ret;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	auto s = read(n);
	auto t = read(m);
	if (t.size() == 1)
	{
		long long ans = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i].second == t[0].second && s[i].first >= t[0].first)
				ans += s[i].first - t[0].first + 1;
		}
		printf("%I64d\n", ans);
	}
	else if (s.size() < t.size())
	{
		puts("0");
	}
	else
	{
		long long th1 = 0;
		long long th2 = 0;
		for (int i = 1; i < (int)t.size() - 1; ++i)
		{
			th1 *= H1;
			th1 += t[i].first * 26 + t[i].second - 'a';
			th2 *= H2;
			th2 += t[i].first * 26 + t[i].second - 'a';
		}
		long long sh1 = 0;
		long long sh2 = 0;
		for (int i = 1; i < (int)t.size() - 1; ++i)
		{
			sh1 *= H1;
			sh1 += s[i].first * 26 + s[i].second - 'a';
			sh2 *= H2;
			sh2 += s[i].first * 26 + s[i].second - 'a';
		}
		long long pw1 = 1;
		long long pw2 = 1;
		for (int i = 0; i < (int)t.size() - 2; ++i)
		{
			pw1 *= H1;
			pw2 *= H2;
		}
		int ans = 0;
		for (int i = 0; i <= (int)s.size() - (int)t.size(); ++i)
		{
			if (th1 == sh1 && th2 == sh2 && s[i].second == t[0].second
				&& s[i].first >= t[0].first
				&& s[i + t.size() - 1].second == t[t.size() - 1].second
				&& s[i + t.size() - 1].first >= t[t.size() - 1].first)
			{
				ans++;
			}
			sh1 *= H1;
			sh2 *= H2;
			sh1 -= (s[i + 1].first * 26 + s[i + 1].second - 'a') * pw1;
			sh2 -= (s[i + 1].first * 26 + s[i + 1].second - 'a') * pw2;
			sh1 += s[i + t.size() - 1].first * 26 + s[i + t.size() - 1].second - 'a';
			sh2 += s[i + t.size() - 1].first * 26 + s[i + t.size() - 1].second - 'a';
		}
		printf("%d\n", ans);
	}
	return 0;
}
