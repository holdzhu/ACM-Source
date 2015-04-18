#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

bool m[1000][1000];
long long x1, x2, y1, y2;
long long W, H, n;
long long sum;

void rnd()
{
	x1 = y1 = 1000000;
	x2 = y2 = 0;
	while (!(y2 >= y1 && x2 >= x1))
	{
		x1 = rand() % W + 1;
		x2 = rand() % W + 1;
		y2 = rand() % H + 1;
		y1 = rand() % H + 1;
	}
	for (int i = x1 - 1; i < x2; ++i)
	{
		for (int j = y1 - 1; j < y2; ++j)
		{
			if (m[i][j])
			{
				rnd();
				return;
			}
		}
	}
	for (int i = x1 - 1; i < x2; ++i)
	{
		for (int j = y1 - 1; j < y2; ++j)
		{
			m[i][j] = 1;
		}
	}
	sum -= (x2 - x1 + 1) * (y2 - y1 + 1);
}

long long pg()
{
	set<Line> vecLine;
	set<Line> horLine;
	for (long long i = 0; i < n; ++i)
	{
		if (sum == 0)
		{
			return 0;
		}
		rnd();
		printf("%lld %lld %lld %lld\n", x1, x2, y1, y2);
		vecLine.insert((Line){x1 - 1, y1 - 1, y2, 1});
		vecLine.insert((Line){x2, y1 - 1, y2, 0});
		horLine.insert((Line){y1 - 1, x1 - 1, x2, 1});
		horLine.insert((Line){y2, x1 - 1, x2, 0});
	}
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!pass\n");
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
	return ans;
}

int main()
{
	srand((int)time(0));
	scanf("%lld %lld %lld %lld", &W, &H, &n, &M);
	while (1)
	{
		memset(m, 0, sizeof m);
		sum = W * H;
		long long ans1 = pg();
		long long ans2 = 0;
		for (int i = 0; i < W; ++i)
		{
			for (int j = 0; j < H; ++j)
			{
				if (i <= W - M)
				{
					bool flag = true;
					for (int k = 0; k < M; ++k)
					{
						if (m[i + k][j])
						{
							flag = false;
							break;
						}
					}
					if (flag)
					{
						ans2++;
					}
				}
				if (j <= H - M)
				{
					bool flag = true;
					for (int k = 0; k < M; ++k)
					{
						if (m[i][j + k])
						{
							flag = false;
							break;
						}
					}
					if (flag)
					{
						ans2++;
					}
				}
			}
		}
		if (M == 1)
		{
			ans2 /= 2;
		}
		if (ans1 != ans2)
		{
			for (int i = 0; i < W; ++i)
			{
				for (int j = 0; j < H; ++j)
				{
					printf("%d", m[i][j]);
				}
				printf("\n");
			}
			break;
		}
	}
	return 0;
}
