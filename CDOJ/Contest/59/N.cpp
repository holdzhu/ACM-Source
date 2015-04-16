#include <cstdio>
#include <cstring>
#include <cctype>
#include <stack>

using namespace std;

char s[1000001];
char *p;

long long readInt()
{
	long long rnt = 0;
	bool sign = false;
	if (*p == '-')
	{
		sign = true;
		p++;
	}
	while (isdigit(*p))
	{
		rnt *= 10;
		rnt += *p - '0';
		p++;
	}
	return sign ? -rnt : rnt;
}

bool low(char c)
{
	return c == '+' || c == '-';
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		p = s;
		stack<long long> nums;
		stack<char> type;
		nums.push(readInt());
		while (*p)
		{
			char c = *(p++);
			long long t = readInt();
			while (!type.empty() && low(type.top()) && low(c))
			{
				long long a = nums.top();
				nums.pop();
				if (type.top() == '-')
				{
					a = -a;
				}
				nums.top() += a;
				type.pop();
			}
			if (!low(c))
			{
				if (c == '*')
				{
					nums.top() *= t;
				}
				else
				{
					nums.top() /= t;
				}
			}
			else
			{
				type.push(c);
				nums.push(t);
			}
		}
		while (!type.empty())
		{
			long long a = nums.top();
			nums.pop();
			if (type.top() == '-')
			{
				a = -a;
			}
			nums.top() += a;
			type.pop();
		}
		printf("%lld\n", nums.top());
	}
	return 0;
}
