#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int level = 3;
const int levelsquare = level * level;
const char sigmastart = '1';
const int maxn = levelsquare * levelsquare * 4 + 2;
const int maxr = levelsquare * levelsquare * levelsquare + 2;
const int maxnode = maxn * maxr;
const int SLOT = 0;
const int ROW = 1;
const int COL = 2;
const int SUB = 3;

struct DLX
{
	int n, sz;
	int S[maxn];
	int row[maxnode], col[maxnode];
	int L[maxnode], R[maxnode], U[maxnode], D[maxnode];
	int ansd, ans[maxr];

	void init(int n)
	{
		this->n = n;
		for (int i = 0; i <= n; ++i)
		{
			U[i] = i;
			D[i] = i;
			L[i] = i - 1;
			R[i] = i + 1;
		}
		R[n] = 0;
		L[0] = n;
		sz = n + 1;
		memset(S, 0, sizeof(S));
	}

	void addRow(int r, vector<int> columns)
	{
		int first = sz;
		for (int i = 0; i < columns.size(); ++i)
		{
			int c = columns[i];
			L[sz] = sz - 1;
			R[sz] = sz + 1;
			D[sz] = c;
			U[sz] = U[c];
			D[U[c]] = sz;
			U[c] = sz;
			row[sz] = r;
			col[sz] = c;
			S[c]++;
			sz++;
		}
		R[sz - 1] = first;
		L[first] = sz - 1;
	}

	void remove(int c)
	{
		L[R[c]] = L[c];
		R[L[c]] = R[c];
		for (int i = D[c]; i != c; i = D[i])
		{
			for (int j = R[i]; j != i; j = R[j])
			{
				U[D[j]] = U[j];
				D[U[j]] = D[j];
				--S[col[j]];
			}
		}
	}

	void restore(int c)
	{
		for (int i = U[c]; i != c; i = U[i])
		{
			for (int j = L[i]; j != i; j = L[j])
			{
				++S[col[j]];
				U[D[j]] = j;
				D[U[j]] = j;
			}
		}
		L[R[c]] = c;
		R[L[c]] = c;
	}

	bool dfs(int d)
	{
		if (R[0] == 0)
		{
			ansd = d;
			return true;
		}
		int c = R[0];
		for (int i = R[0]; i != 0; i = R[i])
		{
			if (S[i] < S[c])
			{
				c = i;
			}
		}
		remove(c);
		for (int i = D[c]; i != c; i = D[i])
		{
			ans[d] = row[i];
			for (int j = R[i]; j != i; j = R[j])
			{
				remove(col[j]);
			}
			if (dfs(d + 1))
			{
				return true;
			}
			for (int j = L[i]; j != i; j = L[j])
			{
				restore(col[j]);
			}
		}
		restore(c);
		return false;
	}

	bool solve(vector<int>& v)
	{
		v.clear();
		if (!dfs(0))
		{
			return false;
		}
		for (int i = 0; i < ansd; ++i)
		{
			v.push_back(ans[i]);
		}
		return true;
	}
};

DLX solver;

int encode(int a, int b, int c)
{
	return a * levelsquare * levelsquare + b * levelsquare + c + 1;
}

void decode(int code, int& a, int& b, int& c)
{
	code--;
	c = code % levelsquare;
	code /= levelsquare;
	b = code % levelsquare;
	code /= levelsquare;
	a = code;
}

char puzzle[levelsquare][levelsquare + 1];

bool read()
{
	for (int i = 0; i < levelsquare; ++i)
	{
		if (scanf("%s", puzzle[i]) != 1)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int kase = 0;
	while (read())
	{
		if (++kase != 1)
		{
			printf("\n");
		}
		solver.init(levelsquare * levelsquare * 4);
		for (int r = 0; r < levelsquare; ++r)
		{
			for (int c = 0; c < levelsquare; ++c)
			{
				for (int v = 0; v < levelsquare; ++v)
				{
					if (puzzle[r][c] < sigmastart || puzzle[r][c] >= sigmastart + levelsquare || puzzle[r][c] == sigmastart + v)
					{
						vector<int> columns;
						columns.push_back(encode(SLOT, r, c));
						columns.push_back(encode(ROW, r, v));
						columns.push_back(encode(COL, c, v));
						columns.push_back(encode(SUB, (r / level) * level + c / level, v));
						solver.addRow(encode(r, c, v), columns);
					}
				}
			}
		}
		vector<int> ans;
		solver.solve(ans);
		for (int i = 0; i < ans.size(); ++i)
		{
			int r, c, v;
			decode(ans[i], r, c, v);
			puzzle[r][c] = sigmastart + v;
		}
		for (int i = 0; i < levelsquare; ++i)
		{
			printf("%s\n", puzzle[i]);
		}
	}
	return 0;
}
