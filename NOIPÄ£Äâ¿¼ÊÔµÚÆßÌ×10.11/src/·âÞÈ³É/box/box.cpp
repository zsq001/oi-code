#include <cstdio>
#include <cmath>
using namespace std;
long long N,minn=1e9; 
int main(){
    freopen("box.in","r",stdin);
    freopen("box.out","w",stdout);
    scanf("%lld",&N);
    for(int i=1;i<=sqrt(N);++i)
        for(int j=i;j<=sqrt(N/i);++j)
            if(!(N%i)&&!(N%j)&&!(N%(N/i/j))){
                long long t=2*(i*j+i*(N/i/j)+j*(N/i/j));
                if(t<minn) minn=t;
            }
    printf("%lld",minn);
    return 0;
}
