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
vi adj[1000006],tr[1000006];
int vis[1000006];
int k;
vi order;
vi scc;

//Functions
void dfs(int s){
    vis[s]=1;

    for(int c: adj[s]){
        if(vis[c]==0){
            dfs(c);
        }
    }
    order.pb(s);
}

void dfs1(int s){
    vis[s]=1;

    for(int c: tr[s]){
        if(vis[c]==0){
            dfs1(c);
        }
    }
    scc.pb(s);
}

void solve()
{
    int n,m;cin>>n>>m;

    sidha(i,0,m){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        tr[b].pb(a);
    }

    sidha(i,1,n+1){
        if(vis[i]==0){
            dfs(i);
        }
    }

    memset(vis,0,sizeof(vis));
    int par[n+1];
    int c=1;
    for(int i=order.size()-1;i>=0;i--){
        if(vis[order[i]]==0){
            scc.clear();
            dfs1(order[i]);

            for(auto it:scc){
                par[it]=c;
            }
            c++;
        }
    }
    cout<<c-1<<endl;

    sidha(i,1,n+1){
        cout<<par[i]<<" ";
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
