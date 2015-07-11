#include <cstdio>

int dfs(int x)
{
  return x == 0 ? 1 : x * dfs(x - 1);
}

int main()
{
  printf("hello,world\n");
  printf("%d\n", dfs(10));
  return 0;
}
