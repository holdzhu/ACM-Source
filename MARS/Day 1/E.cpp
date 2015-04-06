#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	int c = 0;
	set<set<int>[3]> s;
	bool b[N];
	memset(b, 0, sizeof(b));
	while (K--)
	{
		int D, X, Y;
		scanf("%d %d %d", &D, &X, &Y);
		if (X > N || Y > N)
		{
			c++;
		}
		else
		{
			if (D == 1)
			{
				if (b[X] && b[Y])
				{
					
				}
				else if (b[X])
				{

				}
				else if (b[Y])
				{

				}
				else
				{

				}
			}
			else
			{

			}
		}
	}
	return 0;
}
