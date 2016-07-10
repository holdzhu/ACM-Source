#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;
const int inv = (mod + 1) / 2;

long long pow_mod(long long a, long long k)
{
	long long s = 1;
	while (k)
	{
		if (k & 1)
			s = s * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return s;
}

long long dp[2001][2001];
long long inv2[2001];

class BearCircleGame
{
public:
	int winProbability(int n, int k)
	{
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= n; ++j)
				dp[i][j] = 0;
		inv2[0] = 1;
		for (int i = 1; i <= n; ++i)
			inv2[i] = inv2[i - 1] * inv % mod;
		dp[n][0] = 1;
		for (int i = n; i > 1; --i)
		{
			int g = __gcd(i, k);
			vector<int> v;
			for (int j = 0; j <= i / g; ++j)
				v.push_back((1ll * j * k) % i);
			for (int j = 0; j < g; ++j)
			{
				vector<long long> tmp(i / g + 1, 0);
				long long sum = 0;
				for (int k = 0; k < i / g; ++k)
				{
					sum = sum * inv % mod;
					sum += dp[i][(j + v[k]) % i];
					if (sum >= mod)
						sum -= mod;
					tmp[k] = sum;
				}
				for (int k = 0; k < i / g; ++k)
				{
					sum -= dp[i][(j + v[k]) % i] * inv2[i / g - 1] % mod;
					if (sum < 0)
						sum += mod;
					sum = sum * inv % mod;
					tmp[k] += sum;
					if (tmp[k] >= mod)
						tmp[k] -= mod;
				}
				long long ratio = 0;
				for (int k = 0; k < i / g; ++k)
					ratio = (ratio * inv + 1) % mod;
				ratio = pow_mod(ratio, mod - 2);
				for (int k = 0; k < i / g; ++k)
				{
					tmp[k] = tmp[k] * ratio % mod;
					int nxt = (j + v[k + 1] - 1 + i) % i;
					if (nxt != 0)
					{
						if (nxt == i - 1)
							nxt = 0;
						dp[i - 1][nxt] += tmp[k];
						if (dp[i - 1][nxt] >= mod)
							dp[i - 1][nxt] -= mod;
					}
				}
			}
		}
		return (dp[1][0] % mod + mod) % mod;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 333333336; verify_case(0, Arg2, winProbability(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; verify_case(1, Arg2, winProbability(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 142857144; verify_case(2, Arg2, winProbability(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 238095240; verify_case(3, Arg2, winProbability(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 142857144; verify_case(4, Arg2, winProbability(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 5; int Arg1 = 1000000000; int Arg2 = 142857144; verify_case(5, Arg2, winProbability(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 2000; int Arg1 = 123; int Arg2 = 429232785; verify_case(6, Arg2, winProbability(Arg0, Arg1)); }
	void test_case_7() { int Arg0 = 1987; int Arg1 = 987654321; int Arg2 = 623410299; verify_case(7, Arg2, winProbability(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	BearCircleGame ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
