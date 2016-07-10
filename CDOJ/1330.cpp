#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 300;
const double eps = 1e-10;
int nxt[maxn];
double mat[maxn][maxn + 1];

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
		nxt[i] = i;
	while (M--)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		nxt[u - 1] = v - 1;
	}
	for (int i = 0; i < N - 1; ++i)
	{
		mat[i][i]++;
		mat[i][N]++;
		for (int j = 1; j <= 6; ++j)
			if (i + j < N)
				mat[i][nxt[i + j]] -= 1 / 6.;
			else
				mat[i][i] -= 1 / 6.;
	}
	mat[N - 1][N - 1] = 1;
	for (int i = 0; i < N; ++i)
	{
		int r = -1;
		for (int j = i; j < N; ++j)
			if (fabs(mat[j][i]) > eps)
				r = j;
		if (r == -1)
			break;
		if (r != i)
			for (int j = i; j <= N; ++j)
				swap(mat[i][j], mat[r][j]);
		for (int j = 0; j < N; ++j)
			if (i != j)
				for (int k = N; k >= i; --k)
					mat[j][k] -= mat[i][k] / mat[i][i] * mat[j][i];
	}
	bool flag = true;
	for (int i = 1; i < N; ++i)
		if (fabs(mat[0][i]) > eps)
			flag = false;
	if (flag)
		printf("%.10f\n", mat[0][N] / mat[0][0]);
	else
		puts("-1");
	return 0;
}
