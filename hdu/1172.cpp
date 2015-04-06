#include <cstdio>
#include <cstring>

int main()
{
	int N;
	while (scanf("%d", &N) == 1 && N)
	{
		char a[N][5];
		int b[N], c[N];
		for (int i = 0; i < N; ++i)
		{
			scanf("%s %d %d", a[i], &b[i], &c[i]);
		}
		int cnt = 0;
		int ans;
		for (int i = 1000; i < 10000; ++i)
		{
			int n[4] = {i / 1000, i / 100 % 10, i / 10 % 10, i % 10};
			int num[10];
			memset(num, 0, sizeof(num));
			for (int j = 0; j < 4; ++j)
			{
				num[n[j]]++;
			}
			bool flag = true;
			for (int j = 0; j < N; ++j)
			{
				int u = 0, v = 0;
				int t[10];
				memset(t, 0, sizeof(t));
				for (int k = 0; k < 4; ++k)
				{
					if (n[k] == a[j][k] - '0')
					{
						v++;
					}
					t[a[j][k] - '0']++;
				}
				for (int k = 0; k < 10; ++k)
				{
					if (t[k] > num[k])
					{
						t[k] = num[k];
					}
					u += t[k];
				}
				if (u != b[j] || v != c[j])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				ans = i;
				cnt++;
			}
		}
		if (cnt == 1)
		{
			printf("%d\n", ans);
		}
		else
		{
			printf("Not sure\n");
		}
	}
	return 0;
}
