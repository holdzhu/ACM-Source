#include <cstdio>
#include <cstring>

const char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};

int c229(int year, int month, int day)
{
	int rnt = 0;
	rnt += (year + 3 - 2000) / 4;
	rnt -= (year + 99 - 2000) / 100;
	rnt += (year + 399 - 2000) / 400;
	if ((year % 400 == 0 || (year % 100 > 0 && year % 4 == 0)) && (month > 1 || (month == 1 && day == 29)))
	{
		rnt++;
	}
	return rnt;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		char monthstring1[10];
		int day1, year1, month1;
		scanf("%s %d,%d", monthstring1, &day1, &year1);
		for (int i = 0; i < 12; ++i)
		{
			if (strcmp(monthstring1, months[i]) == 0)
			{
				month1 = i;
				break;
			}
		}
		char monthstring2[10];
		int day2, year2, month2;
		scanf("%s %d,%d", monthstring2, &day2, &year2);
		for (int i = 0; i < 12; ++i)
		{
			if (strcmp(monthstring2, months[i]) == 0)
			{
				month2 = i;
				break;
			}
		}
		int ans = c229(year2, month2, day2) - c229(year1, month1, day1);
		if (month1 == 1 && day1 == 29)
		{
			ans++;
		}
		printf("Case #%d: %d\n", kase, ans);
	}
	return 0;
}
