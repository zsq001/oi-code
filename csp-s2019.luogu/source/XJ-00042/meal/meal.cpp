#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int s[50][505],n,m,ans1,ans2,ans;
int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	ios::sync_with_stdio(false);
     cin>>n>>m;
     for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
     cin>>s[i][j]; 
     if(n==2){
     	ans1=0,ans2=0;
       for(int i=1;i<=m-1;i++){
       	for(int j=i+1;j<=m;j++){
       		ans1+=s[1][i]*s[2][j];
       		ans2+=s[2][i]*s[1][j];
       	}
       }
       cout<<ans1+ans2;
   }
   else{
   if(m==2){
   	ans1=0;ans2=0;
   	for(int i=1;i<=n-1;i++){
   		for(int j=i+1;j<=n;j++){
   			ans1+=s[i][1]*s[j][2];
   			ans2+=s[i][2]*s[j][1];
   		}
   	}
   	ans=ans1+ans2;
   	cout<<ans;
   }
   else{
   	ans1=0;ans2=0,ans=0;
   		for(int i=1;i<=n-1;i++){
   		for(int j=i+1;j<=n;j++){
   			ans1+=s[i][1]*s[j][2];
   			ans2+=s[i][2]*s[j][1];
   		}
   	}
   	ans+=ans1+ans2;
   	ans1=0;ans2=0;
   		for(int i=1;i<=n-1;i++){
   		for(int j=i+1;j<=n;j++){
   			ans1+=s[i][2]*s[j][3];
   			ans2+=s[i][3]*s[j][2];
   		}
   	}
   	ans+=ans1+ans2;
   	ans1=0,ans2=0;
   		for(int i=1;i<=n-1;i++){
   		for(int j=i+1;j<=n;j++){
   			ans1+=s[i][1]*s[j][3];
   			ans2+=s[i][3]*s[j][1];
   		}
   	}
   	ans+=ans1+ans2,ans1=0,ans2=0;
    for(int i=1;i<=n-2;i++)
    for(int j=i+1;j<=n-1;j++)
    for(int p=i+2;p<=n;p++){
     	ans1+=s[i][1]*s[j][2]*s[p][3];
     }
     ans2+=ans1;
     ans1=0;
      for(int i=1;i<=n-2;i++)
    for(int j=i+1;j<=n-1;j++)
    for(int p=i+2;p<=n;p++){
     	ans1+=s[i][1]*s[j][3]*s[p][2];
     }
     ans2+=ans1;
     ans1=0;
      for(int i=1;i<=n-2;i++)
    for(int j=i+1;j<=n-1;j++)
    for(int p=i+2;p<=n;p++){
     	ans1+=s[i][2]*s[j][1]*s[p][3];
     }
     ans2+=ans1;
     ans1=0;
      for(int i=1;i<=n-2;i++)
    for(int j=i+1;j<=n-1;j++)
    for(int p=i+2;p<=n-2;p++){
     	ans1+=s[i][2]*s[j][3]*s[p][1];
     }
     ans2+=ans1;
     ans1=0;
      for(int i=1;i<=n-2;i++)
    for(int j=i+1;j<=n-1;j++)
    for(int p=i+2;p<=n;p++){
     	ans1+=s[i][3]*s[j][2]*s[p][1];
     }
     ans2+=ans1;
     ans1=0;
      for(int i=1;i<=n-2;i++)
    for(int j=i+1;j<=n-1;j++)
    for(int p=i+2;p<=n;p++){
     	ans1+=s[i][3]*s[j][1]*s[p][2];
     }
     ans2+=ans1;
     ans+=ans2;
     cout<<ans;
   }
}
	return 0;
}
