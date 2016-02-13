
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

map<long long, vector<pair<int, int> > > ma;
int tree[1010];
const int maxn = 1010;

int lowbit(int x)
{
	return x & (-x);
}

void update(int x, int delta)
{
	while (x <= maxn)
	{
		tree[x] += delta;
		x += lowbit(x);
	}
}

int query(int x)
{
	int ret = 0;
	while (x > 0)
	{
		ret += tree[x];
		x -= lowbit(x);
	}
	return ret;
}

class BearDarts
{
	public:
	long long count(vector <int> w)
	{
		ma.clear();
		int n = w.size();
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 2; j < n; ++j)
			{
				long long p = 1ll * w[i] * w[j];
				ma[p].push_back(make_pair(j, i));
			}
		}
		long long ans = 0;
		for (map<long long, vector<pair<int, int> > >::iterator it = ma.begin(); it != ma.end(); ++it)
		{
			vector<pair<int, int> >& v = it->second;
			sort(v.begin(), v.end());
			for (int i = 0; i < v.size(); )
			{
				int p = i;
				for ( ; p < v.size(); ++p)
				{
					if (v[p].first != v[i].first)
					{
						break;
					}
					ans += query(v[p].second);
				}
				for ( ; i < p; ++i)
				{
					update(v[i].second + 1, 1);
					update(v[i].first, -1);
				}
			}
			for (int i = 0; i < v.size(); ++i)
			{
				update(v[i].second + 1, -1);
				update(v[i].first, 1);
			}
		}
		return ans;
	}
};

int main()
{
	vector<int> w;
	w.push_back(6);
	w.push_back(8);
	w.push_back(4);
	w.push_back(3);
	w.push_back(6);
	BearDarts bd;
	printf("%I64d\n", bd.count(w));
	return 0;
}
