#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 1e6;

int phi[maxn + 1];

void phi_table()
{
	static int flag = 0;
	if (!flag)
	{
		int n = maxn;
		flag = 1;
		for (int i = 2; i <= n; ++i) phi[i] = 0;
		phi[1] = 1;
		for (int i = 2; i <= n; ++i) if (!phi[i])
		{
			for (int j = i; j <= n; j += i)
			{
				if (!phi[j]) phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}

int cnt[maxn + 1];

class GcdAndPhi {
public:
	vector<long long> calc(int T, vector<int> N) {
		vector<long long> ans;
		phi_table();
		for (int i = 0; i < T; ++i)
		{
			int n = N[i];
			for (int j = 1; j <= n; ++j)
			{
				cnt[j] = 0;
			}
			for (int j = 1; j <= n; ++j)
			{
				cnt[phi[j]]++;
			}
			for (int j = 1; j <= n; ++j)
			{
				for (int k = j + j; k <= n; k += j)
				{
					cnt[j] += cnt[k];
				}
			}
			for (int j = 1; j <= n; ++j)
			{
				cnt[j] = 1ll * cnt[j] * cnt[j] % 10007;
			}
			for (int j = n; j > 0; --j)
			{
				for (int k = j + j; k <= n; k += j)
				{
					cnt[j] -= cnt[k];
				}
			}
			long long t = 0;
			for (int i = 1; i <= n; ++i)
			{
				t = (t + 1ll * phi[i] * cnt[i]) % 10007;
			}
			ans.push_back(t);
		}
		return ans;
	}
};

int main()
{
	GcdAndPhi g;
	std::vector<long long> v = g.calc(5, {41,4,26,5,14});
	printf("%lld\n", v[0]);
	printf("%lld\n", v[1]);
	printf("%lld\n", v[2]);
	printf("%lld\n", v[3]);
	printf("%lld\n", v[4]);
	return 0;
}
