#include<bits/stdc++.h>
using namespace std;

char str[105][100100],str1[105][100100],num1[105][100010];
int ans[10010],bns[10010],bbns[100010],gans[100010];
int Ans,T,Q;
bool wron,FFFFFFFFF;

inline void cc(int x,int len){
	if(x==1) return ;
	int res=0;bool fla=0;
	for(int i=1;i<=len;i++){
		if(num1[x][i]!=num1[x-1][i]&&!fla) fla=1,res=abs((num1[x][i]-'0')-(num1[x-1][i]-'0'));
		else if(num1[x][i]!=num1[x-1][i]&&fla) {wron=1;return;}
	}
	bbns[++bbns[0]]=res;;
	Ans+=res;
}

inline bool checkpri(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return false;
	return true;
}

int main(int argc,char *argv[])
{
    freopen(argv[1],"r",stdin);
    freopen(argv[5],"w",stdout);
    int T,Q;
    scanf("%d%d",&T,&Q);
	freopen(argv[3],"r",stdin);
	for(int i=1;i<=T;i++){
		scanf("%d",&ans[i]);
		if(Q==1) scanf(" %s",str[i]+1);
	}
	freopen(argv[2],"r",stdin);
	for(int i=1;i<=T;i++){
		scanf("%d",&bns[i]);
		if(Q==1) scanf(" %s",str1[i]+1),str1[i][strlen(str1[i]+1)+1]='-';
	}
	if(!Q){
		bool flaa=0;
		for(int i=1;i<=T;i++)
			if(ans[i]!=bns[i]){puts("0");flaa=1;break;}
		if(!flaa) puts("10");
		freopen(argv[6],"w",stdout);
		if(!flaa) puts("right-ans");
		else puts("qaq?????");
	}
	else{
		bool fla=0,flg=0;
		for(int i=1;i<=T;i++)
			if(ans[i]!=bns[i]){puts("0");fla=1;break;}
		if(!fla){
			flg=0;
			for(int i=1;i<=T;i++){
				int tot=0,num=1;int x=0;
				Ans=0;memset(num1,0,sizeof(num1));
				int len=strlen(str1[i]+1);
				for(int j=1;j<=len;j++){
					if(str1[i][j]=='-'){
						if(!checkpri(x)) {flg=1;break;}
						cc(num,tot),tot=0,num++,x=0;
						if(wron){flg=1;break;}
					}
					else num1[num][++tot]=str1[i][j],x=x*10+str1[i][j]-'0';
				}
				gans[++gans[0]]=Ans;
				if(Ans!=ans[i]) flg=1;
				if(flg) break;
			}
			if(flg) puts("0");
			else puts("10");
		}
		freopen(argv[6],"w",stdout);
		if(!fla&&!flg) puts("right-ans");
		else{
			printf("your chengxu cal's ans = %d\n",Ans);
			for(int i=1;i<=gans[0];i++)
				printf("every step :%d\n",gans[i]);
		}
	}
}
