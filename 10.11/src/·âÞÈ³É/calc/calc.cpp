#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char ch[2010];
bool pldr[2010][2010];
int lenn;
int bef[2010],aft[2010];
long long ans;
int main(){
    freopen("calc.in","r",stdin); freopen("calc.out","w",stdout);
    scanf("%s",ch+1); lenn=strlen(ch+1);
    for(int i=1;i<=lenn;++i) pldr[i][i]=true;
    for(int i=lenn;i>=1;--i)
        for(int j=i;j<=lenn;++j)
            if(j>i&&ch[i]==ch[j]){
                if(i==j) pldr[i][j]=true;
                else if(j-i+1==2)pldr[i][j]=true;
                else pldr[i][j]=pldr[i+1][j-1];
            }
    for(int i=1;i<=lenn;++i){
        bef[i]=bef[i-1];
        for(int j=1;j<=i;++j)
            if(pldr[j][i]) ++bef[i];
    }
    for(int i=1;i<lenn;++i)
        for(int j=i;j<=lenn;++j)
            if(pldr[i+1][j]) ++aft[i];
    for(int i=1;i<=lenn;++i) ans+=bef[i]*aft[i];
    printf("%I64d",ans);
    return 0;
}
