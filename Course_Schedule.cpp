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
int inde[1000006];
int k;
vector<int> v;
//Functions
void kahn(int n){
    queue<int> q;
    
    for(int i=1;i<=n;i++){
        if(inde[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int c=q.front();
        v.pb(c);

        for(int node:adj[c]){
            inde[node]--;
            if(inde[node]==0){
                q.push(node);
            }
        }
        q.pop();
    }
}

void solve()
{
    int n,m;cin>>n>>m;
    memset(inde,0,sizeof(inde));
    
    sidha(i,0,m){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        inde[b]++;
    }

    // for(int i=1;i<=n;i++){
    //     cout<<inde[i]<<" ";
    // }
    kahn(n);
    //cout<<endl;
   // cout<<v.size();
    if(v.size()!=n){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        for(int i=0;i<=n-1;i++){
            cout<<v[i]<<" ";
        }
    }
}

//Driver Function
int main()
{
    io;
   /// w(t)
   // {
        solve();
  //  }
    return 0;
}
