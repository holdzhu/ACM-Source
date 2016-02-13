#line 7 "ANewHope.cpp"
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


class ANewHope
{
	public:
	int count(vector <int> firstWeek, vector <int> lastWeek, int D)
	{
		int mx = 0;
		int n = firstWeek.size();
		vector<int> p1(n);
		vector<int> p2(n);
		for (int i = 0; i < n; ++i)
		{
			p1[firstWeek[i] - 1] = i;
			p2[lastWeek[i] - 1] = i;
		}
		for (int i = 0; i < n; ++i)
		{
			mx = max(mx, (p1[i] - p2[i] + n - D - 1) / (n - D) + 1);
		}
		return mx;
	}
	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
