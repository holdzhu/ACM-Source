#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n != -1)
	{
		static int kase = 1;
		int m;
		scanf("%d", &m);
		int _n = n;
		char c;
		scanf(" %c", &c);
		vector<long long> ans;
		long long t = m;
		if (n && m)
		{
			while (n)
			{
				if (n & 1)
				{
					ans.push_back(t);
				}
				t <<= 1;
				n >>= 1;
			}
			if (c == 'b')
				reverse(ans.begin(), ans.end());
		}
		else
			ans.push_back(0);
		printf("Case %d: %d x %d = ", kase, _n, m);
		for (int i = 0; i < ans.size(); ++i)
		{
			if (i)
				printf(" + ");
			printf("%lld", ans[i]);
		}
		printf("\n");
		kase++;
	}
	return 0;
}
