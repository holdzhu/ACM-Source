#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	long long l, r;
	int k;
	scanf("%I64d %I64d %d", &l, &r, &k);
	vector<long long> ans;
	if (l == 1)
		ans.push_back(1);
	long long s = 1;
	while (s <= r / k)
	{
		s *= k;
		if (s >= l)
			ans.push_back(s);
	}
	if (ans.size())
		for (int i = 0; i < ans.size(); ++i)
			printf("%I64d ", ans[i]);
	else
		puts("-1");
	return 0;
}
