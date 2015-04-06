#include <cstdio>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char s1[51], s2[51];
		scanf("%s %s", s1, s2);
		int l1 = strlen(s1);
		int l2 = strlen(s2);
		if (l1 == l2)
		{
			char c[26];
			memset(c, 0, sizeof(c));
			for (int i = 0; i < l1; ++i)
			{
				if (s1[i] >= 'a' && s1[i] <= 'z')
				{
					c[s1[i] - 'a']++;
				}
				else
				{
					c[s1[i] - 'A']++;
				}
				if (s2[i] >= 'a' && s2[i] <= 'z')
				{
					c[s2[i] - 'a']--;
				}
				else
				{
					c[s2[i] - 'A']--;
				}
			}
			bool flag = true;
			for (int i = 0; i < 26; ++i)
			{
				if (c[i])
				{
					printf("No\n");
					flag = false;
					break;
				}
			}
			if (flag)
			{
				printf("Yes\n");
			}
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
