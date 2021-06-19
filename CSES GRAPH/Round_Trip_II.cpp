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
int st=-1,e=-1;

//Functions
bool dfs(int s){
    vis[s]=1;

    for(int c: adj[s]){
        if(vis[c]==0){
            par[c]=s;
            if(dfs(c)==true)  return true;
        }
        else if(vis[c]==1){
            st=c;
            e=s;
            return true;
        }
    }

    vis[s]=2;

    return false;
}
void solve()
{
    int n,m;cin>>n>>m;
   
   
    memset(vis,0,sizeof(vis));
    sidha(i,0,m){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
    }

    for(int i=1;i<=n;i++){
        //cout<<an<<" ";
        if(vis[i]==0 and dfs(i))
            break;
       // cout<<an<<" ";
    }
    if(st!=-1){
        vi pa;

        pa.pb(st);

        for (int v = e; v != st; v = par[v])
            pa.push_back(v);
        pa.push_back(st);

        reverse(all(pa));
        cout<<pa.size()<<endl;
        sidha(i,0,pa.size()){
            cout<<pa[i]<<" ";
        }
        
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}

//Driver Function
int main()
{
    io;
    
        solve();

    return 0;
}
