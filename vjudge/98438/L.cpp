#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 50000;

long long sum[maxn << 1];
int add[maxn << 1];
int addk[maxn << 1];
int dl[maxn << 1];
int dr[maxn << 1];

vector<int> G[maxn + 1];
int dep[maxn + 1];
int in[maxn + 1];
int out[maxn + 1];
int tim;

int M;

#define L(x) (x << 1)
#define R(x) (x << 1 | 1)

void pushDown(int x)
{
	if ((add[x] || addk[x]) && x < M)
	{
		add[L(x)] += add[x];
		addk[L(x)] += addk[x];
		sum[L(x)] += 1ll * add[x] * (dr[L(x)] - dl[L(x)] + 1) + 1ll * addk[x] * (dep[dr[L(x)]] - dep[dl[L(x)] - 1]);
		add[R(x)] += add[x];
		addk[R(x)] += addk[x];
		sum[R(x)] += 1ll * add[x] * (dr[R(x)] - dl[R(x)] + 1) + 1ll * addk[x] * (dep[dr[R(x)]] - dep[dl[R(x)] - 1]);
		add[x] = 0;
		addk[x] = 0;
	}
}

int stk[20], top;
void update(int x)
{
	top = 0;
	for ( ; x; x >>= 1)
		stk[++top] = x;
	while (top--)
		pushDown(stk[top]);
}

long long query(int x)
{
	long long ret = 0;
	int insl = 0, insr = 0;
	for (int l = in[x] + M - 1, r = out[x] + M + 1; l ^ r ^ 1; l >>= 1, r >>= 1)
	{
		if (~l & 1)
		{
			if (!insl)
				update(insl = l ^ 1);
			ret += sum[l ^ 1];
		}
		if (r & 1)
		{
			if (!insr)
				update(insr = r ^ 1);
			ret += sum[r ^ 1];
		}
	}
	return ret;
}

void modify(int x, int val)
{
	int base = val - (dep[in[x]] - dep[in[x] - 1]);
	int insl = 0, insr = 0;
	for (int l = in[x] + M - 1, r = out[x] + M + 1; l ^ r ^ 1; l >>= 1, r >>= 1)
	{
		if (~l & 1)
		{
			if (!insl)
				update(insl = l ^ 1);
			add[l ^ 1] += base;
			addk[l ^ 1]++;
			sum[l ^ 1] += 1ll * base * (dr[l ^ 1] - dl[l ^ 1] + 1) + (dep[dr[l ^ 1]] - dep[dl[l ^ 1] - 1]);
		}
		if (r & 1)
		{
			if (!insr)
				update(insr = r ^ 1);
			add[r ^ 1] += base;
			addk[r ^ 1]++;
			sum[r ^ 1] += 1ll * base * (dr[r ^ 1] - dl[r ^ 1] + 1) + (dep[dr[r ^ 1]] - dep[dl[r ^ 1] - 1]);
		}
	}
	while (insl >>= 1)
		sum[insl] = sum[L(insl)] + sum[R(insl)];
	while (insr >>= 1)
		sum[insr] = sum[L(insr)] + sum[R(insr)];
}

void dfs(int u, int d)
{
	++tim;
	dep[tim] = d + dep[tim - 1];
	in[u] = tim;
	for (auto v : G[u])
	{
		dfs(v, d + 1);
	}
	out[u] = tim;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int N, P;
		scanf("%d %d", &N, &P);
		for (int i = 1; i <= N; ++i)
			G[i].clear();
		for (int i = 2; i <= N; ++i)
		{
			int f;
			scanf("%d", &f);
			G[f].push_back(i);
		}
		tim = 0;
		dfs(1, 0);
		for (M = 1; M < (N + 2); M <<= 1);
		for (int i = 0; i <= M + N; ++i)
			sum[i] = add[i] = addk[i] = 0;
		for (int i = 1; i <= N; ++i)
			dl[M + i] = dr[M + i] = i;
		for (int i = M - 1; i >= 1; --i)
		{
			dl[i] = dl[L(i)];
			dr[i] = dr[R(i)];
		}
		printf("Case #%d:\n", kase);
		while (P--)
		{
			char cmd;
			scanf(" %c", &cmd);
			if (cmd == 'A')
			{
				int X, K;
				scanf("%d %d", &X, &K);
				modify(X, K);
			}
			else
			{
				int X;
				scanf("%d", &X);
				printf("%lld\n", query(X));
			}
		}
	}
	return 0;
}
