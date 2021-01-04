// Author :- Sarvesh Chaudhary
#include<bits/stdc++.h>
using namespace std;
#define w(x) int x; cin>>x; while(x--)
#define ll long long int
#define sidha(i,a,b) for(int i=a;i<b;i++)
#define set_built(x) __builtin_popcountll(x)
#define zero_built(x) __bultin_ctzll(x)
#define pairi pair<int,int>
#define vi vector<int>
#define mod 10000007
#define MAX INT_MAX
#define MIN INT_MIN
#define pb push_back
#define po pop_back
#define all(c) c.begin(),c.end()
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//Global Variable
map<int,int> m;

//Functions


//Driver Function
int main() {
    io;
    
    ll n;cin>>n;
    ll arr[n];
    ll x=0;
    sidha(i,0,n){
        ll a,b;cin>>a>>b;
        x-=a;
        arr[i]=a+a+b;
    }
    sort(arr,arr+n);
    ll c=0;
    ll j=n-1;
    while(x<=0){
        x+=arr[j];
        j--;
        c++;
    }
    cout<<c<<endl;
    return 0;
}