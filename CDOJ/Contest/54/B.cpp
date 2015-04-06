#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int L, xb, xa, vb, va, k;
		scanf("%d %d %d %d %d %d", &L, &xb, &xa, &vb, &va, &k);
		if (xa == xb)
		{
			printf("%.5f\n", 0.0);
		}
		else if (va == 0 && vb == 0 && k == 0)
		{
			printf("Impossible\n");
		}
		else if (va != 0 && vb == 0 && k == 0)
		{
			printf("%.5f\n", (xb - xa + L) % L * 1.0 / va);
		}
		else if (vb == 0 && k > 0)
		{
			printf("Impossible\n");
		}
		else if (k >= L)
		{
			double t1 = (xa - xb + L) % L * 1.0 / vb;
			double t2 = (xb - xa + L) % L * 1.0 / vb;
			printf("%.5f\n", min(t1, t2));
		}
		else if (vb <= va && k > 0)
		{
			printf("Impossible\n");
		}
		else if (vb <= va && k == 0)
		{
			printf("%.5f\n", (xb - xa + L) % L * 1.0 / (vb + va));
		}
		else if (k < L && k * 2 >= L && (xb - xa + L) % L <= k && (xa - xb + L) % L <= k)
		{
			if ((xa - xb + L) % L < (xb - xa + L) % L)
			{
				printf("%.5f\n", ((xa - xb + L) % L - (L - k)) * 1.0 / vb + (L - k) * 1.0 / (vb - va));
			}
			else
			{
				printf("%.5f\n", ((xb - xa + L) % L - (L - k)) * 1.0 / vb + (L - k) * 1.0 / (vb - va));
			}
		}
		else
		{
			int dis = (xb - xa + L) % L;
			if (dis <= k)
			{
				swap(xa, xb);
			}
			double t1 = (xa - xb + L) % L * 1.0 / (vb - va);
			double t2 = ((xb - xa + L) % L - k) * 1.0 / (vb + va) + k * 1.0 / (vb - va);
			printf("%.5f\n", min(t1, t2));
		}
	}
	return 0;
}