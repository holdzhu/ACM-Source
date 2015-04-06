#include <cstdio>
#include <algorithm>

using namespace std;

const char s[10][9] = {"Dhaval", "Shivang", "Bhardwaj", "Rishab", "Maji", "Gaurav", "Dhruv", "Nikhil", "Rohan", "Ketan"};
const int o[10] = {9, 0, 8, 1, 7, 2, 6, 3, 5, 4};

int a[10];
int p[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
bool vis[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

inline bool cmp(const int& lhs, const int& rhs)
{
	return a[lhs] < a[rhs];
}

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &a[i]);
	}
	sort(p, p + 10, cmp);
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (!vis[j] && a[j] == a[p[o[i]]])
			{
				vis[j] = true;
				printf("%s\n", s[j]);
				break;
			}
		}
	}
	return 0;
}
