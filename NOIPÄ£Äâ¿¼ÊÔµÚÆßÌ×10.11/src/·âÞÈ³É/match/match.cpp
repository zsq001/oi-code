#include <cstdio>
int N,M,X,Y,L=1,R=1;
int ylw[100010],ble[100010];
long long ans;
int main(){
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%d%d%d%d",&N,&M,&X,&Y);
    for(int i=1;i<=N;++i) scanf("%d",&ylw[i]);
    for(int i=1;i<=M;++i) scanf("%d",&ble[i]);
    while(L<=N&&R<=N){
        if(ble[R]>ylw[N]+Y||ble[M]<ylw[1]-X) break;
        if(ble[R]>=ylw[L]-X&&ble[R]<=ylw[L]+Y) {++ans;++L;++R;continue;}
        if(ble[R]<ylw[L]-X) {++R;continue;}
        if(ble[R]>ylw[L]+Y) {++L;continue;}
        ++L; ++R;
    }
    printf("%I64d",ans);
    return 0;
}
