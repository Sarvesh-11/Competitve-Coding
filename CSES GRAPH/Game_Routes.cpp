/*
 * Author: runtime_terr0r
*/

#include <bits/stdc++.h>
using namespace std;
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define ll long long int
#define sidha(i, a, b) for (int i = a; i < b; i++)
#define set_built(x) __builtin_popcountll(x)
#define zero_built(x) __bultin_ctzll(x)
#define pairi pair<int, int>
#define vi vector<int>
#define mod 1000000007
#define MAX INT_MAX
#define MIN INT_MIN
#define pb push_back
#define po pop_back
#define all(c) c.begin(), c.end()
#define io                        \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

//Global Variable
//map<int,int> m;
vi adj[1000006];
int vis[1000006];
int par[1000006];
int inde[1000006];
int k;
int n,m;
vi t;

//Functions
void kahn(){
    queue<int> q;
    
    for(int i=1;i<=n;i++){
        if(inde[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int c=q.front();

        q.pop();
        t.pb(c);

        for(int ch : adj[c]){
            inde[ch]--;
            if(inde[ch]==0){
                q.push(ch);
            }
        }
    }
}

void solve()
{
    cin>>n>>m;

    memset(inde,0,sizeof(inde));

    sidha(i,0,m){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        inde[b]++;
    }

    kahn();

    ll dp[n+1]={0};
    dp[n]=1;

    for(int i=t.size()-1;i>=0;i--){
        for(int j=0;j<adj[t[i]].size();j++){
            dp[t[i]]+=dp[adj[t[i]][j]];
            dp[t[i]]%=mod;
        }
    }

    // sidha(i,1,n+1){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    cout<<dp[1]<<endl;

}

//Driver Function
int main()
{
    io;
    // w(t)
    // {
       solve();
    // }
    return 0;
}
