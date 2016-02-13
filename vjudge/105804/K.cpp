#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 10;
const int maxm = 3e5 + 10;

struct Event
{
	int x, type, id;
	bool operator<(const Event &rhs) const
	{
		return x < rhs.x;
	}
};

char tmp[maxn << 1];
void manacher(const char *s, int l, int *len)
{
	tmp[0] = '$';
	tmp[1] = '#';
	for (int i = 1; i <= l; ++i)
	{
		tmp[i << 1]		= s[i - 1];
		tmp[i << 1 | 1] = '#';
	}
	int mx = 0, po = 0;
	for (int i = 1; i < l * 2 + 2; ++i)
	{
		if (mx > i)
			len[i] = min(mx - i, len[2 * po - i]);
		else
			len[i] = 1;
		while (tmp[i - len[i]] == tmp[i + len[i]])
			len[i]++;
		if (len[i] + i > mx)
		{
			mx = len[i] + i;
			po = i;
		}
	}
}

int n;
long long tree1[maxn];
long long tree2[maxn];

void update(int l, int r)
{
	for (int i = l; i <= n; i += i & -i)
		tree1[i]++, tree2[i] += l;
	for (int i = r; i <= n; i += i & -i)
		tree1[i]--, tree2[i] -= r;
}

long long query(int x)
{
	long long ret1 = 0, ret2 = 0;
	for (int i = x; i; i -= i & -i)
		ret1 += tree1[i], ret2 += tree2[i];
	return ret1 * (x + 1) - ret2;
}

char s[maxn];
int len[maxn << 1];
int a[maxm], b[maxm];
Event event[maxm * 3];
long long ans[maxm];

int main()
{
	freopen("palindromes.in", "r", stdin);
	freopen("palindromes.out", "w", stdout);
	scanf("%s", s);
	n = strlen(s);
	manacher(s, n, len);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &a[i], &b[i]);
		event[i * 3]	 = {a[i] - 1, 0, i};
		event[i * 3 + 1] = {(b[i] + a[i] - 1) >> 1, 1, i};
		event[i * 3 + 2] = {b[i], 2, i};
	}
	sort(event, event + m * 3);
	long long sum = 0;
	for (int i = 0, j = 0; i <= n; ++i)
	{
		sum += len[i << 1] + len[i << 1 | 1] - 2;
		len[i << 1] /= 2;
		len[i << 1 | 1] /= 2;
		if (len[i << 1])
			update(i - len[i << 1] + 1, i + len[i << 1]);
		if (len[i << 1 | 1])
			update(i - len[i << 1 | 1] + 1, i + len[i << 1 | 1] + 1);
		while (j < m * 3 && event[j].x == i)
		{
			int k = event[j].id;
			switch (event[j].type)
			{
			case 0: ans[k] -= sum - 2 * query(a[k] - 1); break;
			case 1: ans[k] += 2 * (sum - query(a[k] - 1) - query(b[k])); break;
			case 2: ans[k] += 2 * query(b[k]) - sum; break;
			}
			j++;
		}
	}
	for (int i = 0; i < m; ++i)
		printf("%I64d\n", (ans[i] + b[i] - a[i] + 1) / 2);
	return 0;
}
