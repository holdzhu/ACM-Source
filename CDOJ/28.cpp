#include <cstdio>
#include <cstring>

int a[101];

int solve(int x)
{

}

int main()
{
	int N;
	while (scanf("%d", &N) == 1)
	{
		memset(a, 0, sizeof(a));
		while (--N)
		{
			int A, T;
			scanf("%d %d", &A, &T);
			a[T] += A;
		}
		int P, H;
		scanf("%d %d", &P, &H);
		int l = 0;
		int r = 100 * H;
		
	}
	return 0;
}
