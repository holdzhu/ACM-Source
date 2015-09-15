#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int p[200002];
int str[200002];

void pk()
{
    int i;
    int mx = 0;
    int id;
    for(i=1; i<n * 2 + 2; i++)
    {
        if( mx > i )
            p[i] = min( p[2*id-i], mx-i );        
        else
            p[i] = 1;
        for(; str[i+p[i]] == str[i-p[i]]; p[i]++)
            ;
        if( p[i] + i > mx )
        {
            mx = p[i] + i;
            id = i;
        }
    }
}

int t[100000];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &t[i]);
	}
	str[0] = -1000;
	str[1] = -1001;
	for (int i = 0; i < n; ++i)
	{
		str[i * 2 + 2] = t[i];
		str[i * 2 + 3] = -1001;
	}
	pk();
	for (int i = 0; i < n * 2 + 2; ++i)
	{
		printf("%d ", p[i] - 1);
	}
	for (int i = 0; i < m; ++i)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		long long ans = 0;
		for (int i = l * 2; i <= r * 2; ++i)
		{
			int len = 0;
			if (i % 2 == 0)
			{
				len = min(p[i] / 2 + 1, min((i - l * 2), (r * 2 - i)) / 2 + 1);
				printf("%d\n", len);
				len = len * (len + 1) / 2;
			}
			else
			{
				len = min((p[i]) / 2, min(i - l * 2, r * 2 - i));
				printf("%d\n", len);
				len = len * (len + 1) / 2;
			}
			ans += len;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
