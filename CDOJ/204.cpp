#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	int s = 0;
	while (v.size() > 1)
	{
		int _v = v[0] + v[1];
		s += _v;
		v.erase(v.begin(), v.begin() + 2);
		v.insert(lower_bound(v.begin(), v.end(), _v), _v);
	}
	printf("%d\n", s);
	return 0;
}
