#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[20];
char ans[20];
long long pro[17];

int main()
{
	long long K;
	pro[0] = 1;
	for (int i = 1; i < 17; ++i)
	{
		pro[i] = pro[i - 1] * i;
	}
	while (scanf("%s %lld", s, &K) == 2 && s[0] != '#')
	{
		int l = strlen(s);
		sort(s, s + l);
		for (int i = 0; i < l; ++i)
		{
			char last = '#';
			long long sum = 0;
			int flag = -1;
			for (int j = 0; j < l - i; ++j)
			{
				if (s[j] != last)
				{
					int num[26];
					memset(num, 0, sizeof num);
					long long _sum = pro[l - i - 1];
					for (int k = 0; k < l - i; ++k)
					{
						if (j != k)
						{
							num[s[k] - 'A']++;
						}
					}
					for (int k = 0; k < 26; ++k)
					{
						_sum /= pro[num[k]];
					}
					if (sum + _sum < K)
					{
						sum += _sum;
					}
					else
					{
						K -= sum;
						flag = j;
						break;
					}
				}
				last = s[j];
			}
			ans[i] = s[flag];
			for (int j = flag + 1; j < l - i; ++j)
			{
				s[j - 1] = s[j];
			}
		}
		ans[l] = 0;
		printf("%s\n", ans);
	}
	return 0;
}
