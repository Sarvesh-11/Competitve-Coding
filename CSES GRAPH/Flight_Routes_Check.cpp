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
vi tr[1000006];
int vis[100006];
int k;
vi v,scc;
//Functions
void dfs(int s){
    vis[s]=1;

    for(int c: adj[s]){
        if(vis[c]==0){
            dfs(c);
        }
    }
    v.pb(s);
}
void dfs1(int s)
{
    vis[s] = 1;

    for (int c : tr[s])
    {
        if (vis[c] == 0)
        {
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

    // sidha(i,0,n){
    //     cout<<v[i]<<" ";
    // }

    // cout<<endl;
    memset(vis,0,sizeof(vis));

    bool an=true;int c=0,x,y;


    for(int i=1;i<=v.size();i++){
        if(vis[v[n-i]]==0){
            scc.clear();
            dfs1(v[n-i]);
            
            if(c==0){
                x=scc[0];
            }
            if(c==1){
                y=scc[0];
            }
            c++;
        }

        if(c==2){
            bool an=false;
            cout<<"NO"<<endl;
            cout<<y<<" "<<x<<endl;
            break;
        }
        // sidha(i,0,scc.size()){
        //     cout<<scc[i]<<" ";
        // }
        // cout<<endl;
    }

    // sidha(i, 0, scc.size())
    // {
    //     cout << scc[i] << " ";
    // }
    // cout << endl;

    if(c==1){
        cout<<"YES"<<endl;
    }
}

//Driver Function
int main()
{
    io;
    //w(t)
    //{
        solve();
   // }
    return 0;
}
