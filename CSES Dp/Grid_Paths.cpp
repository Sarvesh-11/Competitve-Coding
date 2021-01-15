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
    char arr[n][n];
    ll dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    sidha(i,0,n){
        sidha(j,0,n){
            cin>>arr[i][j];
            if(arr[i][j]=='*'){
                dp[i+1][j+1]=-1;
            }
        }
    }
    // sidha(i,0,n){
    //     sidha(j,0,n){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if(dp[1][1]==-1){
        cout<<"0"<<endl;
        return 0;
    }

    for(int i=1;i<=n;i++){
        //cout<<arr[i-1][1]<<" ";
        if(arr[i-1][0]!='*')dp[i][1]=1;
        else break;
    }
    for(int i=1;i<=n;i++){
        if(arr[0][i-1]!='*')dp[1][i]=1;
        else break;
    }

    sidha(i,2,n+1){
        sidha(j,2,n+1){
            if(dp[i][j]==-1){
                continue;
            }
            
            if(dp[i-1][j]>0) 
                dp[i][j]=(dp[i][j]+dp[i-1][j]+mod)%mod;

            if(dp[i][j-1]>0) 
                dp[i][j]=(dp[i][j]+dp[i][j-1]+mod)%mod;
        }
    }
    // sidha(i,1,n+1){
    //     sidha(j,1,n+1){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if(dp[n][n]>=0){
        cout<<dp[n][n]<<endl;
    }
    else{
        cout<<0<<endl;
    }

}