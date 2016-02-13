#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Median {
public:
    vector<int> getMaxMedian(vector<int> A, int n, int Q, vector<int> l, vector<int> r, vector<int> k) {
    	vector<int> ans;
        for (int q = 0; q < Q; ++q)
        {
        	int L = l[q];
        	int R = r[q];
        	int K = k[q];
        	vector<int> v;
        	for (int i = L; i <= R; ++i)
        	{
        		v.push_back(A[i]);
        	}
        	sort(v.begin(), v.end(), greater<int>());
        	ans.push_back(v[K / 2]);
        }
        return ans;
    }
};

int main()
{
	Median m;
	vector<int> ans = m.getMaxMedian({1,2,3,4,5},5,3,{0,1,2},{1,2,3},{1,2,2});
	for (int i = 0; i < ans.size(); ++i)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}
