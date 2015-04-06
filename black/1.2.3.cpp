#include <cstdio>
#include <cstdlib>

const int q3[] = {1, 2, 4, 7, 6};

int main()
{
	int n[10];
	for (int i = 0; i < 9765625; ++i)
	{
		int t = i;
		int c[5] = {0, 0, 0, 0, 0};
		int firstb = -1;
		int countc = 0;
		int ci;
		for (int j = 0; j < 10; ++j)
		{
			n[j] = t % 5;
			t /= 5;
			c[n[j]]++;
			if (n[j] == 1 && firstb == -1)
			{
				firstb = j;
			}
			if (j && n[j] == n[j - 1])
			{
				countc++;
				ci = j;
			}
		}
		int cc = c[1] + c[2] + c[3];
		if (firstb != n[0] + 1 || 
			countc != 1 || 
			ci != n[1] + 2 || 
			n[2] != n[q3[n[2]] - 1] ||
			c[0] != n[3] ||
			n[4] != n[9 - n[4]] ||
			(n[5] != 4 && c[0] != c[n[5] + 1]) ||
			(n[5] == 4 && (c[0] == c[1] || c[0] == c[2] || c[0] == c[3] || c[0] == c[4])) ||
			abs(n[6] - n[7]) != 4 - n[6] ||
			c[0] + c[4] != n[7] + 2)
		{
			continue;
		}
		if (n[8] == 0 && cc != 2 && cc != 3 && cc != 5 && cc != 7)
		{
			continue;
		}
		if (n[8] == 1 && cc != 1 && cc != 2 && cc != 6)
		{
			continue;
		}
		if (n[8] == 2 && cc != 0 && cc != 1 && cc != 4 && cc != 9)
		{
			continue;
		}
		if (n[8] == 3 && cc != 0 && cc != 1 && cc != 8)
		{
			continue;
		}
		if (n[8] == 4 && cc != 0 && cc != 5 && cc != 10)
		{
			continue;
		}
		for (int i = 0; i < 10; ++i)
		{
			printf("%c ", n[i] + 'a');
		}
		printf("\n");
	}
	return 0;
}
