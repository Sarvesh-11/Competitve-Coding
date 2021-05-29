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
int col[100006];
int k;

//Functions
bool dfs(int s,int c)
{
    vis[s] = 1;
    col[s]=c;

    for (int ch : adj[s]){
        if (vis[ch] == 0){
            if(dfs(ch,c^1)==false){
                return false;
            } 
        }
        else if(col[ch]==col[s]){
            return false;
        }
    }
    return true;

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

    bool ans=true;
    sidha(i, 1, n + 1)
    {
        if (vis[i] == 0)
        {
            ans=dfs(i,0);
            if(ans==false){
                break;
            }
        }
    }

    if(!ans){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        sidha(i,1,n+1){
            cout<<col[i]+1<<" ";
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
