#include <cstdio>
#include <cstring>

char s[100000];
int next[100000];

int main()
{
	while (scanf("%s", s) == 2)
	{
		int l = strlen(s);
		next[0] = -1;
		int a = 0;
		for (int i = 0; i < l; ++i)
		{
			int q = next[i];
			while (q >= 0 && s[q] != s[i])
			{
				q = next[q];
			}
			next[i + 1] = q + 1;
		}
		for (int i = 0; i < l; ++i)
		{
			printf("%d ", next[i]);
		}
		printf("\n");
	}
	return 0;
}
