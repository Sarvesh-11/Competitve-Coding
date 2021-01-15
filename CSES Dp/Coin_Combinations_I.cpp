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

//Functions


//Driver Function
int main(){
	io;
	ll n,x;cin>>n>>x;
    ll arr[n];
    sidha(i,0,n){
        cin>>arr[i];
        //cout<<arr[i]<<" ";
    }
    //cout<<endl;
    vector<ll> dp(x+1,0);
    dp[0]=1;
    
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(arr[j]<=i){
                (dp[i] += dp[i-arr[j]]) %= mod;
            }
        }
    }
    cout<<dp[x]<<endl;
	return 0;
}