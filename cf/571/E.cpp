#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 1000000007;
int n;
vector<pair<int, long long> > fa[100], fb[100];

long long powmod(long long a, long long k)
{
	long long ret = 1;
	while (k)
	{
		if (k & 1)
		{
			ret = ret * a % mod;
		}
		a = a * a % mod;
		k >>= 1;
	}
	return ret;
}

long long exgcd(long long a, long long b, long long& x, long long& y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long d = exgcd(b, a % b, y, x);
	y -= x * (a / b);
	return d;
}

long long find(const vector<pair<int, long long> >& f, int p)
{
	int pos = lower_bound(f.begin(), f.end(), make_pair(p, -1ll)) - f.begin();
	if (pos != f.size() && f[pos].first == p)
	{
		return f[pos].second;
	}
	return 0;
}

vector<pair<int, long long> > factor(int x)
{
	vector<pair<int, long long> > ret;
	for (int i = 2; i * i <= x; ++i)
	{
		long long cnt = 0;
		while (x % i == 0)
		{
			cnt++;
			x /= i;
		}
		if (cnt)
		{
			ret.push_back(make_pair(i, cnt));
		}
	}
	if (x > 1)
	{
		ret.push_back(make_pair(x, 1));
	}
	return ret;
}

void addfirst(vector<int>& s, const vector<pair<int, long long> >& t)
{
	for (int i = 0; i < t.size(); ++i)
	{
		s.push_back(t[i].first);
	}
}

bool solve()
{
	while (n > 1)
	{
		int cnt = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			vector<int> v;
			addfirst(v, fa[i]);
			addfirst(v, fb[i]);
			addfirst(v, fa[i + 1]);
			addfirst(v, fb[i + 1]);
			sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());
			long long px = -1, py, sx, sy;
			for (int j = 0; j < v.size(); ++j)
			{
				long long a1 = find(fa[i], v[j]), a2 = find(fa[i + 1], v[j]);
				long long b1 = find(fb[i], v[j]), b2 = find(fb[i + 1], v[j]);
				long long x, y, dx, dy;
				long long d = exgcd(b1, -b2, x, y);
				if (b1 == 0 && b2 == 0)
				{
					if (a1 != a2)
					{
						return false;
					}
					continue;
				}
				else if (b1 == 0 && a1 >= a2 && (a1 - a2) % b2 == 0)
				{
					x = 0;
					y = (a1 - a2) / b2;
					dx = 1;
					dy = 0;
				}
				else if (b2 == 0 && a2 >= a1 && (a2 - a1) % b1 == 0)
				{
					x = (a2 - a1) / b1;
					y = 0;
					dx = 0;
					dy = 1;
				}
				else if (d == 0 || (a2 - a1) % d != 0)
				{
					return false;
				}
				else
				{
					x *= (a2 - a1) / d;
					y *= (a2 - a1) / d;
					dx = b2 / abs(d);
					dy = b1 / abs(d);
					if (x > 0 && dx > 0)
					{
						long long t = (x - 1) / dx + 1;
						x -= t * dx;
						y -= t * dy;
					}
					if (y > 0 && dy > 0)
					{
						long long t = (y - 1) / dy + 1;
						x -= t * dx;
						y -= t * dy;
					}
					if (x < 0)
					{
						if (dx == 0)
						{
							return false;
						}
						long long t = (-x - 1) / dx + 1;
						x += t * dx;
						y += t * dy;
					}
					if (y < 0)
					{
						if (dy == 0)
						{
							return false;
						}
						long long t = (-y - 1) / dy + 1;
						x += t * dx;
						y += t * dy;
					}
				}
				if (px == -1)
				{
					px = x;
					py = y;
					sx = dx;
					sy = dy;
				}
				else
				{
					if (sx != 0 || sy != 0)
					{
						if (sx != dx || sy != dy)
						{
							long long k1 = ((x - px) * dy - (y - py) * dx) / (sx * dy - sy * dx);
							long long nx = px + sx * k1, ny = py + sy * k1;
							if (nx < x || ny < y || (nx - x) * dy - dx * (ny - y) != 0)
							{
								return false;
							}
							px = nx;
							py = ny;
							sx = sy = 0;
						}
						else if ((px - x) * dy - dx * (py - y) != 0)
						{
							return false;
						}
					}
					else if (px < x || py < y || (px - x) * dy - dx * (py - y) != 0)
					{
						return false;
					}
				}
			}
			if (px != -1)
			{
				vector<pair<int, long long> > nfa, nfb;
				for (int j = 0; j < v.size(); ++j)
				{
					long long a1 = find(fa[i], v[j]), b1 = find(fb[i], v[j]);
					if (b1 * px + a1)
					{
						nfa.push_back(make_pair(v[j], b1 * px + a1));
					}
					if (b1 * sx)
					{
						nfb.push_back(make_pair(v[j], b1 * sx));
					}
				}
				fa[cnt] = nfa;
				fb[cnt++] = nfb;
			}
		}
		n = cnt;
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		fa[i] = factor(a);
		fb[i] = factor(b);
	}
	if (solve())
	{
		long long ans = 1;
		for (int i = 0; i < fa[0].size(); ++i)
		{	
			ans = ans * powmod(fa[0][i].first, fa[0][i].second) % mod;
		}
		printf("%I64d\n", ans);
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}
