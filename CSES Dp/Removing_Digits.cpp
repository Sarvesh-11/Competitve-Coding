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
    vector<ll> dp(n+1,1e9);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(char c: to_string(i)){
            dp[i]=min(dp[i],dp[i-(c-'0')]+1);
        }
    }

    cout<<dp[n]<<endl;

	return 0;
}