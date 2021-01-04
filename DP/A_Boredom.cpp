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
#define mod 10000007
#define MAX INT_MAX
#define MIN INT_MIN
#define pb push_back
#define po pop_back
#define all(c) c.begin(),c.end()
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


//Driver Function
int main() {
    io;
    int n;cin>>n;
    int arr[n];
    map<int,ll> m;
    sidha(i,0,n){
        cin>>arr[i];
        m[arr[i]]++;
    }
    ll dp[(int)(1e+5)+10]={0};
    dp[0]=0;dp[1]=m[1];
    sidha(i,2,(int)(1e+5)+1){
        dp[i]=max(dp[i-1],dp[i-2]+m[i]*i);
    }
    cout<<dp[(int)1e+5]<<endl;
    return 0;
}