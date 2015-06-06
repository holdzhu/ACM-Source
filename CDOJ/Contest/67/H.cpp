#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

int n;
const int sigmasize = 62;
const int sigmasize2 = sigmasize * sigmasize;
int G[sigmasize2][sigmasize2];
int in[sigmasize2];
int out[sigmasize2];
int stk[200000];
int cur = 0;

char s[4];

inline int idx(char c)
{
	if (islower(c))
	{
		return c - 'a';
	}
	if (isupper(c))
	{
		return c - 'A' + 26;
	}
	return c - '0' + 52;
}

inline char deidx(int x)
{
	if (x < 26)
	{
		return x + 'a';
	}
	if (x < 52)
	{
		return x - 26 + 'A';
	}
	return x - 52 + '0';
}

void euler(int u)
{
	for (int i = 0; i < sigmasize2; ++i)
	{
		if (G[u][i])
		{
			G[u][i]--;
			euler(i);
			stk[cur++] = i;
		}
	}
}

int main()
{
	scanf("%d", &n);
	memset(in, 0, sizeof in);
	memset(out, 0, sizeof out);
	memset(G, 0, sizeof G);
	int start;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s);
		int u = idx(s[0]) * sigmasize + idx(s[1]);
		int v = idx(s[1]) * sigmasize + idx(s[2]);
		G[u][v]++;
		start = v;
		out[u]++;
		in[v]++;
	}
	int startnum = 0;
	int endnum = 0;
	bool flag = true;
	for (int i = 0; i < sigmasize2; ++i)
	{
		if (in[i] != out[i])
		{
			if (in[i] == out[i] - 1)
			{
				start = i;
				startnum++;
			}
			else if (in[i] - 1 == out[i])
			{
				endnum++;
			}
			else
			{
				flag = false;
			}
		}
	}
	if (flag && ((startnum == 0 && endnum == 0) || (startnum == 1 && endnum == 1)))
	{
		euler(start);
		if (cur != n)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n%c%c", deidx(start / sigmasize), deidx(start % sigmasize));
			while (cur--)
			{
				printf("%c", deidx(stk[cur] % sigmasize));
			}
			printf("\n");
		}
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}
