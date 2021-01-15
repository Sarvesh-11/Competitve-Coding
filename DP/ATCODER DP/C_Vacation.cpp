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
	ll n;cin>>n;
    ll arr[n][3];
    sidha(i,0,n){
        sidha(j,0,3){
            cin>>arr[i][j];
        }
    }
    ll dp[n][3];
    dp[0][0]=arr[0][0];
    dp[0][1]=arr[0][1];
    dp[0][2]=arr[0][2];
    sidha(i,1,n){
        dp[i][0]=arr[i][0]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=arr[i][1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=arr[i][2]+max(dp[i-1][0],dp[i-1][1]);
    }
    cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
	return 0;
}