#include <cstdio>
#include <cstring>

const char numstr[10][20] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char tenstr[8][20] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char tenthstr[10][20] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char trialstr[2][20] = {"thousand", "million"};
const char hundredstr[20] = "hundred";

void showtriads(int a, int b, int c)
{
	if (a)
	{
		if (b)
		{
			if (c)
			{
				if (b == 1)
				{
					printf(" %s %s and %s", numstr[a - 1], hundredstr, tenthstr[c]);
				}
				else
				{
					printf(" %s %s and %s-%s", numstr[a - 1], hundredstr, tenstr[b - 2], numstr[c - 1]);
				}
			}
			else
			{
				if (b == 1)
				{
					printf(" %s %s and %s", numstr[a - 1], hundredstr, tenthstr[0]);
				}
				else
				{
					printf(" %s %s and %s", numstr[a - 1], hundredstr, tenstr[b - 2]);
				}
			}
		}
		else
		{
			if (c)
			{
				printf(" %s %s and %s", numstr[a - 1], hundredstr, numstr[c - 1]);
			}
			else
			{
				printf(" %s %s", numstr[a - 1], hundredstr);
			}
		}
	}
	else
	{
		if (b)
		{
			if (c)
			{
				if (b == 1)
				{
					printf(" %s", tenthstr[c]);
				}
				else
				{
					printf(" %s-%s", tenstr[b - 2], numstr[c - 1]);
				}
			}
			else
			{
				if (b == 1)
				{
					printf(" %s", tenthstr[0]);
				}
				else
				{
					printf(" %s", tenstr[b - 2]);
				}
			}
		}
		else
		{
			printf(" %s", numstr[c - 1]);
		}
	}
}

int main()
{
	int n;
	int Test = 1;
	int num[15];
	while (scanf("%d", &n) == 1 && n)
	{
		printf("Test %d:", Test++);
		memset(num, 0, sizeof num);
		int p = 0;
		while (n)
		{
			num[p++] = n % 10;
			n /= 10;
		}
		int tricount = (p + 2) / 3;
		int lasttrial;
		int realcount = 0;
		for (int i = tricount - 1; i >= 0; --i)
		{
			int a = num[i * 3 + 2];
			int b = num[i * 3 + 1];
			int c = num[i * 3];
			if (a || b || c)
			{
				lasttrial = i;
				realcount++;
			}
		}
		for (int i = tricount - 1; i > lasttrial; --i)
		{
			int a = num[i * 3 + 2];
			int b = num[i * 3 + 1];
			int c = num[i * 3];
			if (a || b || c)
			{
				showtriads(a, b, c);
				printf(" %s", trialstr[i - 1]);
			}
		}
		int a = num[lasttrial * 3 + 2];
		int b = num[lasttrial * 3 + 1];
		int c = num[lasttrial * 3];
		if (realcount >= 2 && a == 0 && lasttrial == 0)
		{
			printf(" and");
		}
		showtriads(a, b, c);
		if (lasttrial > 0)
		{
			printf(" %s", trialstr[lasttrial - 1]);
		}
		printf("\n");
	}
	return 0;
}
