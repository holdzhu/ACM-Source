#include <cstdio>
#include <cmath>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int A, B;
		scanf("%d %d", &A, &B);
		int a, b;
		if (A <= 2)
		{
			a = 1;
		}
		else if (A % 2)
		{
			int s = sqrt(A);
			bool isprime = true;
			for (int i = 3; i <= s; i += 2)
			{
				if (A % i == 0)
				{
					isprime = false;
					break;
				}
			}
			if (isprime)
			{
				a = 1;
			}
			else
			{
				isprime = true;
				for (int i = 3; i <= s; i += 2)
				{
					if ((A - 2) % i == 0)
					{
						isprime = false;
						break;
					}
				}
				if (isprime)
				{
					a = 2;
				}
				else
				{
					a = 3;
				}
			}
		}
		else
		{
			a = 2;
		}
		if (B <= 2)
		{
			b = 1;
		}
		else if (B % 2)
		{
			int s = sqrt(B);
			bool isprime = true;
			for (int i = 3; i <= s; i += 2)
			{
				if (B % i == 0)
				{
					isprime = false;
					break;
				}
			}
			if (isprime)
			{
				b = 1;
			}
			else
			{
				isprime = true;
				for (int i = 3; i <= s; i += 2)
				{
					if ((B - 2) % i == 0)
					{
						isprime = false;
						break;
					}
				}
				if (isprime)
				{
					b = 2;
				}
				else
				{
					b = 3;
				}
			}
		}
		else
		{
			b = 2;
		}
		if (b <= a)
		{
			printf("God Li\n");
		}
		else
		{
			printf("Master Qiu\n");
		}
	}
	return 0;
}
