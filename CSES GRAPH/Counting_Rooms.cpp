/*
 * Author: runtime_terr0r
*/

#include<bits/stdc++.h>
using namespace std;
#define w(x) int x; cin>>x; while(x--)
#define ll long long int
#define sidha(i,a,b) for(int i=a;i<b;i++)
#define set_built(x) __builtin_popcountll(x)
#define zero_built(x) __bultin_ctzll(x)
#define pairi pair<int,int>
#define vi vector<int>
#define mod 1000000007
#define MAX INT_MAX
#define MIN INT_MIN
#define pb push_back
#define po pop_back
#define all(c) c.begin(),c.end()
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//Global Variable
//map<int,int> m;
vi adj[100006];
int vis[1001][1001];
int k;
int n,m;
char arr[1001][1001];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
//Functions
bool isValid(int x,int y){
    if(x<0 || x>n || y<0 || y>m)    return false;

    if(vis[x][y]==1 or arr[x][y]!='.'){
        return false;
    }
    return true;
}

void dfs(int x,int y){
    vis[x][y]=1;

    for(int i=0;i<4;i++){
        if(isValid(x+dx[i],y+dy[i])){
            dfs(x+dx[i],y+dy[i]);
        }
    }
}



void solve(){
    cin>>n>>m;


    memset(vis,0,sizeof(vis));
    sidha(i,0,n){
        sidha(j,0,m){
            cin>>arr[i][j];
        }
    }

    int c=0;

    sidha(i,0,n){
        sidha(j,0,m){
            if(arr[i][j]=='.' and vis[i][j]==0){
                dfs(i,j);
                c++;
            }
        }
    }

    cout<<c<<endl;
}

//Driver Function
int main(){
	io;
	//w(t){
		solve();
	//}
	return 0;
}
