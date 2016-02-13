#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class GoodPath {
private:
	int solve(int n, const vector<vector<int> >& G, const vector<vector<int> >& W, int s, int t, int mi)
	{
		vector<int> dis(n, -1);
		dis[s] = 0;
		priority_queue<pair<int, int> > pq;
		pq.push(make_pair(0, s));
		while (!pq.empty())
		{
			int u = pq.top().second;
			int w = pq.top().first;
			pq.pop();
            if (u == t) break;
			if (-w != dis[u])
			{
				continue;
			}
			for (int i = 0; i < G[u].size(); ++i)
			{
				int v = G[u][i];
				if (W[u][i] >= mi && (dis[v] == -1 || dis[v] > max(-w, W[u][i])))
				{
					dis[v] = max(-w, W[u][i]);
					pq.push(make_pair(-dis[v], v));
				}
			}
		}
		return dis[t];
	}
public:
    vector<int> getMin(int n, vector<int> A, vector<int> B, vector<int> C, int m, int s, int t) {
        vector<vector<int> > G;
        vector<vector<int> > W;
        s--;
        t--;
        G.resize(n);
        W.resize(n);
        for (int i = 0; i < m; ++i)
        {
        	A[i]--;
        	B[i]--;
        	G[A[i]].push_back(B[i]);
        	G[B[i]].push_back(A[i]);
        	W[A[i]].push_back(C[i]);
        	W[B[i]].push_back(C[i]);
        }
        bool flag = false;
        vector<int> ans(2, -1);
        for (int i = 0; i < m; ++i)
        {
    		int s1 = solve(n, G, W, s, A[i], C[i]);
    		int s2 = solve(n, G, W, t, B[i], C[i]);
    		if (s1 != -1 && s2 != -1)
    		{
    			if (!flag)
    			{
    				flag = true;
    				ans[0] = max(s1, s2);
    				ans[1] = C[i];
    			}
    			else if (1ll * ans[0] * C[i] > 1ll * max(s1, s2) * ans[1])
    			{
    				ans[0] = max(s1, s2);
    				ans[1] = C[i];
    			}
    		}
        }
        if (!flag)
        {
        	return ans;
        }
        int g = __gcd(ans[0], ans[1]);
        ans[0] /= g;
        ans[1] /= g;
        return ans;
    }
};

int main()
{
	GoodPath gp;
	vector<int> ans = gp.getMin(3,{1,1,2},{2,2,3},{10,5,8},3,1,3);
	printf("%d %d\n", ans[0], ans[1]);
	return 0;
}
