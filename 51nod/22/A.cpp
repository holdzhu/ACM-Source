#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		bool flag = 0;
		for (int i = 0; i < n * m; ++i)
		{
			int t;
			scanf("%d", &t);
			flag ^= t;
		}
		puts(flag ? "yadang" : "xiawa");
	}
	return 0;
}
