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
vi adj[100006];
int vis[100006];
int par[100006];
int k;
vi v;

//Functions
bool dfs(int s, int p){
    vis[s]=1;
    par[s]=p;
    for(int c: adj[s]){
        if(c==s){
            continue;
        }

        if(vis[c]==0){
            if(dfs(c,s)==true){
                return true;
            }
        }
        else{
            if(c!=p){
                int source=c;
                int dest=s;
                v.pb(source);

                while(par[dest]!=source){
                    v.pb(dest);
                    dest=par[dest];
                }
                v.pb(dest);
                v.pb(source);
                return true;
            }
        }
    }
    return false;
}


void solve(){
    int n,m;cin>>n>>m;

    memset(vis,0,sizeof(vis));

    sidha(i,0,m){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    // sidha(i,1,n+1){
    //     cout<<i<<"->";
    //     for(int c: adj[i]){
    //         cout<<c<<",";
    //     }
    //     cout<<endl;
    // }

    bool ans=true;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            if(dfs(i,-1)){
                
                cout<<v.size()<<endl;
                sidha(i,0,v.size()){
                    cout<<v[i]<<" ";
                }
                ans = false;
                break;
            }
        }
    }
    
    // sidha(i,1,n+1){
    //     cout<<par[i]<<" ";
    // }
    if(ans==true){
        cout<<"IMPOSSIBLE"<<endl;
    }
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
