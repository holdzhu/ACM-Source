#include <cstdio>
#include <cstring>

int main()
{
	char s[11];
	scanf("%s", s);
	int l = strlen(s);
	char _s[l + 2];
	_s[l + 1] = '\0';
	int left = 0;
	int right = 0;
	bool success = true;
	for (int i = 0; i < l / 2 + 1; ++i)
	{
		if (s[i - left] != s[l - i - 1 + right])
		{
			if (left == 0)
			{
				left = 1;
				_s[i] = s[l - i - 1];
				_s[l - i] = s[l - i - 1];
			}
			else
			{
				success = false;
				break;
			}
		}
		else
		{
			_s[i] = s[i - left];
			_s[l - i + right] = s[l - i - 1 + right];
		}
	}
	if (success)
	{
		if (l % 2 == 0)
		{
			if (left)
			{
				_s[l / 2] = s[l / 2 - 1];
			}
			else
			{
				_s[l / 2] = 'a';
			}
		}
		printf("%s\n", _s);
	}
	else
	{
		success = true;
		left = 0;
		for (int i = 0; i < l / 2 + 1; ++i)
		{
			if (s[i - left] != s[l - i - 1 + right])
			{
				if (right == 0)
				{
					right = 1;
					_s[l - i] = s[i];
					_s[i] = s[i];
				}
				else
				{
					success = false;
					break;
				}
			}
			else
			{
				_s[i - left] = s[i - left];
				_s[l - i] = s[l - i - 1 + right];
			}
		}
		if (success)
		{
			if (l % 2 == 0)
			{
				if (right)
				{
					_s[l / 2] = s[l / 2];
				}
				else
				{
					_s[l / 2] = 'a';
				}
			}
			printf("%s\n", _s);
		}
		else
		{
			printf("NA\n");
		}
	}
	return 0;
}
