#include <cstdio>
#include <cstring>

int n;
int s[10][12];
int l[10];
int num[26];
bool head[26];
bool numused[10];
int ans;
int verans;

void hordfs(int);

void verdfs(int h, int x)
{
	if (x == n - 1)
	{
		if (s[x][h] == -1)
		{
			if (verans % 10 == 0)
			{
				hordfs(h + 1);
			}
		}
		else if (num[s[x][h]] == -1)
		{
			if (!numused[verans % 10] && (verans % 10 > 0 || !head[s[x][h]]))
			{
				numused[verans % 10] = true;
				num[s[x][h]] = verans % 10;
				hordfs(h + 1);
				numused[verans % 10] = false;
				num[s[x][h]] = -1;
			}
		}
		else
		{
			if (verans % 10 == num[s[x][h]])
			{
				hordfs(h + 1);
			}
		}
	}
	else
	{
		if (s[x][h] == -1)
		{
			verdfs(h, x + 1);
		}
		else if (num[s[x][h]] == -1)
		{
			for (int i = head[s[x][h]]; i < 10; ++i)
			{
				if (!numused[i])
				{
					num[s[x][h]] = i;
					verans += num[s[x][h]];
					numused[i] = true;
					verdfs(h, x + 1);
					verans -= num[s[x][h]];
					num[s[x][h]] = -1;
					numused[i] = false;
				}
			}
		}
		else
		{
			verans += num[s[x][h]];
			verdfs(h, x + 1);
			verans -= num[s[x][h]];
		}
	}
}

void hordfs(int x)
{
	if (x < 12)
	{
		int lverans = verans;
		verans = verans / 10;
		verdfs(x, 0);
		verans = lverans;
	}
	else
	{
		if (verans == 0)
		{
			ans++;
		}
	}
}

int main()
{
	while (scanf("%d", &n) == 1)
	{
		scanf("%d", &n);
		memset(s, -1, sizeof s);
		memset(num, -1, sizeof num);
		memset(numused, 0, sizeof numused);
		memset(head, 0, sizeof head);
		for (int i = 0; i < n; ++i)
		{
			char t[11];
			scanf("%s", t);
			l[i] = strlen(t);
			head[t[0] - 'A'] = true;
			for (int j = 0; j < l[i]; ++j)
			{
				s[i][j] = t[l[i] - 1 - j] - 'A';
			}
		}
		ans = 0;
		verans = 0;
		hordfs(0);
		printf("%d\n", ans);
	}
	return 0;
}
