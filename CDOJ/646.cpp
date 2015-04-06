#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char s[20];
		scanf("%s", s);
		int l;
		while ((l = strlen(s)) < 9)
		{
			int a = atoi(s);
			char _s[20];
			for (int i = 0; i < l; ++i)
			{
				_s[i] = s[l - i - 1];
			}
			_s[l] = '\0';
			int b = atoi(_s);
			if (a == b)
			{
				break;
			}
			sprintf(s, "%d", a + b);
		}
		printf("%s\n", s);
	}
	return 0;
}
