#include <cstdio>

char s[200001];
int cnt[26];

int main()
{
	scanf("%s", s);
	for (int i = 0; s[i]; ++i)
	{
		cnt[s[i] - 'a']++;
	}
	int num = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (cnt[i] % 2 == 1)
		{
			num++;
		}
	}
	int j = 0;
	for (int i = 0; i < num / 2; ++i)
	{
		while (j < 26 && cnt[j] % 2 == 0)
		{
			j++;
		}
		j++;
	}
	bool flag = num % 2;
	int k = 0;
	for (int i = 0; i < num; ++i)
	{
		while (j < 26 && cnt[j] % 2 == 0)
		{
			j++;
		}
		while (k < 26 && cnt[k] % 2 == 0)
		{
			k++;
		}
		if (flag && cnt[j] )
		{
			while (j < 26 && cnt[j] % 2 == 0)
			{
				j++;
			}
		}
		cnt[k]++;
		cnt[j]--;
	}
	int odd = -1;
	for (int i = 0; i < 26; ++i)
	{
		if (cnt[i] % 2 == 1)
		{
			odd = i;
		}
		else
		{
			for (int j = 0; j < cnt[i] / 2; ++j)
			{
				putchar('a' + i);
			}
		}
	}
	if (odd != -1)
	{
		for (int i = 0; i < cnt[odd]; ++i)
		{
			putchar('a' + odd);
		}
	}
	for (int i = 25; i >= 0; --i)
	{
		if (cnt[i] % 2 == 1)
		{
			odd = i;
		}
		else
		{
			for (int j = 0; j < cnt[i] / 2; ++j)
			{
				putchar('a' + i);
			}
		}
	}
	return 0;
}