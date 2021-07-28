
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define vivi vector<vector<ll>>
#define itrv vector<ll>::iterator
#define itrs set<ll>::iterator

//...............loop section...........................................

#define fo(i,k,n) for(i=k;i<n;i++)
#define vl(i,v) for(i=v.begin();i<v.end();i++)
#define foR(i,k,n) for(i=k;i>n;i--)

//..............Scan and Print section...................................

#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(x) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define plg(x) printf("%lld ",x)
#define ps(x) printf("%s\n",x)

//..................................................................

#define F first
#define S second
#define sp(x,y) fixed<<setprecision(y)<<x
#define nl cout<<endl

//........Some commonly used values................................

#define mod 1000000007
#define PI 3.141592635

//.........Some commonly used function...........................

ll gcd(ll a, ll b){ return b==0?a:gcd(b,a%b);}
ll lcm(ll a, ll b){ return (a*b)/gcd(a,b);}
vivi spT(100,vi(100,0));

void SparseTable(vi a){                       //Building sparse table it takes O(nlog(n)) to build
	
	int n=a.size();
	for(int i=0;i<n;i++)
		spT[i][0]=a[i];

	for(int i=1;(1<<i)<=n;i++){
		for(int j=0;j+(1<<i)<=n;j++){
			spT[j][i]=max(spT[j][i-1], spT[j+1<<(i-1)][i-1]);

		}
	}
}

ll spTquery(int l,int r){
	int k=log2(r-l+1);
	return max(spT[l][k], spT[r-(1<<k)+1][k]);
}

//................................................................

void solve(vi a, int n){
	SparseTable(a);
	pl(spTquery(3,5));
}

int main(){
	int t=1;
	//si(t);
	while(t--){
		int n;
		int i;
		si(n);
		vi a(n,0);
		fo(i,0,n) sl(a[i]);
		solve(a,n);
	}
	return 0;
}


