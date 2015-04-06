#include <cstdio>
#include <cstring>

char s[1000001];
char ss[2000005];
int f[2000005];

int main()
{
	int N;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%s", s);
		int l = strlen(s);
		ss[0] = -2;
		for (int i = 0; i < l; ++i)
		{
			ss[i * 2 + 1] = -1;
			ss[i * 2 + 2] = s[i];
		}
		ss[l * 2 + 1] = -1;
		ss[l * 2 + 2] = -3;
		int maxid = 1;
		f[0] = 1;
		f[1] = 1;
		int ans = 1;
		for (int i = 2; i < l * 2; ++i)
		{
			f[i] = f[2 * maxid - i];
			if (f[i] > f[maxid] - 2 * (i - maxid))
			{
				f[i] = f[maxid] - 2 * (i - maxid);
			}
			if (f[i] < 1)
			{
				f[i] = 1;
			}
			f[i] /= 2;
			for (; ss[i + f[i]] == ss[i - f[i]]; ++f[i])
			{

			}
			if (ans < f[i])
			{
				ans = f[i];
			}
			f[i] = f[i] * 2 - 1;
			if (i + f[i] / 2 > maxid + f[maxid] / 2)
			{
				maxid = i;
			}
		}
		printf("%d\n", ans - 1);
	}
	return 0;
}
