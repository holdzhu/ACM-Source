#include <cstdio>
#include <cstring>

char s[1001];
char t[1001];

int sum1[1000002];
int sum2[1000002];

int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	scanf("%s", t);
	int m = strlen(s);
	int k = strlen(t);
	sum1[0] = 0;
	sum2[0] = 0;
	for (int i = 0; i < m * k; ++i)
	{
		sum1[i + 1] = sum1[i];
		sum2[i + 1] = sum2[i];
		if (s[i % m] == 'R')
		{
			if (t[i % k] == 'S')
				sum1[i + 1]++;
			else if (t[i % k] == 'P')
				sum2[i + 1]++;
		}
		else if (s[i % m] == 'S')
		{
			if (t[i % k] == 'P')
				sum1[i + 1]++;
			else if (t[i % k] == 'R')
				sum2[i + 1]++;
		}
		else
		{
			if (t[i % k] == 'R')
				sum1[i + 1]++;
			else if (t[i % k] == 'S')
				sum2[i + 1]++;
		}
	}
	int ans1 = sum1[m * k] * (n / (m * k)) + sum1[n % (m * k)];
	int ans2 = sum2[m * k] * (n / (m * k)) + sum2[n % (m * k)];
	printf("%d %d\n", ans2, ans1);
	return 0;
}
