#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int l = 0;
		int r = min(a, b);
		while (l < r)
		{
			int m = (l + r + 1) >> 1;
			int p[3] = {a - m, b - m, c};
			bool flag = true;
			if (m > 0)
			{
				int last = 0;
				for (int i = 1; i < 3; ++i)
					if (p[i] > p[last])
						last = i;
				p[last]--;
				if (p[last] < 0)
					flag = false;
				else for (int i = 1; i < m; ++i)
				{
					int nxt = -1;
					for (int j = 0; j < 3; ++j)
						if (j != last && (nxt == -1 || p[nxt] < p[j]))
							nxt = j;
					last = nxt;
					p[last]--;
					if (p[last] < 0)
						flag = false;
				}
			}
			if (flag)
				l = m;
			else
				r = m - 1;
		}
		printf("%d\n", l);
	}
	return 0;
}
