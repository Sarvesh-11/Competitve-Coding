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
vector<pair<ll,pair<ll,ll>>> v;
int vis[1000006];
int par[1000006];
int k;

//Functions
int find(int a){
    if(a==par[a]){
        return a;
    }
    return par[a]=find(par[a]);
}

void join(int a,int b){
    par[b]=par[a];
}

void solve()
{
    ll n,m;cin>>n>>m;
    
    sidha(i,1,n+1){
        par[i]=i;
    }

    sidha(i,0,m){
        ll a,b,c;cin>>a>>b>>c;
        v.pb({c,{a,b}});
    }

    sort(v.begin(),v.end());

    ll s=0;
    for(int i=0;i<v.size();i++){
        int a=find(v[i].second.first);
        int b = find(v[i].second.second);
        int c = v[i].first;

        if(a==b){
            continue;
        }
        else{
            join(a,b);
            s+=c;
        }
    }

    int c=0;
    sidha(i,1,n+1){
        if(par[i]==i){
            c++;
        }
    }
    if(c>1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
        cout<<s<<endl;
    
}

//Driver Function
int main()
{
    io;
   // w(t)
    //{
        solve();
   // }
    return 0;
}
