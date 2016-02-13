#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int W, H;
int a[11], b[11];
bool used[11];
int x1[11], x2[11], y1[11], y2[11];

int leftmost(int n)
{
	int L = 0, R = W - 1;
	while (L < R)
	{
		int M = (L + R) >> 1;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			if (x1[i] <= M && x2[i] > M)
				cnt += y2[i] - y1[i];
		if (cnt < H)
			R = M;
		else
			L = M + 1;
	}
	return L;
}

pair<int, int> tmp[15];
int topmost(int n, int l)
{
	int m = 1;
	for (int i = 0; i < n; ++i)
		if (x1[i] <= l && x2[i] > l)
			tmp[m++] = {y1[i], y2[i]};
	sort(tmp + 1, tmp + m);
	tmp[0] = {0, 0};
	tmp[m] = {H, H};
	for (int i = 0; i < m; ++i)
		if (tmp[i].second < tmp[i + 1].first)
			return tmp[i].second;
	return -1;
}

bool isValid(int x, int y)
{
	return x >= 0 && y >= 0 && x <= W && y <= H;
}

bool check(int n)
{
	if (!isValid(x1[n], y1[n]) || !isValid(x2[n], y2[n]))
		return false;
	for (int i = 0; i < n; ++i)
		if (y1[i] > y1[n] && y1[i] < y2[n] && x2[i] > x1[n])
			return false;
	return true;
}

bool solve(int i)
{
	if (i == N)
		return true;
	int l = leftmost(i);
	int t = topmost(i, l);
	x1[i] = l;
	y1[i] = t;
	for (int j = 0; j < N; ++j)
	{
		if (!used[j])
		{
			used[j] = true;
			x2[i] = l + a[j];
			y2[i] = t + b[j];
			if (check(i) && solve(i + 1))
				return true;
			x2[i] = l + b[j];
			y2[i] = t + a[j];
			if (check(i) && solve(i + 1))
				return true;
			used[j] = false;
		}
	}
	return false;
}

int main()
{
	scanf("%d", &N);
	scanf("%d %d", &W, &H);
	for (int i = 0; i < N; ++i)
		scanf("%d %d", &a[i], &b[i]);
	solve(0);
	for (int i = 0; i < N; ++i)
		printf("%d %d %d %d\n", x1[i], y1[i], x2[i], y2[i]);
	return 0;
}
