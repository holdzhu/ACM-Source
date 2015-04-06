#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	char s[1001];
	int a[1000];
	while (scanf("%s", s) == 1)
	{
		int l = strlen(s);
		int n = -1;
		int p = 0;
		for (int i = 0; i <= l; ++i)
		{
			if (i == l || s[i] == '5')
			{
				if (n >= 0)
				{
					a[p++] = n;
					n = -1;
				}
			}
			else
			{
				if (n == -1)
				{
					n = 0;
				}
				n *= 10;
				n += s[i] - '0';
			}
		}
		sort(a, a + p);
		for (int i = 0; i < p; ++i)
		{
			if (i)
			{
				printf(" ");
			}
			printf("%d", a[i]);
		}
		printf("\n");
	}
	return 0;
}
