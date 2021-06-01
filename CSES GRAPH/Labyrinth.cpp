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
char adj[1000][1000];
int vis[1000][1000];
int k;
int par[1000][1000];
int n,m;

vector<char> v;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
string st="DURL";
//Functions
bool valid(int x,int y){

    if(x<0 or x>=n or y<0 or y>=m){
        return false;
    }
    return true;
}

void bfs(pairi s){
    vis[s.first][s.second]=1;
    queue<pairi> q;

    q.push(s);

    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            if(vis[cx+dx[i]][cy+dy[i]]==1)continue;
            if(valid(cx+dx[i],cy+dy[i])==false)continue;
            if(adj[cx+dx[i]][cy+dy[i]]=='#')continue;
            vis[cx+dx[i]][cy+dy[i]]=1;
            par[cx + dx[i]][cy + dy[i]]=i;
            q.push({cx + dx[i],cy + dy[i]});
        }
    }
}

void solve()
{
    cin>>n>>m;

    pairi s,e;
    memset(vis,0,sizeof(vis));
    sidha(i,0,n){
        sidha(j,0,m){
            cin>>adj[i][j];

            if(adj[i][j]=='A'){
                s={i,j};
            }
            if(adj[i][j]=='B'){
                e={i,j};
            }
        }
    }

    bfs(s);

    // sidha(i,0,n){
    //     sidha(j,0,m){
    //         cout<<par[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    if(vis[e.first][e.second]==0){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        string ans;
        while(e!=s){
            int p=par[e.first][e.second];
            ans+=st[p];
            e.first-=dx[p];e.second-=dy[p];

        }
        cout<<ans.size()<<endl;
        reverse(all(ans));
        cout<<ans<<endl;
    }
}

//Driver Function
int main()
{
    io;
  //  w(t)
   // {
        solve();
   // }
    return 0;
}
