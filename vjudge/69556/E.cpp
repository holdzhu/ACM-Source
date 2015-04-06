#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	FILE *fin, *fout;
	fin = fopen("nice.in", "rb");
	fout = fopen("nice.out", "wb");
	int n, k;
	fscanf(fin, "%d %d", &n, &k);
	int c[n + 1];
	memset(c, 0, sizeof(c));
	int l;
	for (l = 0; l < n; ++l)
	{
		int t;
		fscanf(fin, "%d", &t);
		c[t]++;
		if (c[t] - *min_element(c, c + t) > k)
		{
			break;
		}
	}
	fprintf(fout, "%d\n", l);
	fclose(fin);
	fclose(fout);
	return 0;
}
