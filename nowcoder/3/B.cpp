#include <cstdio>
#include <vector>

using namespace std;

class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        int sum = 0;
        sum = 0;
        for (int i = 0; i < n; ++i)
        	sum += left[i];
        int ans = sum + 1;
        for (int i = 1; i <= sum; ++i)
        {
        	int t = 0;
        	for (int j = 0; j < (1 << n); ++j)
        	{
        		int p = 0, q = 0;
        		for (int k = 0; k < n; ++k)
        			if (j >> k & 1)
        				p += left[k];
        			else
        				q += right[k];
        		if (p >= i)
        			t = max(t, q + 1);
        	}
        	ans = min(ans, i + t);
        }
        return ans;
    }
};

int main()
{
	Gloves g;
	printf("%d\n", g.findMinimum(3, {2,4,7}, {4,5,7}));
	return 0;
}
