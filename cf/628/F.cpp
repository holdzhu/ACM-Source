#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > v;

int cnt[5];
int must[5];
int can[5];

int main()
{
	int n, b, q;
	scanf("%d %d %d", &n, &b, &q);
	while (q--)
	{
		int upto, quantity;
		scanf("%d %d", &upto, &quantity);
		v.push_back(make_pair(upto, quantity));
	}
	v.push_back(make_pair(0, 0));
	v.push_back(make_pair(b, n));
	sort(v.begin(), v.end());
	bool flag = true;
	for (int i = 1; i < v.size(); ++i)
	{
		int l = v[i - 1].first;
		int r = v[i].first;
		int num = v[i].second - v[i - 1].second;
		if (r - l < num)
		{
			flag = false;
			break;
		}
		for (int j = 0; j < 5; ++j)
			cnt[j] = (r + 5 - j) / 5 - (l + 5 - j) / 5;
		int sum = 0;
		for (int j = 0; j < 5; ++j)
		{
			int d = max(0, num - (r - l - cnt[j]));
			must[j] += d;
			sum += d;
		}
		if (sum > num)
		{
			flag = false;
			break;
		}
		for (int j = 0; j < 5; ++j)
			can[j] += min(num - sum, cnt[j] - max(0, num - (r - l - cnt[j])));
	}
	if (!flag)
	{
		puts("unfair");
	}
	else
	{
		for (int i = 0; i < 5; ++i)
		{
			printf("%d %d\n", must[i], can[i]);
			if (must[i] > n / 5 || must[i] + can[i] < n / 5)
			{
				flag = false;
				break;
			}
		}
		puts(flag ? "fair" : "unfair");
	}
	return 0;
}
