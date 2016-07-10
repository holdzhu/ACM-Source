#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < a.size() - 1; ++i)
		if (__gcd(a[i], a[i + 1]) != 1)
			a.insert(a.begin() + i + 1, 1);
	printf("%d\n", a.size() - n);
	for (int i = 0; i < a.size(); ++i)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
