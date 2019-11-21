 #include<bits/stdc++.h>
 using namespace std;
 long long int a[5010][5010];
 int main()
{
	long long int n,type,cnt=1,ans=0;
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	cin>>n>>type;
	for(int i=1;i<=n;i++)
	{
		cin>>a[cnt][1];
		cnt++;
	}
	
	for(int i=1;i<=n;i++)
	{
		
		cnt=i+1;
		for(int j=1;j<=n;j++)
		{
			if(a[j][i]>a[j+1][i])
			 {
			 	a[cnt][j]=a[j][i]+a[j+1][i];
			 	j++;
			 }
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans+=pow(a[n][i],2);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

 
