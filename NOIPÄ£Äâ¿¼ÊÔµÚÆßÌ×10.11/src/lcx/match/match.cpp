#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,x,y;
int ans;
int a,b[1010];
int cnt1,cnt2,cnt3=1;
int a1[1010],a2[1010];
int bins1(int k,int l,int r)
{
  int mid=(l+r)/2;
  if(l==r&&a1[l]<=k)return l;
  else if(l==r) return 0;
  if(a1[mid]==k)return mid;
  else if(a1[mid]<k)return bins1(k,mid+1,r);
  else  return bins1(k,l,mid);
}
int bins2(int k,int l,int r)
{
  int mid=(l+r)/2;
  if(l==r&&a2[l]>=k)return l;
  else if(l==r)return 0;
  if(a2[mid]==k)return mid;
  else if(a2[mid]>=k)return bins2(k,l,mid);
  else  return bins2(k,mid+1,r);
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%d %d %d %d",&n,&m,&x,&y);
    int i,j;
    for(i=1;i<=n;i++)
    { 
     scanf("%d",&a); 
     if(a!=a1[cnt1]+x||cnt1==0)
     a1[++cnt1]=a-x;
     if(a!=a2[cnt2]-y||cnt2==0)
     a2[++cnt2]=a+y;
    }
    for(i=1;i<=m;i++)
    {
     scanf("%d",&b[cnt3]);
     if(b[cnt3]==b[cnt3-1]&&i!=1)continue;
     int u=bins1(b[cnt3],1,cnt1);
     int v=bins2(b[cnt3],1,cnt2);
     if(u!=0&v!=0)ans+=u-v+1;
     cnt3++;
    }
    printf("%d",ans);
    return 0;
}
