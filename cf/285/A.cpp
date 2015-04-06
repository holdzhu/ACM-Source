#include <cstdio>

int main()
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	double s1 = 3.0 * a / 10;
	double s2 = a - a / 250.0 * c;
	double s3 = 3.0 * b / 10;
	double s4 = b - b / 250.0 * d;
	if (s2 > s1)
	{
		s1 = s2;
	}
	if (s4 > s3)
	{
		s3 = s4;
	}
	if (s1 > s3)
	{
		printf("Misha\n");
	}
	else if (s1 < s3)
	{
		printf("Vasya\n");
	}
	else
	{
		printf("Tie\n");
	}
	return 0;
}
