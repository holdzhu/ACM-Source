#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

const int H1 = 201, H2 = 203;

long long hsh1[100011];
long long hsh2[100011];
long long pow1[100011];
long long pow2[100011];

void init(int n, string s)
{
	pow1[0] = pow2[0] = 1;
	hsh1[0] = hsh2[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		pow1[i] = pow1[i - 1] * H1;
		pow2[i] = pow2[i - 1] * H2;
		hsh1[i] = hsh1[i - 1] * H1 + s[i - 1];
		hsh2[i] = hsh2[i - 1] * H2 + s[i - 1];
	}
}

pair<long long, long long> get(int l, int r)
{
	long long s1 = hsh1[r] - hsh1[l - 1] * pow1[r - l + 1];
	long long s2 = hsh2[r] - hsh2[l - 1] * pow2[r - l + 1];
	return make_pair(s1, s2);
}

class Periods {
public:
    long long getLongest(int n, string s) {
        init(n, s);
        long long ans = 0;
        priority_queue<pair<int, int> > pq;
        for (int i = 2; i <= n; ++i)
        {
        	int l = 0;
        	int r = min(n - i + 1, i - 1);
        	while (l < r)
        	{
        		int m = (l + r + 1) >> 1;
        		if (get(1, m) == get(i, i + m - 1))
        		{
        			l = m;
        		}
        		else
        		{
        			r = m - 1;
        		}
        	}
        	if (l) pq.push(make_pair(i - 1, i + l));
        	while (!pq.empty() && pq.top().second <= i)
        	{
        		pq.pop();
        	}
        	if (!pq.empty())
        	{
        		ans += pq.top().first;
        	}
        }
        return ans;
    }
};

int main()
{
	Periods p;
	long long ans = p.getLongest(3, "aba");
	printf("%lld\n", ans);
	return 0;
}
