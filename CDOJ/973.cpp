#include <cstdio>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char s1[101], s2[101];
		scanf("%s", s1);
		scanf("%s", s2);
		if (s1[0] == '0' || s2[0] == '0')
		{
			printf("0\n");
			continue;
		}
		int l1 = strlen(s1);
		int l2 = strlen(s2);
		int s[l1 + l2];
		for (int i = 0; i < l1 + l2; ++i)
		{
			s[i] = 0;
		}
		for (int i = 0; i < l1; ++i)
		{
			for (int j = 0; j < l2; ++j)
			{
				s[i + j + 1] += (s1[i] - '0') * (s2[j] - '0');
			}
		}
		for (int i = l1 + l2 - 1; i >= 0; --i)
		{
			int t = 10;
			int pos = 1;
			while (s[i] / t >= 1)
			{
				s[i - pos] += s[i] / t % 10;
				t *= 10;
				pos++;
			}
			s[i] %= 10;
		}
		int f = 0;
		while (s[f++] == 0);
		for (int i = f - 1; i < l1 + l2; ++i)
		{
			printf("%d", s[i]);
		}
		printf("\n");
	}
	return 0;
}
