#include <cstdio>
#include <cstring>

char k[101];
char C[1001];

int main()
{
	scanf("%s %s", k, C);
	int n = strlen(k);
	int m = strlen(C);
	for (int i = 0; i < n; ++i)
		if (k[i] >= 'a')
			k[i] = k[i] - 'a' + 'A';
	for (int i = 0; i < m; ++i)
	{
		bool lower = false;
		if (C[i] >= 'a')
			C[i] = C[i] - 'a' + 'A', lower = true;
		int ori = ((C[i] - 'A') + 26 - (k[i % n] - 'A')) % 26;
		putchar((lower ? 'a' : 'A') + ori);
	}
	puts("");
	return 0;
}
