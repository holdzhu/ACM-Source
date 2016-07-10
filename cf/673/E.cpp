#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

double dp[200001][51];
double sum[200001];
double sum2[200001];
double sum3[200001];
vector<pair<double, double> > convex[50];
int t[200001];

inline double slope(const pair<double, double> &A, const pair<double, double> &B)
{
	return (A.second - B.second) / (A.first - B.first);
}

inline pair<double, double> get(vector<pair<double, double> > &v, const double &k)
{
	int L = 0;
	int R = v.size() - 1;
	while (L < R)
	{
		int M = (L + R) >> 1;
		if (slope(v[M], v[M + 1]) < k)
			L = M + 1;
		else
			R = M;
	}
	return v[L];
}

inline void push(vector<pair<double, double> > &v, pair<double, double> p)
{
	while (v.size() > 1 && slope(v[v.size() - 2], v.back()) > slope(v.back(), p))
		v.pop_back();
	v.push_back(p);
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &t[i]);
	for (int i = 1; i <= n; ++i)
	{
		sum[i] = sum[i - 1] + t[i];
		sum2[i] = sum2[i - 1] + 1. / t[i];
		sum3[i] = sum3[i - 1] + sum[i] / t[i];
	}
	for (int i = 0; i < k; ++i)
		convex[i].emplace_back(0, 0);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			auto p = get(convex[j], sum2[i]);
			dp[i][j + 1] = p.second - p.first * sum2[i] + sum3[i];
			if (j + 1 < k)
				push(convex[j + 1], {sum[i], dp[i][j + 1] - sum3[i] + sum2[i] * sum[i]});
		}
	}
	printf("%.12f\n", dp[n][k]);
	return 0;
}
