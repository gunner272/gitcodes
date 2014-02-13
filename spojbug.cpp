#include<iostream>
include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cstring>
#include<cstdio>
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end()) //set/map
#define cpresent(c,x) (find(all(c),x) != (c).end()) //for vector
#define rp(i,n) for((i)=0;(i)<(n);(i)++)
#define each(i,a,n) for((i)=(a);(i)<(n);(i)++)
#define sci(i) scanf("%d",&(i));
#define scl(i) scanf("%lld",&(i));
#define pri(i) printf("%d\n",(i));
#define prl(i) printf("%lld\n",(i));
#define psi(i) printf("%d ",(i));
#define psl(i) printf("%lld ",(i));
#define ll long long int
using namespace std;
vector<int>v[2008];
vector<int>col(2008);
bool func(int index)
{
	queue<int>q;
	q.push(index);
	col[index]=1;
	bool top=0;int u,j;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(j=0;j<v[u].size();j++)
			if(col[v[u][j]]==-1)
			{
				col[v[u][j]]=1-col[u];
				q.push(v[u][j]);
			}
			else
			if(col[v[u][j]]==col[u])
				top=1;
	}
	return top;
}


int main()
{
	
	int n,k,j,t,i,m,u,vi;
	
	sci(t);k=1;
	bool top;
	while(k<=t)
	{
		sci(n);sci(m);
		for(i=1;i<=n;i++)
			v[i].clear();
		fill(all(col),-1);
		for(i=0;i<m;i++)
		{
			sci(u);
			sci(vi);
			v[u].pb(vi);
			v[vi].pb(u);
		}
		top=0;
		for(i=1;i<=n;i++)
			if(col[i]==-1)
				top+=func(i);
		if(top)
			printf("Scenario #%d:\nSuspicious bugs found!\n",k);
		else
			printf("Scenario #%d:\nNo suspicious bugs found!\n",k);
		k++;
	}
	return 0;
}
