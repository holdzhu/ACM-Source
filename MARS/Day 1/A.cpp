#include <cstdio>

int main()
{
	const char num[10][9] = {
		"O-|-OOOO",
		"O-|O-OOO",
		"O-|OO-OO",
		"O-|OOO-O",
		"O-|OOOO-",
		"-O|-OOOO",
		"-O|O-OOO",
		"-O|OO-OO",
		"-O|OOO-O",
		"-O|OOOO-",
	};
	int n;
	scanf("%d", &n);
	if (n)
	{
		while (n)
		{
			printf("%s\n", num[n % 10]);
			n /= 10;
		}
	}
	else
	{
		printf("%s\n", num[0]);
	}
	return 0;
}
