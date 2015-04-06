#include <cstdio>

char s[101];

int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	bool b = false;
	for (int i = 0; i < n && !b; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (i + j * 4 >= n)
			{
				break;
			}
			bool flag = true;
			for (int k = 0; k < 5; ++k)
			{
				if (s[i + j * k] == '.')
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				b = true;
				break;
			}
		}
	}
	if (b)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
	return 0;
}
