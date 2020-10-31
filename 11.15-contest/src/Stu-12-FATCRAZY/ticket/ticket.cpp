#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
template<class T>void read(T &x)
{
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>='9'){f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
	return;
}
int l,c;
char str[27];
int bb[27];
int a[27],ti;
int st=0;
void dfs(int ans,int yy,int ff)
{
	int i,j;
    if(st>=25000)return;
    if(ans==l+1){
        if(yy>=1&&ff>=2){
            ++st;
            if(ti==1)printf("\n");
            else ti=1;
            for(int j=1;j<=l;j++)
			{
                printf("%c",str[a[j]]);
            }
        }
        return;
    }
    for(i=a[ans-1]+1; i<=c; i++)
	{
        if(bb[i]==0){
            bb[i]=1;
            a[ans]=i;
            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')dfs(ans+1,yy+1,ff);
            else dfs(ans+1,yy,ff+1);
            bb[i]=0;
        }
    }
}
int main()
{
	freopen("ticket.in","r",stdin);
	freopen("ticket.out","w",stdout);
    scanf("%d%d",&l,&c);
    getchar();
    char p;
    for(int i=1;i<=c;i++)
	 scanf("%c%c",&str[i],&p);
    sort(str+1,str+c+1);
    dfs(1,0,0);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
