#include <cstdio>
#include <algorithm>

using namespace std;

int sumF[467];
int sumM[467];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		char c;
		int a, b;
		scanf(" %c %d %d", &c, &a, &b);
		if (c == 'M')
		{
			sumM[a]++;
			sumM[b + 1]--;
		}
		else
		{
			sumF[a]++;
			sumF[b + 1]--;
		}
	}
	int ans = 0;
	for (int i = 1; i <= 366; ++i)
	{
		sumF[i] += sumF[i - 1];
		sumM[i] += sumM[i - 1];
		ans = max(ans, min(sumF[i], sumM[i]));
	}
	printf("%d\n", ans * 2);
	return 0;
}
