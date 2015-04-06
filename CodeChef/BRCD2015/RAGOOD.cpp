#include <cstdio>
#include <algorithm>

using namespace std;

struct Time
{
	int L, R;
	bool operator < (const Time& rhs) const
	{
		return R < rhs.R || (R == rhs.R && L > rhs.L);
	}
};

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		Time t[N];
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &t[i].L);
		}
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &t[i].R);
		}
		sort(t, t + N);
		int r = 0;
		int c = 0;
		for (int i = 0; i < N; ++i)
		{
			if (t[i].L >= r)
			{
				c++;
				r = t[i].R;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}
