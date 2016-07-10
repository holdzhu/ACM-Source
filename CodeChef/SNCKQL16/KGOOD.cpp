#include <algorithm>
#include <cstdio>

using namespace std;

char s[100001];
int cnt[26];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int K;
		scanf("%s %d", s, &K);
		for (int i = 0; i < 26; ++i)
			cnt[i] = 0;
		for (int i = 0; s[i]; ++i)
			++cnt[s[i] - 'a'];
		vector<int> v;
		for (int i = 0; i < 26; ++i)
			if (cnt[i])
				v.push_back(cnt[i]);
		sort(v.begin(), v.end());
		int ans = 1e9;
		for (int i = 0, sum = 0; i < v.size(); ++i)
		{
			int ttl = 0;
			for (int j = i; j < v.size(); ++j)
				ttl += max(v[j] - (v[i] + K), 0);
			ans = min(ans, ttl + sum);
			sum += v[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
