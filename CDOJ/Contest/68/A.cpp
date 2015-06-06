#include <cstdio>
#include <cstring>

char s[100002];
const int mod[] = {0, 1, 4, 7, 6, 5, 6, 3, 6, 9, 0, 1, 6, 3, 6, 5, 6, 7, 4, 9};
const int sigma = 94;

int main()
{
	scanf("%s", s);
	int l = strlen(s);
	int num = s[l - 1] - '0';
	int sum = 0;
	if (l > 1)
	{
		num += (s[l - 2] - '0') * 10;
	}
	sum = num / 20 * sigma;
	num %= 20;
	for (int i = 0; i <= num; ++i)
	{
		sum += mod[i];
	}
	printf("%d\n", sum % 10);
	return 0;
}
