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
#define pairi pair<ll, ll>
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
vector<pairi>  adj[1000006];
int vis[1000006];
vector<ll> dis(1000006,LLONG_MAX);
int k;
vi v;

//Functions
void bfs(){
    priority_queue<pairi,vector<pairi>, greater<pairi>> pq;
    dis[1]=0;

    pq.push({0,1});

    while(!pq.empty()){
        ll c=pq.top().second;
        ll cd=pq.top().first;
        pq.pop();

        if(dis[c]<cd){
            continue;
        }
        for(pairi ed : adj[c]){
            if(cd+ed.second<dis[ed.first]){
                dis[ed.first]=cd+ed.second;
                pq.push({dis[ed.first],ed.first});
            }
        }
    }
    
}

void solve()
{
    ll n,m;cin>>n>>m;
    
    sidha(i,0,m){
        ll a,b,c;cin>>a>>b>>c;

        adj[a].pb({b,c});
    }

    // for(int i=1;i<=n;i++){
    //     cout<<i<<"->";
    //     for(int j=0;j<adj[i].size();j++){
    //         cout<<adj[i][j].first<<" "<<adj[i][j].second<<"->";
    //     }
    //     cout<<endl;
    // }

    bfs();

    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
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
