#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Node
{
	long long add;
	map<int, int> other;
};

int n, q;
const int mod = 1000000007;
int a[50000];
map<int, vector<int> > pos;
Node tree[100000];

int powmod(long long a, int k)
{
	long long s = 1;
	while (k)
	{
		if (k & 1)
		{
			s *= a;
			s %= mod;
		}
		a *= a;
		a %= mod;
		k >>= 1;
	}
	return s;
}

void build(int l = 0, int r = n - 1, int rt = 1)
{
	tree[rt].add = 0;
	tree[rt].other.clear();
	if (l == r)
	{
		if (pos[a[l]].size() == 1)
		{
			tree[rt].add = a[l];
		}
		else
		{
			tree[rt].other[a[l]] = 1;
		}
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, rt << 1);
	build(m + 1, r, (rt << 1) + 1);
	map<int, int> tmp;
	for (map<int, int>::iterator i = tree[rt << 1].other.begin(); i != tree[rt << 1].other.end(); ++i)
	{
		if (l <= pos[i->first].front() && r >= pos[i->first].back())
		{
			tmp[i->first] += i->second;
		}
		else
		{
			tree[rt].other[i->first] += i->second;
		}
	}
	for (map<int, int>::iterator i = tree[(rt << 1) + 1].other.begin(); i != tree[(rt << 1) + 1].other.end(); ++i)
	{
		if (l <= pos[i->first].front() && r >= pos[i->first].back())
		{
			tmp[i->first] += i->second;
		}
		else
		{
			tree[rt].other[i->first] += i->second;
		}
	}
	for (map<int, int>::iterator i = tmp.begin(); i != tmp.end(); ++i)
	{
		tree[rt].add = (tree[rt].add + powmod(i->first, i->second)) % mod;
	}
	tree[rt].add = (tree[rt].add + tree[rt << 1].add) % mod;
	tree[rt].add = (tree[rt].add + tree[(rt << 1) + 1].add) % mod;
}

Node query(int L, int R, int l = 0, int r = n - 1, int rt = 1)
{
	if (l > R || r < L)
	{
		return (Node){0, map<int, int>()};
	}
	if (L <= l && R >= r)
	{
		return tree[rt];
	}
	int m = (l + r) >> 1;
	Node left = query(L, R, l, m, rt << 1);
	Node right = query(L, R, m + 1, r, (rt << 1) + 1);
	Node rnt;
	rnt.add = 0;
	for (map<int, int>::iterator i = left.other.begin(); i != left.other.end(); ++i)
	{
		rnt.other[i->first] += i->second;
	}
	for (map<int, int>::iterator i = right.other.begin(); i != right.other.end(); ++i)
	{
		rnt.other[i->first] += i->second;
	}
	rnt.add = (rnt.add + left.add) % mod;
	rnt.add = (rnt.add + right.add) % mod;
	return rnt;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		pos.clear();
		scanf("%d %d", &n, &q);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			pos[a[i]].push_back(i);
		}
		if (pos.size() > 5000)
		{
			build();
			int la = 0;
			long long ans;
			for (int i = 0; i < q; ++i)
			{
				int l, r;
				scanf("%d %d", &l, &r);
				int L = min((l ^ la) % n, (r ^ la) % n);
				int R = max((l ^ la) % n, (r ^ la) % n);
				if (pos.size() <= 500)
				{
					ans = 0;
					map<int, int> tmp;
					for (int i = L; i <= R; ++i)
					{
						tmp[a[i]]++;
					}
					for (map<int, int>::iterator i = tmp.begin(); i != tmp.end(); ++i)
					{
						ans = (ans + powmod(i->first, i->second)) % mod;
					}
				}
				else
				{
					Node num = query(L, R);
					ans = num.add;
					for (map<int, int>::iterator i = num.other.begin(); i != num.other.end(); ++i)
					{
						ans = (ans + powmod(i->first, i->second)) % mod;
					}
				}
				printf("%I64d\n", ans);
				la = ans;
			}
		}
		else
		{
			int la = 0;
			long long ans;
			for (int i = 0; i < q; ++i)
			{
				int l, r;
				scanf("%d %d", &l, &r);
				int L = min((l ^ la) % n, (r ^ la) % n);
				int R = max((l ^ la) % n, (r ^ la) % n);
				if (pos.size() <= 500)
				{
					ans = 0;
					map<int, int> tmp;
					for (int i = L; i <= R; ++i)
					{
						tmp[a[i]]++;
					}
					for (map<int, int>::iterator i = tmp.begin(); i != tmp.end(); ++i)
					{
						ans = (ans + powmod(i->first, i->second)) % mod;
					}
				}
				else
				{
					ans = 0;
					for (map<int, vector<int> >::iterator i = pos.begin(); i != pos.end(); ++i)
					{
						int a = lower_bound(i->second.begin(), i->second.end(), L) - i->second.begin();
						int b = upper_bound(i->second.begin(), i->second.end(), R) - i->second.begin();
						if (b > a)
						{
							ans = (ans + powmod(i->first, b - a)) % mod;
						}
					}
				}
				printf("%I64d\n", ans);
				la = ans;
			}
		}
	}
	return 0;
}
