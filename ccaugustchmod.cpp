#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstdio>
#include<stack>
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end()) //set/map
#define cpresent(c,x) (find(all(c),x) != (c).end()) //for vector
using namespace std;
int RaiseToPower(int x, int y,int M) {
	if (y == 0)
		return 1 % M;
	int result = RaiseToPower(x, y >> 1,M);
	result = ((long long) result * (long long) result) % M;
	if (y & 1)
		result = ((long long) result * (long long) x) % M;
	return result;
}
int main()
{
	int n,i,j,b,l,r,mod,ians,count,ans,t;
	vector< int>a;
	vector<int>v[101];
	vector<int>prime(101);
	vector<int>cp[25];
	vector<int>fp;
	scanf("%d",&n);
	a.resize(n+1);
	for(i=0;i<101;i++)
	{
		v[i].resize(101);
	}
	for(i=0;i<25;i++)
		cp[i].resize(n+1);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	prime[0]=1;prime[1]=1;
	v[1][1]=1;
	for(i=2;i<101;i++)
		if(prime[i]==0)
		{
			fp.pb(i);
			v[i][i]=1;
			for(j=2*i;j<101;j+=i)
			{
				prime[j]=1;
				b=i;
				count=0;
				while(j%b==0)
				{
					count++;
					b*=i;
				}
				v[j][i]=count;
			}
		}
	
	/*for(j=2;j<101;j++)
	{
		cout<<j<<"\n";
		for(i=2;i<101;i++)
			cout<<i<<" "<<v[j][i]<<" ";
	}
	*/
	for(j=1;j<=n;j++)
		for(i=0;i<25;i++)
			cp[i][j]=cp[i][j-1]+v[a[j]][fp[i]];
	
	/*tr(fp,i)
		cout<<*i<<" ";
	cout<<"\n";
	for(i=0;i<25;i++)
	{
		for(j=1;j<=n;j++)
			cout<<cp[i][j]<<" ";
		cout<<"\n";
	}*/
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&l,&r,&mod);
		ans=1;
		for(i=0;i<25;i++)
		{
			ians=cp[i][r]-cp[i][l-1];
			ans=((long long) ans * (long long) RaiseToPower(fp[i],ians,mod)) %mod;
		}
		
		printf("%d\n",ans);
		
	}
	return 0;
}
