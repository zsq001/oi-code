#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#define ll long long
using namespace std;
int cd[60],n,mp[60][60],vis[60][60],list[10010],s,t;
int transc(char ch)
{
    if(ch<='Z') return ch-'A'+1;
    else return ch-'a'+1+26;
}
char transi(int x)
{
    if(x<=26) return (char)(x+'A'-1);
    else return (char)(x+'a'-27);
}
void print()
{
    for(int i=1;i<=n+1;++i) printf("%c",transi(list[i]));
    exit(0);
}
void dfs(int x,int f)
{
    list[f]=x;
    if(f==n+1) print();
    for(int i=1;i<=mp[x][0];++i){
        int v=mp[x][i];
        if(vis[x][v]) continue;
        vis[x][v]=vis[v][x]=1;
        dfs(v,f+1);
        vis[x][v]=vis[v][x]=0;
    }
}
int main()
{
    char cx,cy;
    int x,y;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf(" %c %c",&cx,&cy);
        x=transc(cx),y=transc(cy);
        mp[x][++mp[x][0]]=y;
        mp[y][++mp[y][0]]=x;
    }
    for(int i=1;i<=52;++i) if(mp[i][0]) sort(mp[i]+1,mp[i]+mp[i][0]+1);
    for(int i=1;i<=52;++i){
        if(mp[i][0]&1){
            if(!s) s=i;
            else if(!t) t=i; 
            else{
                puts("No Solution");
                return 0;
            }
        }
    }
    if(!s) {
        for(int i=1;i<=52;++i) if(mp[i][0]) dfs(i,1);
    }
    else dfs(s,1);
    puts("No Solution");
    return 0;
}//a=97 A=65
