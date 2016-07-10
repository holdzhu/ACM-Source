#include <cstdio>
#include <cstring>

int N;
char s[1000];

int main()
{
	scanf("%d", &N);
	int sum = 0;
	int mi = 1e9;
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", s);
		int l = strlen(s);
		int t = 0;
		int t2 = 0;
		for (int i = 0; i < l; ++i)
		{
			if (s[i] == 'o')
			{
				t = l - i;
				for (int j = i + 1; j < l; ++j)
					t2 += s[j] == 'x';
				break;
			}
		}
		if (mi > t2)
			mi = t2;
		sum += t;
	}
	printf("%d\n", mi + sum);
	return 0;
}
