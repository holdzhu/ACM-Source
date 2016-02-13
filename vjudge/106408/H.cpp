#include <cstdio>

int ans[100];

int main()
{
	int n;
	scanf("%d", &n);
	int l = 1, r = n;
	for (int i = 0; i < n / 2; ++i)
	{
		if ((i ^ (i >> 1)) & 1)
		{
			ans[i] = r--;
			ans[n - 1 - i] = r--;
		}
		else
		{
			ans[i] = l++;
			ans[n - 1 - i] = l++;
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
	return 0;
}
