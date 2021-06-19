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
vi adj[100006];
int vis[100006];
int par[100005];
int siz[1000005];
int k;

//Functions
int find(int p){
    if(p==par[p])   return p;

    return par[p] = find(par[p]);
}
void solve()
{
    int n,m;cin>>n>>m;

    for(int i=1;i<=n;i++){
        par[i]=i;
        siz[i]=1;
    }
    int s=1,com=n;

    sidha(i,0,m){
        int a,b;cin>>a>>b;
        int pa=find(a);
        int pc=find(b);

        if(pa!=pc){
            com--;
            if(siz[pa]>siz[pc]){
                par[pc]=pa;
                siz[pa]+=siz[pc];
                siz[pc]=0;
                s=max(s,siz[pa]);
            }
            else{
                par[pa] = pc;
                siz[pc] += siz[pa];
                siz[pa] = 0;
                s = max(s, siz[pc]);
            }
        }

        cout<<com<<" "<<s<<endl;
    }
    // sidha(i,1,n+1){
    //     cout<<par[i]<<" ";
    // }
    // cout<<endl;

    // sidha(i,1,n+1){
    //     cout<<size[i]<<" ";
    // }
}

//Driver Function
int main()
{
    io;
    // w(t)
    // {
        solve();
    //}
    return 0;
}
