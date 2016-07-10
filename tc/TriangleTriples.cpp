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

long long inv2;
long long inv6;

class TriangleTriples
{
	long long getSum1(long long a)
	{
		a %= mod;
		return a * (a + 1) % mod * inv2 % mod;
	}
	long long getSum2(long long a)
	{
		a %= mod;
		return a * (a + 1) % mod * ((2 * a + 1) % mod) % mod * inv6 % mod;
	}
	long long solve(long long A, long long B, long long C)
	{
		if (C == 1)
			return 0;
		if (A > B)
			swap(A, B);
		if (C <= A + 1)
		{
			long long ret = C * getSum1(C - 1) % mod;
			long long del = getSum2(C - 1);
			ret = (ret + mod - del) % mod;
			return ret;
		}
		else if (C <= B + 1)
		{
			long long ret = C * getSum1(A - 1) % mod;
			long long del = getSum2(A - 1);
			ret = (ret + mod - del) % mod;
			long long ret2 = C * A % mod * (C - A) % mod;
			long long del2 = A * (A + C - 1) % mod * (C - A) % mod * inv2 % mod;
			ret2 = (ret2 + mod - del2) % mod;
			return (ret + ret2) % mod;
		}
		else if (C <= A + B)
		{
			long long ret = C * getSum1(A - 1) % mod;
			long long del = getSum2(A - 1);
			ret = (ret + mod - del) % mod;
			long long ret2 = C * A % mod * (B - A) % mod;
			long long del2 = A * (A + B - 1) % mod * (B - A) % mod * inv2 % mod;
			ret2 = (ret2 + mod - del2) % mod;
			long long ret3 = (getSum2(A) + mod - getSum2(A + B - C)) % mod;
			long long del3 = (A + B - C) % mod * (A + A + B - C + 1) % mod * (C - B) % mod * inv2 % mod;
			ret3 = (ret3 + mod - del3) % mod;
			return (ret + ret2 + ret3) % mod;
		}
		else
		{
			long long ret = C * getSum1(A - 1) % mod;
			long long del = getSum2(A - 1);
			ret = (ret + mod - del) % mod;
			long long ret2 = C * A % mod * (B - A) % mod;
			long long del2 = A * (A + B - 1) % mod * (B - A) % mod * inv2 % mod;
			ret2 = (ret2 + mod - del2) % mod;
			long long ret3 = getSum2(A);
			long long del3 = (A + B + mod - C) % mod * getSum1(A) % mod;
			ret3 = (ret3 + mod - del3) % mod;
			return (ret + ret2 + ret3) % mod;
		}
	}
public:
	int count(int A, int B, int C)
	{
		inv2 = pow_mod(2, mod - 2);
		inv6 = pow_mod(6, mod - 2);
		long long all = 1ll * A * B % mod * C % mod;
		all = (all + mod - solve(A, B, C)) % mod;
		all = (all + mod - solve(A, C, B)) % mod;
		all = (all + mod - solve(B, C, A)) % mod;
		all = (all + mod) % mod;
		return all;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 20; int Arg3 = 10; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1000000000; int Arg3 = 6; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 10; int Arg3 = 505; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 123456789; int Arg1 = 987654321; int Arg2 = 555555555; int Arg3 = 64296241; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	TriangleTriples ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
