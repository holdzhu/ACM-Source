#include <cstdio>
#include <cstring>

int main()
{
	int n;
	scanf("%d", &n);
	bool b[20001];
	memset(b, 0, sizeof(b));
	bool unique = true;
	while (n--)
	{
		int t;
		scanf("%d", &t);
		if (b[t + 10000] || t == 0)
		{
			unique = false;
			break;
		}
		b[10000 - t] = true;
	}
	printf("%sUNIQUE\n", unique ? "" : "NOT ");
	return 0;
}
