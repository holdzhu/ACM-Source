#include <algorithm>
#include <cstdio>

using namespace std;

char s[100001];
int sum1[100001];
int sum2[100001];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	for (int i = 0; i < n; ++i)
	{
		sum1[i + 1] = sum1[i] + (s[i] == 'a');
		sum2[i + 1] = sum2[i] + (s[i] == 'b');
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		{
			int l = i;
			int r = n;
			while (l < r)
			{
				int m = (l + r + 1) >> 1;
				if (sum1[m] - sum1[i] > k)
					r = m - 1;
				else
					l = m;
			}
			ans = max(ans, l - i);
		}
		{
			int l = i;
			int r = n;
			while (l < r)
			{
				int m = (l + r + 1) >> 1;
				if (sum2[m] - sum2[i] > k)
					r = m - 1;
				else
					l = m;
			}
			ans = max(ans, l - i);
		}
	}
	printf("%d\n", ans);
	return 0;
}
