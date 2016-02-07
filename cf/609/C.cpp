#include <cstdio>
#include <algorithm>

using namespace std;

int m[100000];

int main()
{
	int n;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", m + i);
		sum += m[i];
	}
	sort(m, m + n);
	int q = sum / n;
	int p = sum % n;
	int ans = 0;
	for (int i = 0, j = n - 1; i < j; ++i)
	{
		int tar = q + (i >= n - p);
		while (m[i] < tar)
		{
			int t2 = q + (j >= n - p);
			int mi = min(tar - m[i], m[j] - t2);
			m[i] += mi;
			m[j] -= mi;
			ans += mi;
			if (m[j] == t2)
			{
				j--;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
