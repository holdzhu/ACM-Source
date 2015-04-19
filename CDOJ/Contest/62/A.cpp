#include <cstdio>
#include <cstring>

void manychar(int width, char c)
{
	for (int i = 0; i < width; ++i)
	{
		putchar(c);
	}
}

inline int idx(char c)
{
	return c - '0';
}

int main()
{
	char A[5], B[5];
	while (scanf("%s %s", A, B) == 2)
	{
		int la = strlen(A);
		int lb = strlen(B);
		int a;
		int b;
		sscanf(A, "%d", &a);
		sscanf(B, "%d", &b);
		int s = a * b;
		char ans[20];
		sprintf(ans, "%d", s);
		int ls = strlen(ans);
		ans[la + lb] = 0;
		for (int i = ls - 1; i >= 0; --i)
		{
			ans[i + la + lb - ls] = ans[i];
		}
		for (int i = 0; i < la + lb - ls; ++i)
		{
			ans[i] = ' ';
		}
		if (la == 1 && A[0] == '0')
		{
			break;
		}
		putchar('+');
		manychar(4 * la + 3, '-');
		printf("+\n");
		printf("|   ");
		for (int i = 0; i < la; ++i)
		{
			printf("%c   ", A[i]);
		}
		printf("|\n");
		printf("| ");
		for (int i = 0; i < la; ++i)
		{
			printf("+---");
		}
		printf("+ |\n");
		bool flag = false;
		for (int j = 0; j < lb; ++j)
		{
			if (j > 0 && flag)
			{
				printf("|/");
			}
			else
			{
				printf("| ");
			}
			for (int i = 0; i < la; ++i)
			{
				printf("|%d /", idx(A[i]) * idx(B[j]) / 10);
			}
			printf("| |\n");
			printf("| ");
			for (int i = 0; i < la; ++i)
			{
				printf("| / ");
			}
			printf("|%d|\n", idx(B[j]));
			printf("|%c", ans[j]);
			if (ans[j] != ' ')
			{
				flag = true;
			}
			for (int i = 0; i < la; ++i)
			{
				printf("|/ %d", idx(A[i]) * idx(B[j]) % 10);
			}
			printf("| |\n");
			printf("| ");
			for (int i = 0; i < la; ++i)
			{
				printf("+---");
			}
			printf("+ |\n");
		}
		printf("|");
		for (int i = 0; i < la; ++i)
		{
			if (flag)
			{
				printf("/");
			}
			else
			{
				printf(" ");
			}
			printf(" %c ", ans[lb + i]);
			if (ans[lb + i] != ' ')
			{
				flag = true;
			}
		}
		printf("   |\n");
		putchar('+');
		manychar(4 * la + 3, '-');
		printf("+\n");
	}
	return 0;
}
