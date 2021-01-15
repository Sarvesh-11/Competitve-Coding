// Author :- Sarvesh Chaudhary
#include<bits/stdc++.h>
using namespace std;
#define w(x) int x; cin>>x; while(x--)
#define ll long long int
#define sidha(i,a,b) for(int i=a;i<b;i++)
#define set_built(x) __builtin_popcountll(x)
#define zero_built(x) __bultin_ctzll(x)
#define pairi pair<int,int>
#define vi vector<int>
#define mod 1000000007
#define MAX INT_MAX
#define MIN INT_MIN
#define pb push_back
#define po pop_back
#define all(c) c.begin(),c.end()
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//Global Variable
map<int,int> m;
ll dp[104][100004];

//Functions
ll  knapsack(ll a[], ll b[], ll n, ll w){
    if(n==0||w==0){
        return 0;
    }
    if(dp[n][w]!=-1)
    return dp[n][w];
    ll ans;
    if(a[n-1]<=w){
       ans= max(knapsack(a,b,n-1,w-a[n-1])+b[n-1], knapsack(a,b,n-1,w));
    }
    else{
        ans=knapsack(a,b,n-1,w);
    }
    return dp[n][w]=ans;
}

//Driver Function
int main(){
	io;
	ll n,w;cin>>n>>w;
    ll weight[n+1];
    ll value[n+1];
    for(ll i=0;i<n;i++){
        cin>>weight[i];
        cin>>value[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<knapsack(weight,value,n,w)<<endl;
	return 0;
}