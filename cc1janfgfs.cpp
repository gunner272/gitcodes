#include<iostream>
#include<vector>
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
#define con 100008
using namespace std;
struct elem
{
	int s,f,p;
};
vector<elem>v[con];
bool cmpo(elem a,elem b)
{
	return a.p<b.p;
}
bool cmpf(elem a,elem b)
{
	return a.f<b.f;
}
int func(int idx)
{
	if(v[idx].size()==0)
		return 0;
	int i=1,ans=1,f=v[idx][0].f;
	while(i<v[idx].size())
	{
		if(f<=v[idx][i].s)
		{
			ans++;
			f=v[idx][i].f;
		}
		i++;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int t,n,k,j,l,i,s,f,p,ans;
	cin>>t;
	vector<elem>in(con);
	while(t--)
	{
		ans=0;
		cin>>n;
		cin>>l;
		for(i=0;i<n;i++)
		{
			cin>>s;
			cin>>f;
			cin>>p;
			in[i].s=s;in[i].f=f;in[i].p=p;
		}
		if(n>0)
		{
			sort(in.begin(),in.begin()+n,cmpo);
			for(i=0;i<con;i++)
				v[i].clear();
			v[0].pb(in[0]);
			for(i=1,j=0;i<n;i++)
			{
				//pri(in[i].p);
				//cout<<"a";
				//pri(in[i-1].p);
				if(in[i].p!=in[i-1].p)
					j++;
				v[j].pb(in[i]);
			}
			for(k=0;k<=j;k++)
				sort(all(v[k]),cmpf);
			for(k=0;k<=j;k++)
				ans+=func(k);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
