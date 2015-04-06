#include <cstdio>
#include <cstring>

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
	long long g = gcd(a, b);
	return a / g * b;
}

struct fra
{
	long long a, b;
	fra operator * (const fra rhs) 
	{
		long long u = a * rhs.a;
		long long v = b * rhs.b;
		long long g = gcd(u, v);
		return (fra) {u / g, v / g};
	}
	fra operator / (const fra rhs) 
	{
		long long u = a * rhs.b;
		long long v = b * rhs.a;
		long long g = gcd(u, v);
		return (fra) {u / g, v / g};
	}
	fra operator + (const fra rhs) 
	{
		long long u = a * rhs.b + rhs.a * b;
		long long v = b * rhs.b;
		long long g = gcd(u, v);
		return (fra) {u / g, v / g};
	}
	fra operator - (const fra rhs) 
	{
		long long u = a * rhs.b - rhs.a * b;
		long long v = b * rhs.b;
		long long g = gcd(u, v);
		return (fra) {u / g, v / g};
	}
};

int m[702];
int ele[702][20];

int main()
{
	char s[81];
	while (scanf("%s", s) == 1 && s[0] != '.')
	{
		memset(ele, 0, sizeof(ele));
		for (int i = 0; i < 702; ++i)
		{
			m[i] = -1;
		}
		int l = strlen(s);
		char le[2];
		int counte = 0;
		int countr = 0;
		int lep = 0;
		bool left = true;
		int num = -1;
		int times = 1;
		for (int i = 0; i < l; ++i)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				if (lep > 0)
				{
					int t = 0;
					if (lep == 1)
					{
						t = (le[0] - 'A') * 27;
					}
					else
					{
						t = (le[0] - 'A') * 27 + le[1] - 'a' + 1;
					}
					if (m[t] < 0)
					{
						m[t] = counte++;
					}
					ele[m[t]][countr] += (num == -1 ? 1 : num) * times * (left ? 1 : -1);
					num = -1;
				}
				lep = 1;
				le[0] = s[i];
			}
			else if (s[i] >= 'a' && s[i] <= 'z')
			{
				lep = 2;
				le[1] = s[i];
			}
			else if (s[i] >= '0' && s[i] <= '9')
			{
				if (num == -1)
				{
					num = 0;
				}
				num *= 10;
				num += s[i] - '0';
			}
			else if (s[i] == '+')
			{
				if (lep > 0)
				{
					int t = 0;
					if (lep == 1)
					{
						t = (le[0] - 'A') * 27;
					}
					else
					{
						t = (le[0] - 'A') * 27 + le[1] - 'a' + 1;
					}
					if (m[t] < 0)
					{
						m[t] = counte++;
					}
					ele[m[t]][countr] += (num == -1 ? 1 : num) * times * (left ? 1 : -1);
					num = -1;
					lep = 0;
				}
				countr++;
			}
			else if (s[i] == '-')
			{
				if (lep > 0)
				{
					int t = 0;
					if (lep == 1)
					{
						t = (le[0] - 'A') * 27;
					}
					else
					{
						t = (le[0] - 'A') * 27 + le[1] - 'a' + 1;
					}
					if (m[t] < 0)
					{
						m[t] = counte++;
					}
					ele[m[t]][countr] += (num == -1 ? 1 : num) * times * (left ? 1 : -1);
					num = -1;
					lep = 0;
				}
				i++;
				left = false;
				countr++;
			}
			else if (s[i] == '(')
			{
				if (lep > 0)
				{
					int t = 0;
					if (lep == 1)
					{
						t = (le[0] - 'A') * 27;
					}
					else
					{
						t = (le[0] - 'A') * 27 + le[1] - 'a' + 1;
					}
					if (m[t] < 0)
					{
						m[t] = counte++;
					}
					ele[m[t]][countr] += (num == -1 ? 1 : num) * times * (left ? 1 : -1);
					num = -1;
					lep = 0;
				}
				int _t = i;
				while (s[_t] != ')')
				{
					_t++;
				}
				_t++;
				times = -1;
				while (s[_t] >= '0' && s[_t] <= '9')
				{
					if (times == -1)
					{
						times = 0;
					}
					times *= 10;
					times += s[_t] - '0';
					_t++;
				}
				if (times == -1)
				{
					times = 1;
				}
			}
			else if (s[i] == ')')
			{
				if (lep > 0)
				{
					int t = 0;
					if (lep == 1)
					{
						t = (le[0] - 'A') * 27;
					}
					else
					{
						t = (le[0] - 'A') * 27 + le[1] - 'a' + 1;
					}
					if (m[t] < 0)
					{
						m[t] = counte++;
					}
					ele[m[t]][countr] += (num == -1 ? 1 : num) * times * (left ? 1 : -1);
					num = -1;
					lep = 0;
				}
				times = 1;
				while (s[i + 1] >= '0' && s[i + 1] <= '9')
				{
					i++;
				}
			}
			else
			{
				if (lep > 0)
				{
					int t = 0;
					if (lep == 1)
					{
						t = (le[0] - 'A') * 27;
					}
					else
					{
						t = (le[0] - 'A') * 27 + le[1] - 'a' + 1;
					}
					if (m[t] < 0)
					{
						m[t] = counte++;
					}
					ele[m[t]][countr] += (num == -1 ? 1 : num) * times * (left ? 1 : -1);
					num = -1;
					lep = 0;
				}
				i++;
				left = false;
				countr++;
			}
		}
		fra f[counte][countr];
		for (int i = 0; i < counte; ++i)
		{
			for (int j = 0; j < countr; ++j)
			{
				f[i][j].a = ele[i][j];
				f[i][j].b = 1;
			}
		}
		for (int i = 0; i < countr; ++i)
		{
			if (i >= counte)
			{
				break;
			}
			for (int j = i; j < counte; ++j)
			{
				if (f[j][i].a != 0)
				{
					for (int k = i; k < countr; ++k)
					{
						fra t = f[i][k];
						f[i][k] = f[j][k];
						f[j][k] = t;
					}
					break;
				}
			}
			if (f[i][i].a != 0)
			{
				for (int j = 0; j < counte; ++j)
				{
					if (i != j)
					{
						fra t = f[j][i] / f[i][i];
						for (int k = i; k < countr; ++k)
						{
							f[j][k] = f[j][k] - t * f[i][k];
						}
					}
				}
			}
		}
		long long lc = 1;
		for (int i = 0; i < counte; ++i)
		{
			for (int j = 0; j < countr; ++j)
			{
				lc = lcm(lc, f[i][j].b);
			}
		}
		long long rst[counte][countr];
		for (int i = 0; i < counte; ++i)
		{
			for (int j = 0; j < countr; ++j)
			{
				rst[i][j] = f[i][j].a * (lc / f[i][j].b);
			}
		}
		fra ans[countr];
		lc = 1;
		for (int i = 0; i < countr - 1; ++i)
		{
			ans[i].b = rst[i][i];
			ans[i].a = -rst[i][countr - 1]; 
			if (ans[i].b < 0)
			{
				ans[i].a = -ans[i].a;
				ans[i].b = -ans[i].b;
			}
			long long g = gcd(ans[i].a, ans[i].b);
			ans[i].a /= g;
			ans[i].b /= g;
			lc = lcm(lc, ans[i].b);
		}
		ans[countr - 1].a = 1;
		ans[countr - 1].b = 1;
		for (int i = 0; i < countr; ++i)
		{
			ans[i].a = ans[i].a * (lc / ans[i].b);
			if (i)
			{
				printf(" ");
			}
			printf("%lld", ans[i].a);
		}
		printf("\n");
	}
	return 0;
}
