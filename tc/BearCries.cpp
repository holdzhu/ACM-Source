#line 7 "BearCries.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int mod = 1e9 + 7;

long long dp[205][205][205];


class BearCries
{
	public:
	int count(string message)
	{
		int n = message.size();
		for (int i = 0; i <= n; ++i)
		{
			for (int j = 0; j <= n; ++j)
			{
				for (int k = 0; k <= n; ++k)
				{
					dp[i][j][k] = 0;
				}
			}
		}
		dp[0][0][0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j <= n; ++j)
			{
				for (int k = 0; k <= n; ++k)
				{
					if (message[i - 1] == '_')
					{
						if (j >= 1 && k + 1 <= n) dp[i][j - 1][k + 1] = (dp[i][j - 1][k + 1] + dp[i - 1][j][k] * j) % mod;
						dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k] * k) % mod;
					}
					else
					{
						if (j + 1 <= n) dp[i][j + 1][k] = (dp[i][j + 1][k] + dp[i - 1][j][k]) % mod;
						if (k >= 1) dp[i][j][k - 1] = (dp[i][j][k - 1] + dp[i - 1][j][k] * k) % mod;
					}
				}
			}
		}
		return dp[n][0][0];
	}
	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
