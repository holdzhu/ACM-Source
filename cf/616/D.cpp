#include <cstdio>

int a[500000];
int cnt[1000001];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	int ansl = 0, ansr = 0;
	int cur = 0;
	for (int i = 0, j = 0; i < n; ++i)
	{
		while (j < n && (cur < k || cnt[a[j]]))
		{
			if (cnt[a[j]] == 0)
				cur++;
			cnt[a[j]]++;
			j++;
		}
		if (j - i > ansr - ansl)
			ansr = j, ansl = i;
		cnt[a[i]]--;
		if (cnt[a[i]] == 0)
			cur--;
	}
	printf("%d %d\n", ansl + 1, ansr);
	return 0;
}
