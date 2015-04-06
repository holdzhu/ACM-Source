#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const long long mod = 95878924012312;
char s[200][201];
int allp[200][201];

int main()
{
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s[i]);
	}
	for (int top = 0; top < n; ++top)
	{
		long long str[n * 2 + 2];
		str[0] = -2;
		str[1] = -1;
		for (int i = 0; i < n; ++i)
		{
			str[i * 2 + 2] = 0;
			str[i * 2 + 3] = -1;
		}
		for (int bottom = top; bottom < n; ++bottom)
		{
			for (int i = 0; i < n; ++i)
			{
				str[i * 2 + 2] *= 26;
				str[i * 2 + 2] += s[bottom][i] - 'a';
				str[i * 2 + 2] %= mod;
			}
		    int maxid = 0;
			int id;
			int _n = n * 2 + 2;
			int p[_n];
			memset(p, 0, sizeof(p));
			for(int i = 1; i < _n; i++)
			{
				if(maxid > i)
				{
					p[i] = min(p[2 * id - i], maxid - i);
				}
				else
				{
					p[i] = 1;
				}
				for( ;str[i + p[i]] == str[i - p[i]]; ++p[i])
				{

				}
				if(p[i] + i > maxid)
				{
					maxid = p[i] + i;
					id = i;
				}
			}
			for (int i = 0; i < _n; ++i)
			{
				if (ans < (bottom - top + 1) * (p[i] - 1))
				{
					ans = (bottom - top + 1) * (p[i] - 1);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
