#include<stdio.h>
#include<string.h>
int row[]={-1,-1,-1,0,0,1,1,1};
int col[]={-1,0,1,-1,1,-1,0,1};

const int LEN=8;
char map[LEN+2][LEN+2];

char current;

bool enemy(int i,int j){
	//if(i<1||i>LEN||j<1||j>LEN)
		//return false;
	if(map[i][j]==(current=='W'?'B':'W'))
		return true;
	return false;
}

bool Friend(int i,int j,int p){
	do{
		i+=row[p];
		j+=col[p];
		//if(i<1||i>LEN||j<1||j>LEN)
			//return false;
	}while(enemy(i,j));
	if(map[i][j]==current)
		return true;
	else
		return false;
}

bool place(int i,int j){
	for(int p=0;p<8;p++)
		if(map[i][j]=='-')
			if(enemy(i+row[p],j+col[p])&&Friend(i,j,p))
				return true;
	return false;
}
void change(char &c){
	if(c=='B')c='W';
	else if(c=='W')c='B';
}

void Pmap(){
	for(int i=1;i<=LEN;i++){
		for(int j=1;j<=LEN;j++)
			printf("%c",map[i][j]);
		if(i!=LEN)printf("\n");
		}
}

int main(){
	//freopen("out","w",stdout);
	//freopen("in","r",stdin);
	memset(map,0,sizeof(map));//necessary?
	int Case;
	scanf("%d",&Case);
	while(Case--){
		getchar();
		for(int i=1;i<=LEN;i++)
			gets(map[i]+1);
		scanf(" %c",&current);
		char cmd;
		while(true){
			scanf(" %c",&cmd);
			if(cmd=='L'){
				int count=0;
				for(int i=1;i<=LEN;i++)
					for(int j=1;j<=LEN;j++)
						if(place(i,j)){
							if(++count!=1)printf(" ");
							printf("(%d,%d)",i,j);
						}
				if(count==0)
					printf("No legal move.");
				printf("\n");
			}
			else if(cmd=='M'){
				int i,j;
				scanf("%1d%1d",&i,&j);
				if(!place(i,j))change(current);
				map[i][j]=current;
				for(int p=0;p<8;p++){
					if(!enemy(i+row[p],j+col[p])||!Friend(i,j,p))
						continue;
					for(int ei=i+row[p],ej=j+col[p];map[ei][ej]!=current;){
						map[ei][ej]=current;
						ei+=row[p];
						ej+=col[p];
					}
				}
				int w=0,b=0;
				for(int i=1;i<=LEN;i++)
					for(int j=1;j<=LEN;j++)
						if(map[i][j]=='B')b++;
						else if(map[i][j]=='W')w++;
				printf("Black - %2d White - %2d\n",b,w);
				change(current);
			}
			else{
					Pmap();
					break;
				}
			}
		if(Case!=0)
			printf("\n\n");
	}
	return 0;
}