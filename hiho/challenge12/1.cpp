#include <cstdio>
#include <cstring>

const char numchar[14] = "A234567891JQK";
const char typechar[5] = "SHCD";
bool num[13];
bool type[4];

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	memset(num, 0, sizeof num);
	memset(type, 0, sizeof type);
	for (int i = 0; i < 4; ++i)
	{
		char s[4];
		scanf("%s", s);
		char n = s[0];
		char t = s[0] == '1' ? s[2] : s[1];
		for (int i = 0; i < 13; ++i)
		{
			if (numchar[i] == n)
			{
				num[i] = true;
				break;
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			if (typechar[i] == t)
			{
				type[i] = true;
				break;
			}
		}
	}
	int numcnt = 0;
	for (int i = 0; i <= 10; ++i)
	{
		int c = 0;
		for (int j = 0; j < 5; ++j)
		{
			if (num[(i + j) % 13])
			{
				c++;
			}
		}
		if (c == 4)
		{
			numcnt++;
		}
	}
	int typecnt = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (type[i])
		{
			typecnt++;
		}
	}
	int ans = (4 - (typecnt == 1)) * numcnt;
	printf("%d/%d\n", ans / gcd(ans, 48), 48 / gcd(ans, 48));
	return 0;
}
