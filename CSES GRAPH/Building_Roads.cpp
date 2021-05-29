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
int k;

//Functions
void dfs(int s){
    vis[s]=1;

    for(int c: adj[s]){
        if(vis[c]==0){
            dfs(c);
        }
    }
}

void solve(){
    int n,m;cin>>n>>m;

    memset(vis,0,sizeof(vis));

    sidha(i,0,m){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int c=0;
    vi v;
    sidha(i,1,n+1){
        if(vis[i]==0){
            v.pb(i);
            c++;
            dfs(i);
        }
    }
    cout<<c-1<<endl;
    sidha(i,1,v.size()){
        cout<<v[i-1]<<" "<<v[i]<<endl;
    }

}

//Driver Function
int main()
{
    io;
        solve();
    return 0;
}
