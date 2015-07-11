#include <cstdio>
#include <set>

using namespace std;

struct Line
{
	long long p, l, r;
	bool type;
	bool operator < (const Line &rhs) const
	{
		return p < rhs.p || (p == rhs.p && !(type && !rhs.type));
	}
};

long long M;
inline long long f(long long l)
{
	return l - M + 1 > 0 ? l - M + 1 : 0;
}

int main()
{
	long long W, H, n;
	scanf("%lld %lld %lld %lld", &W, &H, &n, &M);
	set<Line> vecLine;
	set<Line> horLine;
	for (long long i = 0; i < n; ++i)
	{
		long long x1, x2, y1, y2;
		scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		vecLine.insert((Line){x1 - 1, y1 - 1, y2, 1});
		vecLine.insert((Line){x2, y1 - 1, y2, 0});
		horLine.insert((Line){y1 - 1, x1 - 1, x2, 1});
		horLine.insert((Line){y2, x1 - 1, x2, 0});
	}
	long long ans = 0;
	long long last = 0;
	set<long long> ls;
	set<long long> rs;
	rs.insert(0);
	ls.insert(H);
	long long cur = f(H);
	if (cur > 0)
	{
		for (set<Line>::iterator i = vecLine.begin(); i != vecLine.end(); ++i)
		{
			long long p = i->p;
			long long l = i->l;
			long long r = i->r;
			bool type = i->type;
			ans += (p - last) * cur;
			if (type)
			{
				long long ll = *(--rs.upper_bound(l));
				long long lr = *ls.lower_bound(r);
				cur -= f(lr - ll);
				cur += f(l - ll);
				cur += f(lr - r);
				ls.insert(l);
				rs.insert(r);
			}
			else
			{
				ls.erase(l);
				rs.erase(r);
				long long ll = *(--rs.upper_bound(l));
				long long lr = *ls.lower_bound(r);
				cur += f(lr - ll);
				cur -= f(l - ll);
				cur -= f(lr - r);
			}
			last = p;
		}
		ans += (W - last) * cur;
	}
	last = 0;
	rs.clear();
	ls.clear();
	rs.insert(0);
	ls.insert(W);
	cur = f(W);
	if (cur > 0)
	{
		for (set<Line>::iterator i = horLine.begin(); i != horLine.end(); ++i)
		{
			long long p = i->p;
			long long l = i->l;
			long long r = i->r;
			bool type = i->type;
			ans += (p - last) * cur;
			if (type)
			{
				long long ll = *(--rs.upper_bound(l));
				long long lr = *ls.lower_bound(r);
				cur -= f(lr - ll);
				cur += f(l - ll);
				cur += f(lr - r);
				ls.insert(l);
				rs.insert(r);
			}
			else
			{
				ls.erase(l);
				rs.erase(r);
				long long ll = *(--rs.upper_bound(l));
				long long lr = *ls.lower_bound(r);
				cur += f(lr - ll);
				cur -= f(l - ll);
				cur -= f(lr - r);
			}
			last = p;
		}
		ans += (H - last) * cur;
	}
	if (M == 1)
	{
		ans /= 2;
	}
	printf("%lld\n", ans);
	return 0;
}
