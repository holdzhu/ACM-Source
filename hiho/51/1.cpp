#include<cstdio>
int N,G[1<<15]={1};int d(int u){int i=2;while(i--)G[u*2+i]++?0:d(u/2|i<<N-2);putchar(u&1^48);}main(){d(!scanf("%d",&N));puts("");}