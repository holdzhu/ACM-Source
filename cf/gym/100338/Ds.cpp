#include <cstdio>
#include <algorithm>

using namespace std;

int a[3];

int main()
{
	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);
	while (scanf("%d %d %d", &a[0], &a[1], &a[2]) == 3 && a[0] | a[1] | a[2])
	{
		printf("%s wins the game.\n", (a[0] + 2) ^ (a[1] + 2) ^ (a[2] + 2) ? "Alice" : "Bob");
	}
	return 0;
}
