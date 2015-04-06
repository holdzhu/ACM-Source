#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int dir[4][2]={0,1,-1,0,0,-1,1,0}; //四个方向
int startx,starty,n,m;
bool flag[60][60]; //标记传送门是否已走过
char str[60][60];

//传送门的坐标
struct protal
{
    int x1,y1,x2,y2;
}pro[35];

struct cur
{
    int x,y;
    int step;
};

bool BFS()
{
    cur p;
    queue<cur> Q;
    p.x = startx;
    p.y = starty;
    p.step = 0;
    Q.push(p);
    memset(flag,0,sizeof(flag));
    flag[p.x][p.y] = 1;
    while(!Q.empty())
    {
        cur q = Q.front();
        //cout<<q.x <<" "<<q.y<<" "<<q.step<<endl;
        Q.pop();
        if(str[q.x][q.y]=='Q')
        {
            printf("%d\n",q.step);
            return false;
        }
        for(int i=0;i<4;i++)
        {
            int dx = q.x + dir[i][0];
            int dy = q.y + dir[i][1];
            if(dx>=0&&dx<n&&dy>=0&&dy<m && str[dx][dy]!='#' && !flag[dx][dy])
            {
                if(islower(str[dx][dy]))
                {
                    if(pro[str[dx][dy]-'a'].x1 == dx && pro[str[dx][dy]-'a'].y1 == dy)
                    {
                        p.x = pro[str[dx][dy]-'a'].x2;
                        p.y = pro[str[dx][dy]-'a'].y2;
                    }
                    else
                    {
                        p.x = pro[str[dx][dy]-'a'].x1;
                        p.y = pro[str[dx][dy]-'a'].y1;
                    }
                    p.step = q.step + 1;
                    Q.push(p);
                }
                else
                {
                    p.x = dx;
                    p.y = dy;
                    p.step = q.step + 1;
                    Q.push(p);
                }
                flag[dx][dy] = 1;
            }
        }
    }
    return true;
}

int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        for(i=0;i<26;i++)
        pro[i].x1 = -1;
        scanf("%d%d",&n,&m);

        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            cin>>str[i][j];
            if(str[i][j]=='L')//记录开始位置
            {
                startx = i;
                starty = j;
            }else if(islower(str[i][j]))//str[i][j]是小写字母
            {
                if(pro[str[i][j]-'a'].x1==-1)
                {
                    pro[str[i][j]-'a'].x1 = i;
                    pro[str[i][j]-'a'].y1 = j;
                }else
                {
                    pro[str[i][j]-'a'].x2 = i;
                    pro[str[i][j]-'a'].y2 = j;
                }
            }
        }
        if(BFS())
        puts("-1");
    }
    return 0;
}