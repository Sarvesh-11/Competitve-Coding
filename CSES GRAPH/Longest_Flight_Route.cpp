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
vi adj[1000066];
int vis[1000066];
int dis[1000006];
int par[1000005];
int inde[1000005];
int n,m;
vi top;

//Functions
void kahn(){
    queue<int> q;
    par[1]=0;
    dis[1]=0;
    sidha(i,1,n+1){
        if(inde[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int c=q.front();
        top.pb(c);
        q.pop();
        for(int ch: adj[c]){
            inde[ch]--;
            if(inde[ch]==0){
                q.push(ch);
            }
        }
    }
}

void solve()
{
    cin>>n>>m;
    memset(inde,0,sizeof(inde));
    sidha(i,0,m){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        inde[b]++;
    }

    for (int i = 1; i <= n; i++){
        dis[i] = MIN;
    }
    kahn();
    // for(auto x: top){
    //     cout<<x<<" "; 
    // }
    // cout<<endl;

    for (auto x : top)
    {
        for (auto y : adj[x])
        {
            if (dis[x] + 1 > dis[y])
            {
                dis[y] = dis[x] + 1;
                par[y] = x;
            }
        }
    }

    if(dis[n]==MIN){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        int y=n;
        vi path;

        while(y!=0){
            path.pb(y);
            y=par[y];
        }
       // path.pb(y);
        reverse(all(path));

        if(path[0]!=1){
            cout<<"IMPOSSIBLE"<<endl;
            return ;
        }

        cout<<path.size()<<endl;
        for(auto x: path){
            cout<<x<<" ";
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