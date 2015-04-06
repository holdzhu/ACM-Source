#include <cstdio>
#include <cstring>

int main()
{
	char s[200001];
	char t[200001];
	scanf("%s %s", s, t);
	int cs[54];
	int ct[54];
	memset(cs, 0, sizeof(cs));
	memset(ct, 0, sizeof(ct));
	for (int i = 0; s[i] != '\0'; ++i)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			cs[s[i] - 'a']++;
		}
		else
		{
			cs[s[i] - 'A' + 26]++;
		}
	}
	for (int i = 0; t[i] != '\0'; ++i)
	{
		if (t[i] >= 'a' && t[i] <= 'z')
		{
			ct[t[i] - 'a']++;
		}
		else
		{
			ct[t[i] - 'A' + 26]++;
		}
	}
	int s1 = 0;
	int s2 = 0;
	for (int i = 0; i < 54; ++i)
	{
		if (cs[i] > ct[i])
		{
			cs[i] -= ct[i];
			s1 += ct[i];
			ct[i] = 0;
		}
		else
		{
			ct[i] -= cs[i];
			s1 += cs[i];
			cs[i] = 0;
		}
	}
	for (int i = 0; i < 26; ++i)
	{
		cs[i] += cs[i + 26];
		ct[i] += ct[i + 26];
	}
	for (int i = 0; i < 26; ++i)
	{
		if (cs[i] > ct[i])
		{
			cs[i] -= ct[i];
			s2 += ct[i];
			ct[i] = 0;
		}
		else
		{
			ct[i] -= cs[i];
			s2 += cs[i];
			cs[i] = 0;
		}
	}
	printf("%d %d\n", s1, s2);
	return 0;
}
