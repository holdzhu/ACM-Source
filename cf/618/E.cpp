#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 300000;

double tree[maxn << 2][2];
double lazyA[maxn << 2][2][2];
double lazyB[maxn << 2][2];

void mul(const double A[2][2], double B[2])
{
	double t0 = A[0][0] * B[0] + A[0][1] * B[1];
	double t1 = A[1][0] * B[0] + A[1][1] * B[1];
	B[0] = t0;
	B[1] = t1;
}

double tmp[2][2];
void mul(const double A[2][2], double B[2][2])
{
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
		{
			tmp[i][j] = 0;
			for (int k = 0; k < 2; ++k)
				tmp[i][j] += A[i][k] * B[k][j];
		}
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			B[i][j] = tmp[i][j];
}

void add(const double A[2], double B[2])
{
	B[0] += A[0];
	B[1] += A[1];
}

void pushdown(int rt)
{
	mul(lazyA[rt], tree[rt << 1]);
	mul(lazyA[rt], tree[rt << 1 | 1]);
	mul(lazyA[rt], lazyA[rt << 1]);
	mul(lazyA[rt], lazyA[rt << 1 | 1]);
	mul(lazyA[rt], lazyB[rt << 1]);
	mul(lazyA[rt], lazyB[rt << 1 | 1]);
	add(lazyB[rt], tree[rt << 1]);
	add(lazyB[rt], tree[rt << 1 | 1]);
	add(lazyB[rt], lazyB[rt << 1]);
	add(lazyB[rt], lazyB[rt << 1 | 1]);
	lazyA[rt][0][0] = lazyA[rt][1][1] = 1;
	lazyA[rt][0][1] = lazyA[rt][1][0] = 0;
	lazyB[rt][0] = lazyB[rt][1] = 0;
}

void build(int rt, int l, int r)
{
	lazyA[rt][0][0] = lazyA[rt][1][1] = 1;
	if (l >= r)
	{
		tree[rt][0] = l;
		return;
	}
	int m = (l + r) >> 1;
	build(rt << 1, l, m);
	build(rt << 1 | 1, m + 1, r);
}

void update(int L, int R, const double mu[2][2], const double ad[2], int rt, int l, int r)
{
	if (L <= l && r <= R)
	{
		mul(mu, tree[rt]);
		add(ad, tree[rt]);
		mul(mu, lazyA[rt]);
		mul(mu, lazyB[rt]);
		add(ad, lazyB[rt]);
		return;
	}
	pushdown(rt);
	int m = (l + r) >> 1;
	if (L <= m) update(L, R, mu, ad, rt << 1, l, m);
	if (R > m) update(L, R, mu, ad, rt << 1 | 1, m + 1, r);
}

pair<double, double> query(int x, int rt, int l, int r)
{
	if (l >= r)
	{
		return make_pair(tree[rt][0], tree[rt][1]);
	}
	pushdown(rt);
	int m = (l + r) >> 1;
	if (x <= m) return query(x, rt << 1, l, m);
	else return query(x, rt << 1 | 1, m + 1, r);
}

const double pi = acos(-1);
const double IND[2][2] = {{1, 0}, {0, 1}};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	build(1, 0, n);
	for (int i = 0; i < m; ++i)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if (x == 1)
		{
			pair<double, double> A = query(y - 1, 1, 0, n), B = query(y, 1, 0, n);
			double dx = B.first - A.first;
			double dy = B.second - A.second;
			double dis = hypot(dx, dy);
			dx *= z / dis;
			dy *= z / dis;
			double tmp[2] = {dx, dy};
			update(y, n, IND, tmp, 1, 0, n);
		}
		else
		{
			pair<double, double> A = query(y - 1, 1, 0, n);
			double co = cos(z * pi / 180);
			double si = sin(z * pi / 180);
			double tmp1[2][2] = {{co, si}, {-si, co}};
			double tmp2[2] = {A.first * (1 - co) - A.second * si, A.first * si + A.second * (1 - co)};
			update(y, n, tmp1, tmp2, 1, 0, n);
		}
		pair<double, double> ans = query(n, 1, 0, n);
		printf("%.10f %.10f\n", ans.first, ans.second);
	}
	return 0;
}
