#include <cstdio>
#include <functional>
#include <algorithm>
#include <queue>
#include <cassert>
#include <iostream>

using namespace std;

long long multi_mod(long long a, long long b, long long c)
{
	a %= c;
	b %= c;
	long long rnt = 0;
	while (b)
	{
		if (b & 1)
		{
			rnt += a;
			if (rnt >= c)
			{
				rnt -= c;
			}
		}
		a <<= 1;
		if (a >= c)
		{
			a -= c;
		}
		b >>= 1;
	}
	return rnt;
}

const int N = 2500;
int sgn[N * 2];
int fa[N * 2];

int get(int x)
{
	if (x == fa[x])
	{
		return sgn[x];
	}
	sgn[x] *= get(fa[x]);
	fa[x] = x;
	return sgn[x];
}

int main()
{
	long long p, q, r, base;
	while (scanf("%I64d %I64d %I64d %I64d", &p, &q, &r, &base) == 4)
	{
		long long b = 1;
		priority_queue<pair<long long, int> > pq;
		for (int i = 0; i < N; ++i)
		{
			b = multi_mod(b, base, r);
			long long w = (multi_mod(p, b, r) - multi_mod(q, b, r) + r) % r;
			b = multi_mod(b, base, r);
			w = (w + multi_mod(q, b, r) - multi_mod(p, b, r) + r) % r;
			b = multi_mod(b, base, r);
			b = multi_mod(b, base, r);
			pq.push(make_pair(w, i));
		}
		for (int i = 0; i < N * 2; ++i)
		{
			fa[i] = i;
			sgn[i] = 0;
		}
		int cnt = N;
		while (pq.size() > 1)
		{
			pair<long long, int> a = pq.top();
			pq.pop();
			pair<long long, int> b = pq.top();
			pq.pop();
			pair<long long, int> c = pq.top();
			if (a.first == b.first)
			{
				sgn[a.second] = 1;
				sgn[b.second] = -1;
				break;
			}
			if (b.first == c.first)
			{
				sgn[b.second] = 1;
				sgn[c.second] = -1;
				break;
			}
			if (a.first + b.first == r)
			{
				sgn[a.second] = 1;
				sgn[b.second] = 1;
				break;
			}
			if (b.first == c.first)
			{
				sgn[b.second] = 1;
				sgn[c.second] = 1;
				break;
			}
			if (a.first < b.first)
			{
				swap(a, b);
			}
			fa[a.second] = cnt;
			fa[b.second] = cnt;
			sgn[a.second] = 1;
			sgn[b.second] = -1;
			pq.push(make_pair(a.first - b.first, cnt++));
		}
		for (int i = 0; i < N; ++i)
		{
			if (get(i) >= 0)
			{
				printf("(())");
			}
			else
			{
				printf("()()");
			}
		}
		puts("");
		for (int i = 0; i < N; ++i)
		{
			if (get(i) <= 0)
			{
				printf("(())");
			}
			else
			{
				printf("()()");
			}
		}
		puts("");
	}
	return 0;
}
