#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef set<pair<long long, long long> >::iterator setit;

long long N;
long long H[100001];
long long nxt[2][100001];
long long dp[17][100001];
long long sum[2][17][100001];

setit next(setit it)
{
	return ++it;
}

setit prev(setit it)
{
	return --it;
}

pair<long long, long long> solve(long long S, long long X)
{
	pair<long long, long long> ret = make_pair(0, 0);
	for (long long i = 16; i >= 0; --i)
		if (dp[i][S] != N && sum[0][i][S] + sum[1][i][S] + ret.first + ret.second <= X)
			ret.first += sum[0][i][S], ret.second += sum[1][i][S], S = dp[i][S];
	return ret;
}

int main()
{
	scanf("%lld", &N);
	for (long long i = 0; i < N; ++i)
		scanf("%lld", &H[i]);
	set<pair<long long, long long> > s;
	for (long long i = 0; i < N; ++i)
		s.insert(make_pair(H[i], i));
	for (long long i = 0; i < N; ++i)
	{
		vector<pair<long long, pair<long long, long long> > > v;
		setit it = s.find(make_pair(H[i], i));
		setit it1 = next(it);
		if (it1 != s.end())
		{
			v.push_back(make_pair(abs(it1->first - H[i]), *it1));
			setit it2 = next(it1);
			if (it2 != s.end())
				v.push_back(make_pair(abs(it2->first - H[i]), *it2));
		}
		if (it != s.begin())
		{
			setit it3 = prev(it);
			v.push_back(make_pair(abs(it3->first - H[i]), *it3));
			if (it3 != s.begin())
			{
				setit it4 = prev(it3);
				v.push_back(make_pair(abs(it4->first - H[i]), *it4));
			}
		}
		sort(v.begin(), v.end());
		if (v.size() >= 1)
		{
			nxt[1][i] = v[0].second.second;
			if (v.size() >= 2)
				nxt[0][i] = v[1].second.second;
			else
				nxt[0][i] = N;
		}
		else
			nxt[0][i] = nxt[1][i] = N;
		s.erase(it);
	}
	nxt[0][N] = nxt[1][N] = N;
	for (long long i = 0; i <= N; ++i)
	{
		dp[0][i] = nxt[0][i];
		sum[0][0][i] = sum[0][1][i] = abs(H[nxt[0][i]] - H[i]);
		dp[1][i] = nxt[1][nxt[0][i]];
		sum[1][1][i] = abs(H[nxt[1][nxt[0][i]]] - H[nxt[0][i]]);
	}
	for (long long i = 2; i < 17; ++i)
		for (long long j = 0; j <= N; ++j)
		{
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
			sum[0][i][j] = sum[0][i - 1][j] + sum[0][i - 1][dp[i - 1][j]];
			sum[1][i][j] = sum[1][i - 1][j] + sum[1][i - 1][dp[i - 1][j]];
		}
	long long X0;
	scanf("%lld", &X0);
	long long ansu = 1, ansv = 0, ansid = 0;
	for (long long i = 0; i < N; ++i)
	{
		pair<long long, long long> p = solve(i, X0);
		long long u = p.first;
		long long v = p.second;
		if (v == 0)
			u = 1;
		long long delta = 1ll * ansu * v - 1ll * ansv * u;
		if (delta > 0)
			ansu = u, ansv = v, ansid = i;
		else if (delta == 0 && H[ansid] < H[i])
			ansid = i;
	}
	printf("%lld\n", ansid + 1);
	long long M;
	scanf("%lld", &M);
	while (M--)
	{
		long long S, X;
		scanf("%lld %lld", &S, &X);
		pair<long long, long long> p = solve(S - 1, X);
		printf("%lld %lld\n", p.first, p.second);
	}
	return 0;
}
