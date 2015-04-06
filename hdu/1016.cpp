#include <cstdio>
#include <cstring>

const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
bool ok[20][20];
int nums[20] = {1};
bool used[20];
int n;

void dfs(int depth)
{
	if (depth == n)
	{
		if (ok[nums[0]][nums[n - 1]])
		{
			printf("%d", nums[0]);
			for (int i = 1; i < n; ++i)
			{
				printf(" %d", nums[i]);
			}
			printf("\n");
		}
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!used[i] && (depth == 0 || ok[nums[depth - 1]][i]))
		{
			used[i] = true;
			nums[depth] = i;
			dfs(depth + 1);
			used[i] = false;
		}
	}
}

int main()
{
	memset(ok, 0, sizeof(ok));
	for (int i = 1; i < 20; ++i)
	{
		for (int j = 1; j < 20; ++j)
		{
			for (int k = 0; k < 12; ++k)
			{
				if (primes[k] == i + j)
				{
					ok[i][j] = true;
					ok[j][i] = true;
					break;
				}
			}
		}
	}
	int kase = 1;
	while (scanf("%d", &n) == 1)
	{
		memset(used, 0, sizeof(used));
		used[1] = true;
		printf("Case %d:\n", kase++);
		if (n == 1 || n % 2 == 0)
		{
			dfs(1);
		}
		printf("\n");
	}
	return 0;
}
