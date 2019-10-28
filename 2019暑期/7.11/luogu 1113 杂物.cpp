#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,ans,id,len,pre,f[10010];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>id>>len;
        int tmp=0;
        while(1){
            cin>>pre;
            if(!pre) break;
            tmp=max(tmp,f[pre]);
        }
        ans=max(ans,(f[id]=tmp+len));
    }
    cout<<ans;
    return 0;
}
