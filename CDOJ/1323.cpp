#include <cstdio>
#include <tuple>
#include <algorithm>

using namespace std;

const int MAGIC_NUMBER = 42;
int cnt[201];
tuple<int, int, int> ans[201];

int main()
{
	for (int i = 1; i <= 200; ++i)
		ans[i] = make_tuple(i * (i + 1) / 2, 2, 3);
	for (int i = 2; i < MAGIC_NUMBER; ++i)
		for (int j = i + 1; j <= MAGIC_NUMBER; ++j)
		{
			for (int k = 0; k <= 200; ++k)
				cnt[k] = k;
			for (int k = 0; k + i <= 200; ++k)
				cnt[k + i] = min(cnt[k + i], cnt[k] + 1);
			for (int k = 0; k + j <= 200; ++k)
				cnt[k + j] = min(cnt[k + j], cnt[k] + 1);
			int last = 0;
			for (int k = 1; k <= 200; ++k)
				ans[k] = min(ans[k], make_tuple(last += cnt[k], i, j));
		}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("1 %d %d\n", get<1>(ans[n]), get<2>(ans[n]));
	}
	return 0;
}
