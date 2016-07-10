#include <cstdio>
#include <map>

using namespace std;

double p[20];
int N, K;

map<int, double> mp;

void dfs(int cur, int cnt, int mask, int ca, double pa) {
  if (cur == N) {
    if (cnt != K) return;
    if (ca * 2 != cnt) return;
    mp[mask] += pa;
  }
  else {
    dfs(cur+1, cnt+1, mask|(1<<cur), ca+1, pa * p[cur]);
    dfs(cur+1, cnt+1, mask|(1<<cur), ca, pa * (1-p[cur]));
    dfs(cur+1, cnt, mask, ca, pa);
  }
}

void print_bit(int x) {
  for (int i = 0; i < N; i++) {
    if ((x>>i)&1) {
      putchar('1');
    }
    else putchar('0');
  }
}

double solve() {
  double ans = -1;
  mp.clear();
  dfs(0, 0, 0, 0, 1);
  int m = 0;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    // printf("%d  %.3f\n", it->first, it->second);
    // ans = max(ans, it->second);
    if (it->second > ans) {
      m = it->first;
      ans = it->second;
    }
  }
  // for (int i = 0; i < N; i++) printf("%.3f ", p[i]);
  // print_bit(m);
  // puts("");
  return ans;
}

int main() {
  int T;

  scanf("%d", &T);

  for (int kase = 1; kase <= T; kase++) {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%lf", &p[i]);
    printf("Case #%d: ", kase);
    printf("%.10f\n", solve());
  }


  return 0;
}
