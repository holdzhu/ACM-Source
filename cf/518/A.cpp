#include <cstdio>
#include <cstring>

int main()
{
	char a[101];
	char b[101];
	scanf("%s %s", a, b);
	int l = strlen(a);
	bool flag = false;
	for (int i = 0; i < l; ++i)
	{
		if (a[i] > b[i])
		{
			break;
		}
		if ((a[i] < b[i] && i < l - 1) || a[i] < b[i] - 1)
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		int p = l - 1;
		while (a[p] == 'z')
		{
			a[p] = 'a';
			p--;
		}
		a[p]++;
		printf("%s\n", a);
	}
	else
	{
		printf("No such string\n");
	}
	return 0;
}
