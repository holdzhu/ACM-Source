#include <cstdio>
#include <vector>

using namespace std;

struct Point
{
	double x, y;
	int u, v;
};

long long A[100000];
long long B[100000];
long long C[100000];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%I64d %I64d %I64d", &A[i], &B[i], &C[i]);
	}
	vector<Point> v;
	bool h = true;
	for (int i = 1; i < n; ++i)
	{
		bool flag = false;
		for (int j = 0; j < v.size(); ++j)
		{
			if (A[i] * v[j].x + B[i] * v[j].y + C[i] == 0)
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			int cnt = 0;
			for (int j = 0; j < n; ++j)
			{
				if (i == j)
				{
					continue;
				}
				if (A[i] * B[j] == A[j] * B[i])
				{
					cnt++;
				}
				else
				{
					v.push_back((Point){1.0 * (C[i] * B[j] - C[j] * B[i]) / (B[i] * A[j] - B[j] * A[i]),
										1.0 * (C[i] * A[j] - C[j] * A[i]) / (A[i] * B[j] - A[j] * B[i]),
										i + 1, j + 1});
					break;
				}
			}
			if (cnt > k)
			{
				h = false;
				break;
			}
		}
		if (v.size() > k)
		{
			break;
		}
	}
	if (h && v.size() <= k)
	{
		for (int i = 0; i < n; ++i)
		{
			bool l = false;
			for (int j = 0; j < v.size(); ++j)
			{
				if (A[i] * v[j].x + B[i] * v[j].y + C[i] == 0)
				{
					l = true;
					break;
				}
			}
			if (!l)
			{
				v.push_back((Point){1e23, 1e23, i + 1, -1});
			}
		}
		if (v.size() > k)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
			printf("%d\n", v.size());
			for (int i = 0; i < v.size(); ++i)
			{
				printf("%d %d\n", v[i].u, v[i].v);
			}
		}
	}
	else
	{
		puts("NO");
	}
	return 0;
}
