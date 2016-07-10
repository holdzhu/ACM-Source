#include <cstdio>

int cnt[5001];
int ans[5001];
int t[5000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &t[i]);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			cnt[j] = 0;
		cnt[t[i]]++;
		int mx = t[i];
		ans[mx]++;
		for (int j = i + 1; j < n; ++j)I
		{
			cnt[t[j]]++;
			if (cnt[t[j]] > cnt[mx] || (cnt[t[j]] == cnt[mx] && t[j] < mx))
				mx = t[j];
			ans[mx]++;
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}
