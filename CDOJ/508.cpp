#include <cstdio>
#include <cstring>
#include <cstdlib>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		bool s = true;
		bool a[n - 1];
		memset(a, 0, sizeof(a));
		int last;
		scanf("%d", &last);
		for (int i = 1; i < n; ++i)
		{
			int t;
			scanf("%d", &t);
			if (abs(t - last) >= n || a[abs(t - last) - 1])
			{
				s = false;
			}
			else
			{
				a[abs(t - last) - 1] = true;
			}
			last = t;
		}
		if (s)
		{
			printf("Jolly\n");
		}
		else
		{
			printf("Not jolly\n");
		}
	}
	return 0;
}
