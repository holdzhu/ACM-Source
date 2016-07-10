#include <cstdio>
#include <algorithm>

using namespace std;

int a[100000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; ++i)
		printf("%d%c", a[i], "\n "[i < n - 1]);
	return 0;
}
