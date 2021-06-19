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
vector<pair<ll,ll>> adj1[1000006],adj2[1000005];
int vis[100006];
ll dis1[1000005],dis2[1000000];
int k;
int n,m;

//Functions
void dik(){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;

    dis1[1]=0;
    for(int i=2;i<=n;i++){
        dis1[i]=LLONG_MAX-1000;
    }
    q.push({0,1});

    while(!q.empty()){
        ll cc=q.top().second;
        ll cd=q.top().first;

        q.pop();

        if (dis1[cc] < cd)
        {
            continue;
        }

        for(auto ed : adj1[cc]){
            if(dis1[ed.first]>cd+ed.second){
                dis1[ed.first]=cd+ed.second;
                q.push({dis1[ed.first],ed.first});
            }
        }
    }
}

void dik1(){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;

    dis2[n] = 0;
    for (int i = 1; i < n; i++)
    {
        dis2[i] = LLONG_MAX-1000;
    }
    q.push({0, n});

    while (!q.empty())
    {
        ll cc = q.top().second;
        ll cd = q.top().first;
        q.pop();
        if(dis2[cc]<cd){
            continue;
        }

        for (auto ed : adj2[cc])
        {
            if (dis2[ed.first] > cd + ed.second)
            {
                dis2[ed.first] = cd + ed.second;
                q.push({dis2[ed.first], ed.first});
            }
        }
    }
}

void solve()
{
    cin>>n>>m;

    vector<vector<ll>> e(m);
    sidha(i,0,m){
        ll a,b,c;cin>>a>>b>>c;

        e[i].pb(a);
        e[i].pb(b);
        e[i].pb(c);
        adj1[a].pb({b,c});
        adj2[b].pb({a,c});
    }

    // sidha(i,0,m){
    //     cout<<e[i][0]<<" "<<e[i][1]<<" "<<e[i][2]<<endl;
    // }

    // cout << 1 << endl;
    dik();

    // sidha(i,1,n+1){
    //     cout<<dis1[i]<<" ";
    // }
    // cout<<endl;
    // cout << 1 << endl;
    dik1();

    // sidha(i, 1, n + 1)
    // {
    //     cout << dis2[i] << " ";
    // }
    // cout << endl;
    // cout << 1 << endl;

    ll ans = LLONG_MAX-1000;
    for (int i=0;i<e.size();i++)
    {
        ans = min(ans, dis1[e[i][0]] + dis2[e[i][1]] + e[i][2] / 2);
    }
    cout << ans << endl;
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
