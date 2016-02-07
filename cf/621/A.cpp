#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	long long esum = 0;
	long long osum = 0;
	long long miodd = 2e9;
	for (int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		if (t & 1)
		{
			osum += t;
			if (t < miodd)
				miodd = t;
		}
		else
			esum += t;
	}
	printf("%I64d\n", esum + osum - (osum & 1 ? miodd : 0));
	return 0;
}
