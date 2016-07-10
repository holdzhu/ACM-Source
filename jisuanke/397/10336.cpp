#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[10001];
char ans[3][10001];

int main()
{
	scanf("%s", s);
	int l = strlen(s);
	int sum = 0;
	for (int i = 0; i < l; ++i)
		sum += s[i] - '0';
	if (sum % 3 == 0)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0, rem = sum / 3; j < l; ++j)
			{
				int dif = min(rem, s[j] - '0');
				ans[i][j] = '0' + dif;
				s[j] -= dif;
				rem -= dif;
			}
			int first = 0;
			while (first < l - 1 && ans[i][first] == '0')
				++first;
			printf("%s%c", ans[i] + first, "\n "[i < 2]);
		}
	}
	else
		puts("-1");
	return 0;
}
