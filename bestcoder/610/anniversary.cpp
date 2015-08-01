#include <cstdio>
#include <cstring>

const char s[] = "anniversary";
const int l = 11;
char t[101];
int tl;

bool check(int s1, int s2)
{
	int k = 0;
	int i;
	for (i = 0; i < tl; ++i)
	{
		if (t[i] == s[k])
		{
			k++;
		}
		else
		{
			k = 0;
		}
		if (k == s1)
		{
			break;
		}
	}
	if (i == tl)
	{
		return false;
	}
	for (; i < tl; ++i)
	{
		if (t[i] == s[k])
		{
			k++;
		}
		else
		{
			k = s1;
		}
		if (k == s2)
		{
			break;
		}
	}
	if (i == tl)
	{
		return false;
	}
	for (; i <= tl; ++i)
	{
		if (t[i] == s[k])
		{
			k++;
		}
		else
		{
			k = s2;
		}
		if (k == l)
		{
			break;
		}
	}
	if (k == l)
	{
		return true;
	}
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", t);
		tl = strlen(t);
		if (tl < l)
		{
			printf("NO\n");
			continue;
		}
		bool flag = false;
		for (int i = 1; i < l && !flag; ++i)
		{
			for (int j = i + 1; j < l && !flag; ++j)
			{
				if (check(i, j))
				{
					flag = true;
				}
			}
		}
		if (flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
