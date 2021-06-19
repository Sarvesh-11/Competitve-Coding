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

//Functions
vector<vector<int>> v;
ll dist[10005];
void solve()
{
    //start
    int n, m;
    cin >> n >> m;
    int flag = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, -c});
    }
    for (int i = 1; i <= n; i++)
        dist[i] = 10000000000000000;
    dist[1] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a = v[j][0];
            int b = v[j][1];
            int c = v[j][2];
            if (dist[a] != 10000000000000000)
                if (dist[a] + c < dist[b])
                {
                    dist[b] = dist[a] + c;
                }
        }
    }

    //   cout<<"Dist array is : ";
    //  for(int i = 1; i<=n; i++)
    //   cout<<dist[i]<<" ";
    // cout<<"\n";
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a = v[j][0];
            int b = v[j][1];
            int c = v[j][2];
            if (dist[a] != 10000000000000000)
            {
                if (dist[a] + c < dist[b])
                {
                    dist[b] = -10000000000000000;
                }
            }
        }
    }
    //   cout<<"Dist array after 2nd relax is : ";
    //  for(int i = 1; i<=n; i++)
    //   cout<<dist[i]<<" ";
    // cout<<"\n";

    if (dist[n] == -10000000000000000 || dist[1] == -10000000000000000)
        cout << -1 << endl;
    else
    {
        cout << -1 * dist[n] << endl;
        //cout<<dist[n]<<endl;
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