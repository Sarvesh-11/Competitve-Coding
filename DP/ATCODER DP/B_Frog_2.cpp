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
    ll n,k;cin>>n>>k;
    ll arr[n];ll dp[n];
    sidha(i,0,n){
        cin>>arr[i];
        dp[i]=INT_MAX;
    }
    dp[0]=0;dp[1]=abs(arr[1]-arr[0]);
    for(int i=2;i<n;i++){
        for(int j=1;j<=k;j++){
            if(j<=i){
                dp[i]=min(abs(arr[i]-arr[i-j])+dp[i-j],dp[i]);
            }
        }
    }
    // sidha(i,0,n){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    cout<<dp[n-1]<<endl;
	return 0;
}