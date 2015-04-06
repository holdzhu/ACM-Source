#include <cstdio>
#include <cstring>

char str1[27];
char str2[27];

void solve(int s1, int s2, int n)
{
	if (n <= 1)
	{
		return;
	}
	int m;
	for (m = s2; str2[m] != str1[s1]; ++m);
	solve(s1 + 1, s2, m - s2);
	solve(s1 + 1 + m - s2, m + 1, s2 + n - m - 1);
	char c = str1[s1];
	for (int i = s1; i < s1 + n - 1; ++i)
	{
		str1[i] = str1[i + 1];
	}
	str1[s1 + n - 1] = c;
}

int main()
{
	scanf("%s %s", str1, str2);
	solve(0, 0, strlen(str1));
	printf("%s\n", str1);
	return 0;
}
