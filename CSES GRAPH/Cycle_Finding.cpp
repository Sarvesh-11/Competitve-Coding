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

struct edge{
    ll a,b,c;
};
//Functions
void solve()
{
    ll n,m;cin>>n>>m;

    edge e[m+1];
    vector<ll> v(n+1,10000000000000000);
    vector<ll> p(n+1,-1);

    for(int i=0;i<m;i++){
        cin >> e[i].a >> e[i].b >> e[i].c;
    }

    ll x;
    v[1]=0;

    for(int i=0;i<n+1;i++){
        x=-1;
        for(int j=0;j<m;j++){
                if (v[e[j].b] > v[e[j].a] + e[j].c){
                    v[e[j].b]=v[e[j].a]+e[j].c;
                    p[e[j].b]=e[j].a;
                    x=e[j].b;
                }

        }
    } 

    // sidha(i,0,n){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    // sidha(i, 0, n){
    //     cout << p[i] << " "; 
    // }
    // cout<< endl;


    if(x==-1){
        cout<<"NO"<<endl;
    }
    else{
        int y=x;
        for(int i=0;i<n;i++){
            y=p[y];
        }
        vi path;
        int a=y;
        for(int a=y;;a=p[a]){
            path.pb(a);
            if(a==y and path.size()>1){
                path.pb(a);
                break;
            }
        }

        reverse(all(path));

        cout<<"YES"<<endl;
        for(int i=1;i<path.size();i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
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
