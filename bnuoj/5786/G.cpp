#include <cstdio>
#include <cstring>

int main()
{
	char s[101];
	scanf("%s", s);
	int l = strlen(s);
	int b0 = 0;
	int b1 = 0;
	for (int i = 0; i < l; ++i)
	{
		if (s[i] == '0')
		{
			if (s[(i + 1) % l] == '0')
			{
				b0++;
			}
			else
			{
				b1++;
			}
		}
	}
	if ((b0 + b1) * (b0 + b1) > b0 * l)
	{
		printf("ROTATE\n");
	}
	else if ((b0 + b1) * (b0 + b1) < b0 * l)
	{
		printf("SHOOT\n");
	}
	else
	{
		printf("EQUAL\n");
	}
	return 0;
}
