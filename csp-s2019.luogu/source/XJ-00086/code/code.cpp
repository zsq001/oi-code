 #include<bits/stdc++.h>
 using namespace std;
 long long int m=10,nn,a[4]={0,1,11,10},kk,p,q;
 int main()
 {
 	long long n,k;
 	freopen("code.in","r",stdin);
 	freopen("code.out","w",stdout);
    cin>>n>>k;
    nn=n;
    kk=k;
	while(n>2)
	{
		
		
		
			if(k>=pow(2,n-1)-1) 
			{
				k=pow(2,n-1)-k+pow(2,n-1)-1;
				m+=1;
				m*=10;
			} 
			else if(k<pow(2,n-1))
			{
			
				m*=10;
			}
			
			
	
		n--;
	}
	if(nn!=2&&kk>=pow(2,nn-1))	m=m*10+a[k];
	else if(nn!=2&&kk<pow(2,nn-1)) m=m*10+a[k];
	else m=m*10+a[k];
	if(kk>=pow(2,nn-1)){
	p=pow(10,nn);
	cout<<m%p;
	
	}
	else
	{
	  for(int i=nn;i>=1;i--)
	{
		p=pow(10,i);
		q=pow(10,i-1);
		if(m%p==m%q)cout<<"0";
		else cout<<"1";
	}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 }
