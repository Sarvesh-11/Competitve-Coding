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
int k;
vi v;

//Functions
void solve()
{
    ll n, m,q;
    cin >> n >> m>>q;

    ll arr[n+1][n+1];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j ){
                arr[i][j]=0;
                continue;
            }
            arr[i][j]=LLONG_MAX;
        }
    }

    sidha(i,0,m){
        ll a,b,c;cin>>a>>b>>c;
        arr[a][b]=min(arr[a][b],c);
        arr[b][a]=min(arr[b][a],c);
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if (arr[i][j] > (arr[i][k] + arr[k][j]) && (arr[k][j] != LLONG_MAX && arr[i][k] != LLONG_MAX)){
                        arr[i][j]=arr[i][k]+arr[k][j];
                }
            }
        }
    }

    while(q--){
        ll a,b;cin>>a>>b;
        if(arr[a][b]==LLONG_MAX){
            cout<<"-1"<<endl;
        }
        else{
            cout<<arr[a][b]<<endl;
        }
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
