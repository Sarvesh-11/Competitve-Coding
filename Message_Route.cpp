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
int dis[100006];
int k;

//Functions
void dfs(int s, int p,int d)
{
    vis[s] = 1;
    par[s] = p;
    dis[s]=d;

    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int cu=q.front();
        q.pop();

        for(int i=0;i<adj[cu].size();i++){
            if(vis[adj[cu][i]]==0){
                vis[adj[cu][i]]=1;
                dis[adj[cu][i]]=dis[cu]+1;
                par[adj[cu][i]]=cu;
                q.push(adj[cu][i]);
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    memset(vis, 0, sizeof(vis));

    sidha(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1,-1,0);    

    if (vis[n]==0)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout<<dis[n]+1<<endl;
        int x=n;
        vi v;

        // sidha(i,1,n+1){
        //     cout<<par[i]<<endl;
        // }
        while(par[x]!=-1){
            v.pb(x);
            x=par[x];
        }
        v.pb(1);

        for(int i=v.size()-1;i>=0;i--){
            cout<<v[i]<<" ";
        }
    }
}

//Driver Function
int main()
{
    io;
    solve();
    return 0;
}
