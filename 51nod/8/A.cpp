#include <cstdio>
#include <cstring>

char s[1000001];

int solve()
{
	int ones = 0;
	int l = strlen(s);
	for (int i = 0; i < l; ++i)
	{
		if (s[i] == '1')
		{
			ones++;
		}
	}
	int zero = 0;
	for (int i = 0; i < l; ++i)
	{
		if (zero == ones - (i - zero))
		{
			return i;
		}
		zero += s[i] == '0';
	}
	if (zero == 0)
	{
		return l;
	}
	return -1;
}

int main()
{
	scanf("%s", s);
	printf("%d\n", solve());
	return 0;
}
