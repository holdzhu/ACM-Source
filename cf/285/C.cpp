#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define INF 1e9
using namespace std;

struct G
{
	int v, degree, s;
	bool operator < (const G b) const
	{
		return degree < b.degree;
	}
};

int main()
{
	int n;
	scanf("%d", &n);
	G g[n];
	set<unsigned int> e;
	int Epos = 0;
	for (int i = 0; i < n; ++i)
	{
		int degree, s;
		scanf("%d %d", &degree, &s);
		g[i].v = i;
		g[i].degree = degree;
		g[i].s = s;
	}
	while (1)
	{
		G _g[n];
		memcpy(_g, g, sizeof(g));
		sort(_g, _g + n);
		if (_g[n - 1].degree <= 0 || _g[n - 1].degree >= n)
		{
			break;
		}
		int pos = 0;
		for ( ;_g[pos].degree <= 0; ++pos)
		{
			_g[pos].degree = INF;
		}
		for ( ; _g[pos].degree == 1 && pos < n; ++pos)
		{
			if (_g[pos].v < _g[pos].s)
			{
				e.insert(_g[pos].v * n + _g[pos].s);
			}
			else
			{
				e.insert(_g[pos].s * n + _g[pos].v);
			}
			g[_g[pos].s].degree--;
			g[_g[pos].s].s ^= _g[pos].v;
			g[_g[pos].v].degree = 0;
		}
	}
	printf("%u\n", e.size());
	for (set<unsigned int>::iterator i = e.begin(); i != e.end(); ++i)
	{
		printf("%d %d\n", *i / n, *i % n);
	}
	return 0;
}
