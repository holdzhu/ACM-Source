#include <cstdio>
#include <set>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		set<int> s;
		while (n--)
		{
			int t;
			scanf("%d", &t);
			s.insert(t);
		}
		printf("%d ", s.size());
		for (set<int>::iterator i = s.begin(); i != s.end(); ++i)
		{
			printf("%d ", *i);
		}
		printf("\n");
	}
	return 0;
}
