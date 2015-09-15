#include <cstdio>
#define m(x,y) (x>y?x:y)
int d[4][2101][2101],i,j,k;char s[2102]={1},t[2102]={2};int main(){scanf("%s%s",s+1,t+1);for(;s[i];++i)for(j=0;t[j];++j){d[0][i][j]=i*j?m(d[0][i][j-1],d[0][i-1][j]):0;for(k=0;k<3;++k)d[k+1][i][j]=i*j&&s[i]==t[j]?m(d[k+1][i-1][j-1],d[k][i-1][j-1])+1:-1e9;d[0][i][j]=m(d[0][i][j],d[3][i][j]);}return !printf("%d\n",d[0][i-1][j-1]);}