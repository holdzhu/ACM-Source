#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int p2[32];
int p3[32];
int p5[32];
int p7[32];

vector<unsigned int> s;

int main()
{
	long long t = 1;
	for (int i = 0; t <= 2000000000; ++i)
	{
		p2[i] = t;
		t *= 2;
	}
	t = 1;
	for (int i = 0; t <= 2000000000; ++i)
	{
		p3[i] = t;
		t *= 3;
	}
	t = 1;
	for (int i = 0; t <= 2000000000; ++i)
	{
		p5[i] = t;
		t *= 5;
	}
	t = 1;
	for (int i = 0; t <= 2000000000; ++i)
	{
		p7[i] = t;
		t *= 7;
	}
	for (int s1 = 0; s1 < 31; ++s1)
	{
		t = p2[s1];
		for (int s2 = 0; s2 < 20; ++s2)
		{
			t *= p3[s2];
			if (t <= 2000000000)
			{
				for (int s3 = 0; s3 < 14; ++s3)
				{
					t *= p5[s3];
					if (t <= 2000000000)
					{
						for (int s4 = 0; s4 < 12; ++s4)
						{
							t *= p7[s4];
							if (t <= 2000000000)
							{
								s.push_back(t);
							}
							else
							{
								t /= p7[s4];
								break;
							}
							t /= p7[s4];
						}
					}
					else
					{
						t /= p5[s3];
						break;
					}
					t /= p5[s3];
				}
			}
			else
			{
				t /= p3[s2];
				break;
			}
			t /= p3[s2];
		}
	}
	sort(s.begin(), s.end());
	int n;
	while (scanf("%d", &n) == 1 && n)
	{
		printf("The %d%s humble number is %d.\n", n, n % 100 == 11 || n % 100 == 12 || n % 100 == 13 ? "th" : (n % 10 == 1 ? "st" : (n % 10 == 2 ? "nd" : (n % 10 == 3 ? "rd" : "th"))), s[n - 1]);
	}
	return 0;
}
