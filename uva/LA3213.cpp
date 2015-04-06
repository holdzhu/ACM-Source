#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	char sa[101];
	char sb[101];
	char a[26], b[26];
	while (scanf("%s %s", sa, sb) == 2)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 0; sa[i] != '\0'; ++i)
		{
			a[sa[i] - 'A']++;
			b[sb[i] - 'A']++;
		}
		sort(a, a + 26);
		sort(b, b + 26);
		bool B = true;
		for (int i = 0; i < 26; ++i)
		{
			if (a[i] != b[i])
			{
				B = false;
				break;
			}
		}
		printf("%s\n", B ? "YES" : "NO");
	}
	return 0;
}
