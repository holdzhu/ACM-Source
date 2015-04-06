#include <cstdio>
#include <cstring>

char s1[10001];
char s2[10001];

int main()
{
	int a, b;
	scanf("%s %s", s1, s2);
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	if (s1[0] == '0' && (s1[1] == 'x' || s1[1] == 'X'))
	{
		sscanf(s1, "%x", &a);
	}
	else if (s1[0] == '0' && l1 > 1)
	{
		sscanf(s1, "%o", &a);
	}
	else
	{
		sscanf(s1, "%d", &a);
	}
	if (s2[0] == '0' && (s2[1] == 'x' || s2[1] == 'X'))
	{
		sscanf(s2, "%x", &b);
	}
	else if (s2[0] == '0' && l2 > 1)
	{
		sscanf(s2, "%o", &b);
	}
	else
	{
		sscanf(s2, "%d", &b);
	}
	printf("%d\n", a + b);
	return 0;
}
