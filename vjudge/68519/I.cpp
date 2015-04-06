#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int N, k;
	while (scanf("%d %d", &N, &k) == 2 && N && k)
	{
		int a[N];
		bool b[N];
		memset(b, 0, sizeof(b));
		for (int i = 0; i < N; ++i)
		{
			int t;
			scanf("%d %d", &t, &a[i]);
			if (t)
			{
				b[t - 1] = true;
			}
		}
		int s[N];
		int pos = 0;
		for (int i = 0; i < N; ++i)
		{
			if (!b[i])
			{
				s[pos++] = a[i];
			}
		}
		if (pos >= k)
		{
			sort(s, s + pos);
			long long sum = 0;
			for (int i = 0; i < k; ++i)
			{
				sum += s[pos - i - 1];
			}
			printf("%lld\n", sum);
		}
		else
		{
			printf("impossible\n");
		}
	}
	return 0;
}
