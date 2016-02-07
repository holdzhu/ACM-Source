#include <cstdio>

char s[100010];
char a[100010];
char b[100010];

int main()
{
	scanf("%s", s);
	int fa = 0, fb = 0;
	for (int i = 0, j = 0, k = 0; ; ++i)
	{
		bool num = (s[i] >= '1' && s[i] <= '9') || (s[i] == '0' && (s[i + 1] == ',' || s[i + 1] == ';' || s[i + 1] == 0));
		int t = i;
		while (s[t] != ',' && s[t] != ';' && s[t] != 0)
		{
			if (s[t] < '0' || s[t] > '9')
			{
				num = false;
				break;
			}
			t++;
		}
		if (num)
		{
			if (fa)
			{
				a[j++] = ',';
			}
			fa = true;
			for ( ; s[i] != ',' && s[i] != ';' && s[i] != 0; ++i)
			{
				a[j++] = s[i];
			}
		}
		else
		{
			if (fb)
			{
				b[k++] = ',';
			}
			fb = true;
			for ( ; s[i] != ',' && s[i] != ';' && s[i] != 0; ++i)
			{
				b[k++] = s[i];
			}
		}
		if (s[i] == 0)
		{
			break;
		}
	}
	if (fa)
	{
		printf("\"%s\"\n", a);
	}
	else
	{
		puts("-");
	}
	if (fb)
	{
		printf("\"%s\"\n", b);
	}
	else
	{
		puts("-");
	}
	return 0;
}
