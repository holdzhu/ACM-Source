#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		set<int> A, B, C;
		int n;
		int t;
		scanf("%d", &n);
		while (n--)
		{
			scanf("%d", &t);
			A.insert(t);	
		}
		scanf("%d", &n);
		while (n--)
		{
			scanf("%d", &t);
			B.insert(t);	
		}
		set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(C, C.begin()));
		bool b = false;
		printf("{");
		for (set<int>::iterator i = C.begin(); i != C.end(); ++i)
		{
			if (b)
			{
				printf(",");
			}
			else
			{
				b = true;
			}
			printf("%d", *i);
		}
		printf("}\n");
	}
	return 0;
}
