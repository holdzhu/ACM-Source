#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double pi = acos(-1);

int n, k;
const int N = 200001;
int Fx[N];
int Fy[N];
int Bx[N];
int By[N];
bool ans[N];
double deg[N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d", &Fx[i], &Fy[i]);
		}
		scanf("%d", &k);
		long long px = 0, py = 0;
		for (int i = 0; i < k; ++i)
		{
			scanf("%d %d", &Bx[i], &By[i]);
			px += Bx[i];
			py += By[i];
		}
		if (2 * k >= n)
		{
			printf("Yes\n%d\n", n);
			for (int i = 0; i < n; ++i)
			{
				printf("%d ", i + 1);
			}
			puts("");
			continue;
		}
		px /= k;
		py /= k;
		for (int i = 0; i < n; ++i)
		{
			deg[i] = atan2(Fy[i] - py, Fx[i] - px);
			if (deg[i] < deg[0])
			{
				deg[i] += pi * 2;
			}
			ans[i] = 0;
		}
		for (int i = 0; i < k; ++i)
		{
			double t = atan2(By[i] - py, Bx[i] - px);
			if (t < deg[0])
			{
				t += pi * 2;
			}
			int pos = lower_bound(deg, deg + n, t) - deg;
			ans[pos % n] = 1;
			ans[(pos + n - 1) % n] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			if (ans[i])
			{
				cnt++;
			}
		}
		printf("Yes\n%d\n", cnt);
		for (int i = 0; i < n; ++i)
		{
			if (ans[i])
			{
				printf("%d ", i + 1);
			}
		}
		puts("");
	}
	return 0;
}