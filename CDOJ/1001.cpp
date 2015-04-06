#include <cstdio>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char s[202];
		scanf("%s", s);
		int l = strlen(s);
		int s1 = 0;
		int s2 = 0; 
		int s3 = 0; 
		for (int i = 0; i < l; ++i)
		{
			s1 += s[i] - '0';
			if (i % 2)
			{
				s2 += s[i] - '0';
			}
			else
			{
				s3 += s[i] - '0';
			}
		}
		printf("%s %s\n", (s1 % 3) ? "no" : "yes", ((s2 - s3) % 11) ? "no" : "yes");
	}
	return 0;
}
