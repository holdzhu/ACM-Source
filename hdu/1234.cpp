#include <cstdio>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		char early[100];
		char late[100];
		int e = 86400;
		int l = -1;
		while (n--)
		{
			char t[100];
			scanf("%s", t);
			int h, m, s;
			scanf("%d:%d:%d", &h, &m, &s);
			s += h * 3600 + m * 60;
			if (s < e)
			{
				strcpy(early, t);
				e = s;
			}
			scanf("%d:%d:%d", &h, &m, &s);
			s += h * 3600 + m * 60;
			if (s > l)
			{
				strcpy(late, t);
				l = s;
			}
		}
		printf("%s %s\n", early, late);
	}
	return 0;
}
