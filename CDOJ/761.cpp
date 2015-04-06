#include <cstdio>
#include <cstring>

int main()
{
	int T;
	char A[100002], B[100002];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s %s", A, B);
		int l = strlen(B);
		int _l = strlen(A);
		if (l > _l)
		{
			printf("0\n");
		}
		else if (l < _l)
		{
			printf("Poor LoveZx\n");
		}
		else
		{
			int pos;
			int dpos = 0;
			int c = 0;
			int _c = 0;
			int count[10];
			memset(count, 0, sizeof(count));
			for (int i = 0; i < l; ++i)
			{
				count[B[i] - '0']++;
			}
			for (pos = 0; pos < l; ++pos)
			{
				while (count[B[pos - dpos] - '0'] == 0)
				{
					dpos--;
				}
				if (A[pos] > B[pos - dpos])
				{
					char max = '0';
					for (int i = 9; i > 0; --i)
					{
						if (count[i])
						{
							max = i + '0';
							break;
						}
					}
					if (max > A[pos])
					{
						printf("%d\n", c + 1);
						break;
					}
					else if (max < A[pos])
					{
						if (_c)
						{
							printf("%d\n", _c);
						}
						else
						{
							printf("Poor LoveZx\n");
						}
						break;
					}
					else
					{
						count[max - '0']--;
						c++;
						dpos++;
					}
				}
				else if (A[pos] < B[pos - dpos])
				{
					printf("%d\n", c);
					break;
				}
				else
				{
					char max = '0';
					for (int i = 9; i > 0; --i)
					{
						if (count[i])
						{
							max = i + '0';
							break;
						}
					}
					if (max > A[pos])
					{
						if (_c == 0)
						{
							_c = c + 1;
						}
					}
					count[B[pos - dpos] - '0']--;
				}
			}
			if (pos == l)
			{
				if (_c)
				{
					printf("%d\n", _c);
				}
				else
				{
					printf("Poor LoveZx\n");
				}
			}
		}
	}
	return 0;
}
