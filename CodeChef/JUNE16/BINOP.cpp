#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char A[1000001];
char B[1000001];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s %s", A, B);
		int n = strlen(A);
		bool zeroA = false;
		bool zeroB = false;
		bool oneA = false;
		bool oneB = false;
		for (int i = 0; i < n; ++i)
		{
			zeroA |= A[i] == '0';
			zeroB |= B[i] == '0';
			oneA |= A[i] == '1';
			oneB |= B[i] == '1';
		}
		if ((!zeroA && zeroB) || (!oneA && oneB))
			puts("Unlucky Chef");
		else
		{
			puts("Lucky Chef");
			int cnt1 = 0, cnt2 = 0;
			for (int i = 0; i < n; ++i)
			{
				if (A[i] != B[i])
				{
					if (A[i] == '0')
						cnt1++;
					else
						cnt2++;
				}
			}
			printf("%d\n", max(cnt1, cnt2));
		}
	}
	return 0;
}
