#include <cstdio>
#include <cstring>

int main()
{
	char t;
	char s1[] = "qwertyuiop";
	char s2[] = "asdfghjkl;";
	char s3[] = "zxcvbnm,./";
	scanf("%c", &t);
	char s[101];
	scanf("%s", s);
	int l = strlen(s);
	for (int i = 0; i < l; ++i)
	{
		bool b1 = false;
		bool b2 = false;
		bool b3 = false;
		char p;
		for (int j = 0; j < 10; ++j)
		{
			if (s1[j] == s[i])
			{
				b1 = true;
				if (t == 'L')
				{
					p = s1[j + 1];
				}
				else
				{
					p = s1[j - 1];
				}
				break;
			}
		}
		if (!b1)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (s2[j] == s[i])
				{
					b2 = true;
					if (t == 'L')
					{
						p = s2[j + 1];
					}
					else
					{
						p = s2[j - 1];
					}
					break;
				}
			}
			if (!b2)
			{
				for (int j = 0; j < 10; ++j)
				{
					if (s3[j] == s[i])
					{
						b3 = true;
						if (t == 'L')
						{
							p = s3[j + 1];
						}
						else
						{
							p = s3[j - 1];
						}
						break;
					}
				}
			}
		}
		putchar(p);
	}
	printf("\n");
	return 0;
}
