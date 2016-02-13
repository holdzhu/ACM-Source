#include <cstdio>

int n, w, h;
int x[101], y[101];
double sum[101][101];

bool inside(int w, int h, int k)
{
	return x[k] <= w && y[k] <= h;
}

int main()
{
	scanf("%d %d %d", &n, &w, &h);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", x + i, y + i);
	x[n] = x[0], y[n] = y[0];
	for (int i = 1; i <= w; ++i)
		for (int j = 1; j <= h; ++j)
			for (int k = 0; k < n; ++k)
			{
				double tx = -1.0 * (x[k + 1] * y[k] - x[k] * y[k + 1] - j * (x[k + 1] - x[k])) / (y[k + 1] - y[k]);
				double ty = 1.0 * (x[k + 1] * y[k] - x[k] * y[k + 1] + i * (y[k + 1] - y[k])) / (x[k + 1] - x[k]);
				int D = (x[k + 1] * y[k] - x[k] * y[k + 1]) - (j * (x[k + 1] - x[k]) - i * (y[k + 1] - y[k]));
				if (inside(i, j, k) && !inside(i, j, k + 1))
				{
					double ix, iy;
					if (D <= 0 && x[k] != x[k + 1])
						ix = i, iy = ty;
					else
						ix = tx, iy = j;
					sum[i][j] += i * iy - ix * j + ix * y[k] - x[k] * iy;
				}
				else if (!inside(i, j, k) && inside(i, j, k + 1))
				{
					double ix, iy;
					if (D >= 0 && x[k] != x[k + 1])
						ix = i, iy = ty;
					else
						ix = tx, iy = j;
					sum[i][j] += ix * j - i * iy + x[k + 1] * iy - ix * y[k + 1];
				}
				else if (inside(i, j, k) && inside(i, j, k + 1))
					sum[i][j] += x[k + 1] * y[k] - x[k] * y[k + 1];
				else if (y[k + 1] != y[k] && x[k + 1] != x[k] && tx <= i && ty <= j)
				{
					if (x[k] >= i && y[k + 1] >= j)
						sum[i][j] += (tx - i) * (ty - j);
					else if (x[k + 1] >= i && y[k] >= j)
						sum[i][j] -= (tx - i) * (ty - j);
				}
			}
	for (int j = h; j > 0; puts(""), --j)
		for (int i = 1; i <= w; ++i)
		{
			double area = sum[i][j] - sum[i - 1][j] - sum[i][j - 1] + sum[i - 1][j - 1];
			putchar(area < 0.5 - 1e-10 ? '.' : area < 1 - 1e-10 ? '+' : area < 1.5 - 1e-10 ? 'o' : area < 2 - 1e-10 ? '$' : '#');
		}
	return 0;
}