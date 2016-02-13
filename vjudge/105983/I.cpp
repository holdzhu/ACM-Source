#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const char thou[10][5] = {"", "M", "MM", "MMM"};
const char hund[10][5]
	= {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const char tent[10][5]
	= {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const char onet[10][5]
	= {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

char s[100001];
int cnt[128];
int tmp[4];
int c[128];
char ans[100];
char ts[100];

int main()
{
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; ++i)
	{
		if (s[i] >= 'a')
			s[i] -= 'a' - 'A';
		cnt[(int)s[i]]++;
	}
	int val = 0;
	int len = 0;
	for (int i = 1; i < 4000; ++i)
	{
		int t = i;
		for (int j = 0; j < 4; ++j)
		{
			tmp[j] = t % 10;
			t /= 10;
		}
		int j = 0;
		strcpy(ts + j, thou[tmp[3]]);
		j += strlen(thou[tmp[3]]);
		strcpy(ts + j, hund[tmp[2]]);
		j += strlen(hund[tmp[2]]);
		strcpy(ts + j, tent[tmp[1]]);
		j += strlen(tent[tmp[1]]);
		strcpy(ts + j, onet[tmp[0]]);
		j += strlen(onet[tmp[0]]);
		for (int k = 0; k < 128; ++k)
			c[k] = 0;
		for (int k = 0; k < j; ++k)
			c[(int)ts[k]]++;
		bool flag = true;
		for (int k = 0; k < 128; ++k)
			if (c[k] > cnt[k])
				flag = false;
		if (flag && len <= j)
		{
			strncpy(ans, ts, j);
			len = j;
			val = i;
		}
	}
	printf("%s\n", ans);
	return 0;
}
