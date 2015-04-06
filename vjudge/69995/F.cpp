#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	FILE *fin, *fout;
	fin = fopen("knights.in", "rb");
	fout = fopen("knights.out", "wb");
	while(scanf("%d", &n) == 1 && n)
	{
		int maxx = 0;
		int maxy = 0;
		while (n--)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			if (x < 2 + y / 3 * 3)
			{
				maxx = max(maxx, (x + 1) / 3);
			}
			else
			{
				maxx = max(maxx, (x - y / 3 * 3) / 2 + y / 3);
			}
			if (y < (x + 1) / 3 * 3)
			{
				maxy = max(maxy, y / 3);
			}
			else
			{
				maxy = max(maxy, (y - (x + 1) / 3 * 3) / 2 + (x + 1) / 3);
			}
		}
		printf("%s wins the game\n", maxx > maxy ? "Andrew" : "Peter");
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
